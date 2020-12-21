#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int fd[2];
	pid_t pid;
	pipe(fd); // create pipe
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1],1);
		close(fd[0]);
		close(fd[1]);
		execlp("ls","ls","-l",NULL);
		fprintf(stderr,"can't start ls\n");
		return 1;
	}
	dup2(fd[0],0);
	close(fd[0]);
	close(fd[1]);
	execlp("wc","wc",NULL);
	fprintf(stderr,"can't wc\n");
	return 1;

}

