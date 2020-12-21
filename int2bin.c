#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc ,char **argv)
{
	FILE *f;//read file text
	int fd,num;//write file binary
	if(argc<3)
	{	printf("./int2bin text_file bin_file\n");
		return 1;
	}
	f=fopen(argv[1],"r");
	if(f==NULL)
	{	fprintf(stderr,"can't open file %s\n",argv[1]);
		return 2;
	}
	fd=creat(argv[2],0644);
	if(fd == -1)
	{fprintf(stderr,"can't creat flie %s\n",argv[2]);
		return 2;
	}
	while(fscanf(f,"%d",&num)!=EOF)
	write(fd,&num,sizeof(num));
	fclose(f);
	close(fd);
	return 0;
}
