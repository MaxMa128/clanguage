#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<sys/wait.h>

volatule int flag = 0;
void Handler(int s)
{
	signal(SIGUSR1, Handler);
	flag = 1;
}

int do_work(int *fd)
{
	pid_t pidf = getppid();
	int sum = 0, num;
	while(1)
	{
		if(!flag) pause();//wait
		flag = 0;
		if (read(fd[0], &num, sizeof(int)) != sizeof(int))
			break;
		else
		{
			sum += num;
			kill(pidf,SIGUSR1); 
		}
	}
	return sum;
}
int main()
{
	int fd[2];
	int num, i = 0;
	pid_t pid[2];
	
	if(pipe(fd) < 0) { perror("pipe"); return 1;}
	
	signal(SIGUSR1, Handler);
	
	if ( (pid[0] = fork()) < 0){ perror("fork1"); return 2;}
	else if (pid[0] == 0)//son 1
	{
		int sum = 0, num;
		close(fd[1]);
		sum = do_work(fd);//sum of numbers
		close(fd[0]);
		printf("son1 %d\n",sum); fflush(stdout);
		kill(getppid(),SIGUSR1);
		return 0;
	}
	if ( (pid[1] = fork()) < 0){ perror("fork2"); return 3;}
	else if (pid[1] == 0)//son 2
	{
		int sum = 0;
		close(fd[1]);
		sum = do_work(fd);//sum of numbers
		close(fd[0]);
		printf("son2 %d\n",sum); fflush(stdout);
		return 0;
	}
	//father
	i=0;
	close(fd[0]);
	while(scanf("%d", &num) != EOF)
	{
		write(fd[1], &num, sizeof(int)); //num = 2 -> pipe
		kill(pid[i], SIGUSR1);//SIGUSR1 pid[1] i=1
		i++; i = i%2;// i=0 or i=1
		if(!flag) pause();
		flag =0;
	}
	close(fd[1]);//pipe -> EOF
	kill(pid[0],SIGUSR1); //SIGUSR1 son1
	if(!flag) pause();
	flag = 0;
	kill(pid[1],SIGUSR1);// SIGUSR1 son2
	wait(NULL);
	wait(NULL);
	return 0;
}

