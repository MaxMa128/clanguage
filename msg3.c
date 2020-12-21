#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf{
	long mtype;
	char data[256];
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid;

	key = ftok("ping-pong.c",'h');
	if (key < 0) { perror("key"); return 1;}

	msgid = msgget(key, IPC_CREAT | 0666);
	if (msgid < 0) { perror("msgget"); return 2;}

	for(;;) //endless cycle
	{
		msgrcv(msgid, &message, 256 , 2, 0); //receive message type 2
		if (strcmp(message.data,"q") == 0)
			break;
		else
			printf("\nProcess received: %s\n",message.data);
	}
	return 0;
}

