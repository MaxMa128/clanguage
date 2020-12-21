#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
	int fd[2],semid,cnt = 0,Cnt_max, ff;
	key_t key;
	pid_t pid;
	struct sembuf p1 = {0,-1,0};
	struct sembuf v1 = {0,1,0};
	struct sembuf p2 = {1,-1,0};
	struct sembuf v2 = {1,1,0};

	scanf("%d",&Cnt_max);
	ff=creat("file",0666);
	if(ff<0) {perror("creat"); return 5;}

	key = ftok("file",'t');
	if(key < 0)  {perror("key");  return 1;}
	close(ff);

	semid = semget(key,2,IPC_CREAT | 0666); //create 2 semphore
	if(semid < 0)  {perror("semget"); return 2;}
	//semctl(semid,0,SETALL,0); //所有信号量sem.val = 0
	semctl(semid,0,SETVAL,0);//first sem.val1 = 0
	semctl(semid,1,SETVAL,0);//second sem.val2 = 0

	if(pipe(fd) < 0)  {perror("pipe"); return 3;}
	if( (pid=fork()) < 0) {perror("fork"); return 4;}
	else if(pid > 0)  //father
	{
        	write(fd[1],&cnt,sizeof(cnt));
		semop(semid,&v1,1);
		while(cnt < Cnt_max)
		{
           		semop(semid,&p2,1);
           		read(fd[0],&cnt,sizeof(int));
    			printf("father %d\n",cnt++);
           		fflush(stdout);
    			write(fd[1],&cnt,sizeof(int));
			semop(semid,&v1,1);
		}
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
	}
	else //son
	{
		while(cnt < Cnt_max)
		{
          		semop(semid,&p1,1);
			read(fd[0],&cnt,sizeof(int));
			printf("son %d\n",cnt++);
			fflush(stdout);
			write(fd[1],&cnt,sizeof(int));
			semop(semid,&v2,1);
		}
 		close(fd[0]);
       		close(fd[1]);
 		return 0;
	}
   	semctl(semid,0,IPC_RMID,0);
   	semctl(semid,1,IPC_RMID,0);
   	return 0;
}
