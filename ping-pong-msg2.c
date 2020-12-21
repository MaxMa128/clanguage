#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define CNT_MAX 10

struct msgbuf{
	long mtype;
	long cnt;
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid;

	key = ftok("ping-pong.c",'t');
	if(key < 0){ perror("key"); return 1;}

	msgid =msgget(key,IPC_CREAT | 0666);
	if(msgid < 0){ perror("msgid"); return 2;}

	message.mtype = 2;
	message.cnt = 0;
	msgsnd(msgid,&message,sizeof(long),0);
	
	while(1)
	{
		msgrcv(msgid,&message,sizeof(long),1,0);
		printf("cnt= %ld mtype = %ld \n",message.cnt,message.mtype);
		if(message.cnt<CNT_MAX)
		{
			message.cnt++;
			message.mtype = 2;
			msgsnd(msgid,&message,sizeof(long),0);
		}
		else
		{
			message.cnt = -1;
			message.mtype = 2;
			msgsnd(msgid,&message,sizeof(long),0);
			break;
		}
	}
	return 0; 
}
