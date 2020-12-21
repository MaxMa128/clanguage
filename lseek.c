#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char** argv)
{
     int fd;
     int a,max,min;
     long max_p,min_p;
     if(argc<2)
     {
	     printf("need file\n");
	     return 1;
     }
     fd=open(argv[1],O_RDWR);
     if(fd==1)
     {
	     fprintf(stderr,"cant open file %s\n",argv[1]);
	     return 2;
     }
    if(read(fd,&a,sizeof(int))!=sizeof(int))
     {
	     printf("empty file\n");
	     return 3;
     }
     max=min=a;
     max_p=min_p=0;
     while(read(fd,&a,sizeof(int))==sizeof(int))
     {
	     if(a>max)
	     {
		     max=a;
		     max_p=lseek(fd,0,SEEK_CUR)-sizeof(int);
	     }
	     if(a<min)
	     {
		     min=a;
		     min_p=lseek(fd,0,SEEK_CUR)-sizeof(int);
	     }
     }
     lseek(fd,max_p,SEEK_SET);
     write(fd,&min,sizeof(int));
     lseek(fd,min_p,SEEK_SET);
     write(fd,&max,sizeof(int));
     close(fd);
     return 0;
}