#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msgbuf{
	long mtype;
	long cnt;
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid;

	key = ftok("ping-pong.c", 't');
	if(key<0){perror("key");return 1;}

	msgid=msgget(key,IPC_CREAT | 0666);
	if(msgid<0){perror("msgid");return 2;}

	while(1)
	{
		msgrcv(msgid,&message,sizeof(long),2,0);
		printf("cnt=%ld type=%ld\n",message.cnt,message.mtype);
		if(message.cnt==-1)
			break;
		message.cnt ++;
		message.mtype =1;
		msgsnd(msgid,&message,sizeof(long),0);

	}

	msgctl(msgid,IPC_RMID,0);
	return 0;
}
