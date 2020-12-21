#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

// pr1 arg1 | pr2        //ls -l  wc out
int main(int argc,char **argv)
{
	int fd[2],out;
	pid_t pid1,pid2;
	if ( argc < 5)
		return 1;
	out=open(argv[4],O_RDWR|O_CREAT|O_EXCL,0644);
	if ( pipe(fd) < 0) 
	{
		perror("pipe"); 
		return 2;
	}
	pid1 = fork();
	if (pid1 < 0) {perror("fork1"); return 3;}
	else if(pid1 == 0)
	{
		dup2(fd[1],1);
		close(fd[1]);
		close(fd[0]);
		if(strcmp(argv[4],"out")==0)
             execlp(argv[1],argv[1],argv[2],argv[3],NULL);
		fprintf(stderr,"can't start %s\n",argv[1]);
		return 4;
	}
	pid2 = fork();
	if ( pid2 < 0) { perror("fork2"); return 2;}
	else if(pid2 == 0)
	{
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		execlp(argv[4],argv[4],NULL);
		fprintf(stderr,"can't start %s \n",argv[4]);
		return 4;
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return  0;

}

