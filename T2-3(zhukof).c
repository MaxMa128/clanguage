#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/wait.h>

int main(int argc, char ** argv)
{
	pid_t pid;
	int fd, semid, shmid;
	key_t key;
	int *shmaddr;
	struct sembuf P1 = {0, -1, 0};
	struct sembuf V1 = {0, -1, 0};
	struct sembuf P2 = {0, -1, 0};
	struct sembuf V2 = {0, -1, 0};
	
	if( argc < 2 )
	{
		printf("./a.out bin_file\n");
		return 1;
	}
	fd = creat("file",0644);
	if(fd < 0) { perror("creat"); return 2; }
	
	key = ftok("file",'k');
	if (key < 0) { perror("key"); return 3; }
	close(fd);
	
	shmid = shmget(key, sizeof(int)*2, IPC_CREAT | 0666);
	if (shmid < 0) { perror("shmget"); return 4; }
	
	semid = semget(key, 2, IPC_CREAT | 0666);
	if (semid < 0 ){ perror("semget"); return 5; }
	
	semctl(semid, 0, SETALL, 0);
	
	shmaddr = shmat(shmid, NULL, 0);
	if (shmaddr == (void*)-1) { perror("shmat"); return 6; }
	
	if ((pid = fork()) < 0){ perror("fork"); return 7;} 
	else if (pid == 0)
	{
		int ff, a[2], res, i;
		ff = open(argv[1],O_RDONLY);
		if (ff < 0) { perror("open"); return 8; }
		while( (read(ff, a, 2*sizeof(int)) == 2*sizeof(int))) // reaf 2 int from file
		{
			shmaddr[0] = a[0];//write to shared memory
			shmaddr[1] = a[1];
			semop(semid, &V1, 1);//now father is working
			semop(semid, &P2, 1);// son wait
			res = shmaddr[0];// son read answer
			printf("son %d\n",res); fflush(stdout);
		}
		close(ff);
		shmaddr[0] = INT_MIN; 
		semop(semid,&V1,1);
		return 0;
	}
	else
	{
		int res;
		while(1)
		{
			semop(semid, &P1, 1); // father is waiting
			if(shmaddr[0] == INT_MIN)	
				break;
			else
			{
				printf("father %d %d\n", shmaddr[0], shmaddr[1]);
				fflush(stdout);
				res = shmaddr[0]*shmaddr[1];
				shmaddr[0] = res;
			}
			semop(semid, &V2, 1);
		}
		wait(NULL);
		shmdt(shmaddr);
		shmctl(shmid, IPC_RMID, NULL);
		semctl(semid, 0, IPC_RMID, 0);
	}
	return 0;
}
