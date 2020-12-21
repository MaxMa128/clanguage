#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
// pr1 arg1 arg2 > pr2        //ls -l -a out
int main(int argc,char **argv)
{
	int fd[2],n;
	pid_t pid1;
	if (argc<5)
		return 1;
	n = open(argv[4],O_RDWR|O_CREAT|O_EXCL,0644);
	if(pipe(fd)<0)
	{
		perror("pipe");
		return 2; 
	}
	pid1=fork();
	if(pid1<0)
	{
		perror("fork");
		return 3;
	}
	else if(pid1==0)
	{
		close(1);
		dup2(n,1);
		close(fd[1]);
		close(fd[0]);
		if(strcmp(argv[4],"out")==0)
             execlp(argv[1],argv[1],argv[2],argv[3],NULL);
		return 4;
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	return 0;
}
