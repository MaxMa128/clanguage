#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<unistd.h>
#include<wait.h>

int main()
{
	key_t key;
	int i,j,n;
	int shmid,semid;
	struct sembuf V1={0,1,0};
	struct sembuf P1={0,-1,0};
	struct sembuf P2={1,-1,0};
	struct sembuf V2={1,1,0};
	struct sembuf V3={2,1,0};
	struct sembuf P3={2,-1,0};
	long *shmaddr,file;

	scanf("%d",&n);

	file = creat("file",0666);
	if(file < 0){perror("creat"); return 1;}

	key = ftok("file",'f');
	if(key < 0){perror("key"); return 2;}

	shmid = shmget(key, n*sizeof(long), IPC_CREAT | 0666);
	if(shmid < 0){perror("shmget"); return 3;}

	semid = semget(key, 2, IPC_CREAT | 0666);
	if(semid < 0){perror("semget"); return 4;}

	semctl(semid, 0, SETVAL, 0);
	semctl(semid, 1, SETVAL, 0);
	semctl(semid, 2, SETVAL, 0);

	shmaddr = shmat(shmid,NULL,0);
        if(shmaddr == (void*)-1){perror("shmat"); return 6;}

	pid_t pid1,pid2;
	if((pid1 = fork()) < 0){perror("fork"); return 5;}
	else if(pid1 == 0)//s1
	{
		i = 2;
		while(i <= n)
		{
			semop(semid, &P1, 1);
			shmaddr[i] = shmaddr[i-1] + shmaddr[i-2];
			i+=2;
			semop(semid ,&V2, 1);
		}
		semop(semid, &V3, 1);
		return 0;
	}
	else
	{
		if((pid2 = fork()) < 0){perror("fork"); return 5;}
		else if(pid2 == 0)//s2
		{
			i = 3;
			while(i <= n)
                	{
                       		 semop(semid, &P2, 1);
                	         shmaddr[i] = shmaddr[i-1] + shmaddr[i-2];
                     		 i+=2;
                     		 semop(semid ,&V1, 1);
                	}
                	semop(semid, &V3, 1);
                	return 0;
		}
		else//f
		{
			shmaddr[0] = 0;
		        shmaddr[1] = 1;
			semop(semid, &V1, 1);
			wait(NULL);
			wait(NULL);
			semop(semid, &P3, 1);
			for(j = 0;j < n;j++)
				printf("%ld ",shmaddr[j]);
		}
	}
	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);
	semctl(semid, 0, IPC_RMID, 0);
	semctl(semid, 1, IPC_RMID, 0);
	return 0;
}
