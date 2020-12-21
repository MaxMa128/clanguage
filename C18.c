#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	int fd1,fd2,i,j,k;
	if(argc<3)
	{
		printf("need 2 file£º file1.bin and file2.bin\n");
  		return 1;
	}
	fd1=open(argv[1],O_RDWR);
	if(fd1==-1)
	{
		printf("can't open %s\n",argv[1]);
		return 2;
	}
	fd2=creat(argv[2],0644);
	if(fd2==-1)
	{
		printf("can't create %s\n",argv[2]);
		return 2;
	}
	if(read(fd1,&i,sizeof(int))!=sizeof(int))
	{
		printf("empty file\n");
  		return 0;
	}
	write(fd2,&i,sizeof(int));
	while(read(fd1,&i,sizeof(int))==sizeof(int))
	write(fd2,&i,sizeof(int));
	fd2=open(argv[2],O_RDWR);
	k=1;
	while(k)
	{
		k=0;
		lseek(fd2,0,SEEK_SET);
		while(read(fd2,&i,sizeof(int))==sizeof(int))
		{
			if(read(fd2,&j,sizeof(int))!=sizeof(int))
   				break;
  			if(i>j)
  			{ 
				printf("change %d and %d \n",i,j);
   				lseek(fd2,-2*sizeof(int),SEEK_CUR);
   				write(fd2,&j,sizeof(int));
   				write(fd2,&i,sizeof(int));
   				k=1;
   			}
  			lseek(fd2,-sizeof(int),SEEK_CUR); 
  			printf("1\n");
  		}
  		printf("2\n");
 	}
	close(fd1);
	close(fd2);
	return 0;
}
