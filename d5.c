#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

// pr1 arg1 arg2 | pr2 arg3 |pr3       //ls -l -a|grep rwx |wc 
int main(int argc,char **argv)
{
	int fd[2];
	pid_t pid1,pid2,pid3;
	if ( argc < 6)
	{
		printf("use: ./a.out pr1 arg1 arg2 pr2\n");
		return 1;
	}
	if ( pipe(fd) < 0) {perror("pipe"); return 2;}
	
	pid1 = fork();
	if (pid1 < 0) {perror("fork1"); return 3;}
	else if(pid1 == 0)
	{
		dup2(fd[1],1);
		close(fd[1]);
		close(fd[0]);
		execlp(argv[1],argv[1],argv[2],argv[3],NULL);
		execlp(argv[4],argv[4],argv[5],NULL);
		fprintf(stderr,"can't start %s\n",argv[1]);
		return 4;
	}
//	pid2 = fork();
//        if (pid2 < 0) {perror("fork2"); return 3;}
//        else if(pid2 == 0)
//        {
//                dup2(fd[1],1);
//                close(fd[1]);
//                close(fd[0]);
//                execlp(argv[4],argv[4],argv[5],NULL);
//                fprintf(stderr,"can't start %s\n",argv[4]);
//                return 4;
//        }

	pid3 = fork();
	if ( pid3 < 0) { perror("fork2"); return 2;}
	else if(pid3 == 0)
	{
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		execlp(argv[6],argv[6],NULL);
		fprintf(stderr,"can't start %s \n",argv[6]);
		return 5;
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
//	wait(NULL);
	return  0;

}

