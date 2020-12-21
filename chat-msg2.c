#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

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
    struct msgbuf buf;
    pid_t pid;
	
    key = ftok("ping-pong.c",'h');
    msgid = msgget(key, 0); 
    if(msgid < 0){ perror("msgget");return 1;}

    pid = fork();

    if (pid < 0){ perror("fork");return 2;}
    else if (pid == 0)      //son
    {
        while(1)
        {
            memset(&message, 0, sizeof(message));   
            scanf("%s", message.data);
            message.mtype = 2;  //type 2-send

            ret = msgsnd(msgid, &message, sizeof(message.data), 0);   
            if (ret < 0){ perror("msgsnd");return 3;}
            if (!strncmp(message.data, "q", 1))  //q
            {
                message.mtype = 1;
                ret = msgsnd(msgid, &message, sizeof(message.data), 0);
                if (ret < 0){ perror("msgrcv");return 4;}
                break;
            }
        }
    }

    else       
    {
        while(1)
        {
            memset(&message, 0, sizeof(message));

            ret = msgrcv(msgid, &message, sizeof(message.data), 1, 0);
            if ( ret < 0){ perror("msgrcv");return 5;}
            if (!strncmp(message.data, "q", 1))  //q
            {
                kill(pid, SIGKILL); 
                break;
            }

            printf("Receive: %s\n", message.data);   
        }
        waitpid(pid, NULL, 0);  

        return 0;
    }
	msgctl(msgid,IPC_RMID, 0);
}
