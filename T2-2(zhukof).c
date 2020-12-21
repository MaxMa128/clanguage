#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
// echo "The result of task2" > out
// pr1 arg1 | pr2 >> out  //./out ls -l -a out
int main(int argc, char** argv)
{
	int fd[2],fd1;
	pid_t pid1, pid2;
	char str[] = "The result of task2\n";
	if (argc < 4)
	{
		return 1;
	}
	if (pipe(fd) < 0) { perror("pipe"); return 2; }
	
	fd1 = creat(argv[4], 0644);//echo "The..." > out
	if (fd1 < 0) { perror("creat"); return 5; }
	write(fd1,str,strlen(str));
	close(fd1);
	
	pid1 = fork();
	if (pid1 < 0) { perror("fork1"); return 3; }
	else if (pid1 == 0)
	{
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		execlp(argv[1], argv[1], argv[2], NULL);
		fprintf(stderr, "can't start %s\n", argv[1]);
		return 4;
	}
	pid2 = fork();
	if (pid2 < 0) { perror("fork2"); return 2; }
	else if (pid2 == 0)
	{
		fd1 = open(argv[4],O_WRONLY | O_APPEND);
		if(fd1<0){
			perror("open");
			return 6;
		}
		dup2(fd[0], 0);
		dup2(fd1, 1);
		close(fd[0]);
		close(fd[1]);
		execlp(argv[3], argv[3], NULL);
		fprintf(stderr, "can't start %s\n", argv[3]);
		return 4;
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return 0;
}
