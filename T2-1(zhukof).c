#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
	int fd;
	const int SIZE_INT = sizeof(int);
	unsigned char data[SIZE_INT],i;
	if(argc < 2)
	{
		printf("./a.out bin_file\n");
		return 1;
	}
	fd = open(argv[1],O_RDWR);
	if(fd < 0) 
	{
		perror("open");
		return 2;
	}
	while(read(fd,data,SIZE_INT)==SIZE_INT)
	{
		lseek(fd,-SIZE_INT,SEEK_CUR);
		for(i=0;i<SIZE_INT;i++)
			write(fd,data+SIZE_INT-1-i,sizeof(char));
	}
	close(fd);
	return 0;
 } 
