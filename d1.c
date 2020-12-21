#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int i=1,n;
	pid_t pid;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{	
		pid = fork();
		if(pid < 0)
		{
			perror("fork");
			return 1;
		}else if(pid == 0)
		{
			break;
		}
		if(i<n){
	  		printf("%d ",i);
			fflush(stdout);
		}else if(i=n)
			printf("%d\n",i);
		
	}
	return 0;
}
