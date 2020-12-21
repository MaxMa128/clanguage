#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
        int fd;
        int a,max,min;
        long max_p,min_p;
        fd = open("input.bin",O_RDWR);
        if(fd==-1)
        {	
		fprintf(stderr,"can't open flie data.bin");
                return 2;
        }
        read(fd,&a,sizeof(int));
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

