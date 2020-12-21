#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

volatile int flag = 0;

void Handler(int s)
{
	signal(SIGUSR1,Handler);
	flag = 1;
}

int main()
{
	pid_t pid;
	int fd[2];
	int cnt = 0, Cnt_Max;

	scanf("%d",&Cnt_Max);
	if (pipe(fd) < 0) { perror("pipe"); return 1; }
	signal(SIGUSR1,Handler);
	pid = fork();
	if (pid < 0){ perror("fork"); return 2;}
	else if (pid == 0)
	{
		pid_t pidf = getppid();//pidf = PID Father
		while(cnt < Cnt_Max) // 0 < 10
		{
			if (!flag) pause(); // wait
			flag = 0;
			read(fd[0],&cnt,sizeof(int)); // cnt = 0 <- pipe 
			printf("son %d\n",cnt++); // son 0 cnt = 1
			fflush(stdout);
			write(fd[1],&cnt,sizeof(int)); // 1 -> pipe 1
			kill(pidf,SIGUSR1); // send signal
		}
		close(fd[0]);
		close(fd[1]);
		return 0;
	}
	else
	{
		// pid = PID son
		write(fd[1],&cnt,sizeof(int)); // cnt = 0 -> pipe 0
		kill(pid,SIGUSR1); // send signal
		while(cnt < Cnt_Max) // 0 < 10
		{
			if (!flag) pause(); // wait
			flag = 0;
			read(fd[0],&cnt,sizeof(int)); // cnt = 1 <- pipe
			printf("father %d\n",cnt++); // father 1 cnt = 2
			fflush(stdout);
			write(fd[1],&cnt,sizeof(int)); // 2 -> pipe 2
			kill(pid,SIGUSR1); // send signal
		}
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		return 0;
	}
}
