#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

struct msgbuf
{
    long mtype;
    char data[256];
};

int main()
{
    struct msgbuf message;
    key_t key;
    int msgid;
    int ret;
    pid_t pid;

    key = ftok("ping-pong.c",'h');
    msgid = msgget(key, IPC_CREAT | 0666);   //creat mess
    if(msgid < 0){ perror("msgget"); return 1;}

    pid = fork();   

    if (pid < 0){perror("fork");return 2;}
    else if (pid == 0) 
    {
        while(1)
        {
            memset(&message, 0, sizeof(message)); 
            scanf("%s", message.data);
            message.mtype = 1;  //type 1
            ret = msgsnd(msgid, &message, sizeof(message.data), 0);//send
            if (ret < 0) {perror("msgsnd");return 3;}
            if (!strncmp(message.data, "q", 1))  // q- quit
            {
                message.mtype = 2;  // receive father type 2
                ret = msgsnd(msgid, &message, sizeof(message.data), 0);
                if(ret < 0){perror("msgsnd");return 4;}
                break;
            }   
        }
    }

    else   
    {// father
        while(1)
        {
            memset(&message, 0, sizeof(message));

            ret = msgrcv(msgid, &message, sizeof(message.data), 2, 0);
            if (ret < 0) {perror("msgrcv");return 1;}
            if (!strncmp(message.data, "1", 1))  //q
            {
                kill(pid, SIGKILL);
                break;
            }
            printf("Receive: %s\n", message.data); 
        }
        waitpid(pid, NULL, 0);
    }
        msgctl(msgid, IPC_RMID, 0); 

        return 0;
}

