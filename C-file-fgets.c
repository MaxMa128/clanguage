//input wert
//output wert
//
//intput wergtyujfefgtyukjsyjrht
//output string is very long
#include<stdio.h>
#include<string.h>

int main()
{
	char buf[20];
	int len;
	fgets(buf,sizeof(buf),stdin);
	len = strlen(buf);
	if (len == sizeof(buf)-1 && buf[len-2] != '\n')
	{
		printf("string is very long\n");
		return -1;
	}
	else 
		fputs(buf,stdout);
	return 0;
}
