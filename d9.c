#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
        int fd[2], semid, cnt = 0, Cnt_Max, ff;
        key_t key;
        pid_t pid,pid2;
        struct sembuf P1 = {0, -1, 0};
        struct sembuf V1 = {0, 1, 0};
        struct sembuf P2 = {1, -1, 0};
        struct sembuf V2 = {1, 1, 0};
        struct sembuf P3 = {2, -1, 0};
        struct sembuf V3 = {2, 1, 0};

        scanf("%d", &Cnt_Max);
        ff=creat("file", 0666);
        if(ff < 0) { perror("creat");return 5;}

        key = ftok("file", 't');
        if (key<0) { perror ("key");return 1;}
        close(ff);

        semid = semget (key, 3, IPC_CREAT | 0666);// create 3 sem
         if (semid<0) { perror ("semget");return 2;}

        semctl(semid, 0, SETVAL, 0);
        semctl(semid, 1, SETVAL, 0);
        semctl(semid, 2, SETVAL,0);
       
       	if(pipe(fd) < 0) { perror ("pipe");return 3;}

        if ((pid = fork()) < 0) { perror("fork");return 4;}
        else if (pid>0)
	{
            if ((pid2=fork())<0) 
	    {
                perror("fork");
                return 4;
            }
	    else if(pid2==0)
	    {
                while(cnt<Cnt_Max)
		{
                	semop(semid, &P3, 1);
                        read(fd[0], &cnt, sizeof(int));
                    	if(cnt<=Cnt_Max)
			{
                	        printf("son2 %d\n", cnt++);
                       	 	fflush(stdout);
                        	write(fd[1],&cnt, sizeof(int));
                        	semop(semid, &V2, 1);
            		}
            	}
                close(fd[0]); close(fd[1]);
                return 0;
            }
	    else
	    {
            	write(fd[1], &cnt, sizeof(int));
                semop(semid, &V1, 1);
                while(cnt<Cnt_Max)
		{
                        semop(semid, &P2, 1);
                        read(fd[0], &cnt, sizeof(int));
                	if(cnt<=Cnt_Max)
			{
                        	printf("father %d\n", cnt++);
                        	fflush(stdout);
                        	write(fd[1],&cnt,sizeof(int));
                        	semop(semid, &V1,1);
                    	}
                }
                close(fd[0]); close(fd[1]);
                wait(NULL);
            }
        }
	else
	{
                while(cnt<Cnt_Max)
		{
                        semop(semid, &P1, 1);
                        read(fd[0], &cnt, sizeof(int));
                	if(cnt<=Cnt_Max)
			{
                        	printf("son1 %d\n", cnt++);
                        	fflush(stdout);
                       		write(fd[1],&cnt, sizeof(int));
                        	semop(semid, &V3, 1);
                    	}
                }
                close(fd[0]); close(fd[1]);
                return 0;

        }

        semctl(semid, 0, IPC_RMID, 0);
	semctl(semid, 1, IPC_RMID, 0);
	semctl(semid, 2, IPC_RMID, 0);
        return 0;

}
