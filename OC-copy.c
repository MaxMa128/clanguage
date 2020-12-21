//linux÷¥––copy2:
//vim data
//  wegfaerwgasdgsdfsdf
//gcc copy2.c
//./a.out data data1

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char **argv)
{
	int fd1, fd2, n;
	char buf[1024];
	struct stat s;
	if(argc < 3)
	{
		printf("use: ./copy first_file second_file\n");
		return 1;
	}
	fd1 = open(argv[1],O_RDONLY);
	if (fd1 == -1)
	{
		fprintf(stderr,"can't open file %s\n",argv[1]);
		return 1;
	}
	stat(argv[1],&s);
	fd2 = creat(argv[2],s.st_mode);
	if (fd2 == -1)
	{
		fprintf(stderr,"can't open file %s\n",argv[2]);
		return 1;
	}
	while((n = read(fd1,buf,1024))>0)
		write(fd2,buf,n);
	close(fd1);
	close(fd2);
	return 0;
}

