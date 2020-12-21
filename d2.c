#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
// input need ctrl D
int main()
{
	int fd[2];
	pipe(fd);
	if (fork() > 0)
	{
		int k;
		close(fd[0]);
		while(scanf("%d",&k)!=EOF)
			write(fd[1],&k,sizeof(int));
		close(fd[1]);
	}
	else
	{
		int max,min,n;
		close(fd[1]);
		read(fd[0],&n,sizeof(int));
		max=min=n;
		while(read(fd[0],&n,sizeof(int))>0)
		{
			if(n > max)
				max=n;
			if(n < min)
				min=n;
		}
		close(fd[0]);
		printf("%d %d\n",min,max);
	}
	return 0;
}
