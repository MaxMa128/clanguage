#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
        int fd;
        long a,b,min;
		long min_p;
        fd = open("input.bin",O_RDWR);
        if(fd==-1)
        {
                fprintf(stderr,"can't open flie input.bin");
                return 2;
        }
        read(fd,&a,sizeof(a));
        min=a;
        min_p=0;
        while(read(fd,&a,sizeof(a))==sizeof(a))
        {
                if(a<min)
                {
                        min=a;
                        min_p=lseek(fd,0,SEEK_CUR)-sizeof(long);
                }
        }
        b=-min; 
		lseek(fd,min_p,SEEK_SET);
        write(fd,&b,sizeof(b));
        close(fd);
        return 0;
}


