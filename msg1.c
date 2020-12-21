#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
//第一个字母是a/A 发到msg2
//若b 发到msg3
//q 退出
struct msgbuf{
	long mtype; // type message
	char data[256];
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid;
	char str[256];

	key = ftok("ping-pong.c",'h');
	if(key < 0) { perror("key"); return 1;}

	msgid = msgget(key, IPC_CREAT | 0666);
	if (msgid < 0) { perror("msgget"); return 2;}

	while(1)
	{
		fgets(str, 255, stdin);
		strcpy(message.data,str);// if 1 st letter 'a' send to process 2
					// if 1st letter 'b' send to process 3
		switch(str[0])
		{
			case 'a':
			case 'A':
				message.mtype = 1;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				break;
			case 'b':
			case 'B':
				message.mtype = 2;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				break;
			case 'q':
			case 'Q':
				strcpy(message.data,"q");
				message.mtype = 1;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				message.mtype = 2;
				msgsnd(msgid, &message, strlen(str)+1, 0);
				sleep(1);
				msgctl(msgid,IPC_RMID, 0);//delete queue
				return 0;
			default:
				break;
		}
	}
}




