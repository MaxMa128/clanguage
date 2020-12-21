#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

volatile int flag = 0;
volatile int flags = 1;

void Handler(int s)
{
	signal(SIGUSR1,Handler);
	flag = 1;
}
void min2(int a);

int main()
{
	pid_t pid, pidg;
	int fd[2],count;
	int cnt = 0, Cnt_Max;

	scanf("%d",&Cnt_Max);
	if(Cnt_Max > 2)
		count = 2;
	else{ min2(Cnt_Max); return 0;};
	if (pipe(fd) < 0) { perror("pipe"); return 1; }
	signal(SIGUSR1,Handler);
	pid = fork();
	
	if (pid < 0){ perror("fork"); return 2;}
	else if (pid == 0)
	{
		pidg=fork();
            	if(pidg < 0){ perror("fork");return 3;}
     		else if (pidg == 0)
		{
            		if (cnt==Cnt_Max)
                		return 0;
            		pid_t pid=getppid();// PID grandson
            		while (cnt<Cnt_Max-count) 
			{
               			if(!flag) pause();
               		 	flag=0;
                		read(fd[0], &cnt, sizeof(int));
                		printf("grandson %d\n",cnt++);
               			fflush(stdout);
                		write(fd[1], &cnt, sizeof(int));
                		kill(pid, SIGUSR1);
            		}
	            	close(fd[0]);
        	    	close(fd[1]);
            		return 0;
        	}
		else
		{
			pid_t pidf = getppid();//pidf = PID Father
			pause();
			while(cnt < Cnt_Max) // 0 < 10
			{
				if (!flag) pause(); // wait
				flag = 0;
				read(fd[0],&cnt,sizeof(int)); // cnt = 0 <- pipe 
				printf("son %d\n",cnt++); // son 0 cnt = 1
				fflush(stdout);
				write(fd[1],&cnt,sizeof(int)); // 1 -> pipe 1
				if (flags == 1) 
				{
                   			flags = 0;
                    			kill(pidf, SIGUSR1);
                		}else
				{
                    			flags=1;
                    			kill(pidg, SIGUSR1);
                		}
			}
		close(fd[0]);
		close(fd[1]);
		return 0;
		}
	}
	else
	{
		// pid = PID son
		write(fd[1],&cnt,sizeof(int)); // 
		kill(pid,SIGUSR1); // send signal
		if (Cnt_Max >= 2)
		{
			while(cnt < Cnt_Max-count) 
			{
				if (!flag) pause(); 
				flag = 0;
				read(fd[0],&cnt,sizeof(int));
				printf("father %d\n",cnt++); 
				fflush(stdout);
				write(fd[1],&cnt,sizeof(int)); 
				kill(pid,SIGUSR1); // send signal
			}
		}
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		return 0;
	}
}

void min2(int a)
{
	if(a == 0)
		printf("grandson 0\n");
	if(a == 1)
		printf("grandson 0\nson 1\n");
	if(a == 2)
		printf("grandson 0\nson 1\nfather 2\n");
}
