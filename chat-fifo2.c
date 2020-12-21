//filename:peter.c
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    char write_fifo_name[]="read-fifo";
    char read_fifo_name[]="write-fifo";
    int write_fd,read_fd;
    char buf[256];
    int len;
    //struct stat_buf;
    
    int ret=mkfifo(write_fifo_name,S_IRUSR | S_IWUSR);
    if(ret==-1)
    {
        printf("failed to create FIFO %s:%s\n",write_fifo_name,strerror(errno));
    exit(-1);
    }
        while((read_fd=open(read_fifo_name,O_RDONLY))==-1)
    {
        sleep(1);
    }    
    
    write_fd=open(write_fifo_name,O_WRONLY);
        if(write_fd==-1)
        {
            printf("failed to open FIFO %s:%s\n",write_fifo_name,strerror(errno));
    exit(-1);
        }
    

    
    while(1)
    {
        len=read(read_fd,buf,256);
        if(len>0)
        {
            buf[len]='\0';
            printf("马瀚文:%s\n",buf);
        }
        printf("王琪瑞:");
    fgets(buf,256,stdin);
    buf[strlen(buf)-1]='\0';
    if(strncmp(buf,"quit",4)==0)
    {
        close(write_fd);
        unlink(write_fifo_name);
        close(read_fd);
        exit(0);
    }
        write(write_fd,buf,strlen(buf));
    }
}
