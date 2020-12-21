#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

struct msgbuf {
	long mtype;
	char str[256];
};

int main()
{
	struct msgbuf message;
	key_t key;
	int msgid;
	char c1 = 'a', c2 = '0', c3 = 'A';
	int n, i = 0, file;

	file = creat("file",0666);
	if(file < 0){perror("creat"); return 4;}

	scanf("%d", &n);

	key = ftok("file", 'l');
	if (key < 0) { perror("ftok"); return 1; }

	msgid = msgget(key, IPC_CREAT | 0666);
	if (msgid < 0) { perror("msgget"); return 2; }

	pid_t pid1, pid2, pid3;
	if ((pid1 = fork()) < 0)
	{
		perror("fork"); return 3;
	}
	else if (pid1 == 0)//s1
	{
		i = 0;
		for (;;)
		{
			message.str[i] = c1;
			if (i > n) {
				message.mtype = 4;
				msgsnd(msgid, &message, 256, 0);
				break;
			}
			if (c1 < 'z')
				c1++;
			else
				c1 = 'a';
			i+=3;
			message.mtype = 2;
			msgsnd(msgid, &message, 256, 0);
			msgrcv(msgid, &message, 256, 1, 0);
		}
		return 0;
	}
	else//f
	{
		if ((pid2 = fork()) < 0)
		{
			perror("fork"); return 2;
		}
		else if (pid2 == 0)//s2
		{
			i = 1;
			for (;;)
			{
				msgrcv(msgid, &message, 256, 2, 0);
				message.str[i] = c2;
				if (i >= n) {
					message.mtype = 4;
					msgsnd(msgid, &message, 256, 0);
					break;
				}
				if (c2 < '9')
					c2++;
				else
					c2 = '0';
				i+=3;
				message.mtype = 3;
				msgsnd(msgid, &message, 256, 0);
			}
			return 0;
		}
		else
		{
			if ((pid3 = fork()) < 0)
			{
				perror("fork"); return 2;
			}
			else if (pid3 == 0)//s3
			{
				i =  2;
				for (;;)
				{
					msgrcv(msgid, &message, 256, 3, 0);
					message.str[i] = c3;
					if (i >= n) {
						message.mtype = 4;
						msgsnd(msgid, &message, 256, 0);
						break;
					}
					if (c3 < 'Z')
						c3++;
					else
						c3 = 'A';
					i+=3;
					message.mtype = 1;
					msgsnd(msgid, &message, 256, 0);
				}
				return 0;
			}
			else//f
			{
				msgrcv(msgid, &message, 256, 4, 0);
				message.str[n] = '\0';
				printf("%s\n", message.str);
			}
		}
	}
	msgctl(msgid, IPC_RMID, 0);
	return 0;
}
