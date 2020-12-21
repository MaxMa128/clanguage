#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	int fd;
	if(argc < 2)
	{
		fprintf(stderr,"need filename\n");
		exit(1);
	}
//	fd = open(argv[1], O_RDONLY);// rean
//	fd = open(argv[1], O_WRONLY | O_APPEND);// write & append
//	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC , 0644);
//	fd = creat(argv[1],0644);
	fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL  , 0644);
	if (fd == -1)
	{
		fprintf(stderr,"can't open file %s\n",argv[1]);
		exit(1);
	}
	printf("fd = %d\n",fd);
	close(fd);
	return 0;
}

