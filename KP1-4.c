#include<stdio.h>
#include<string.h>
#define N 289

int main(int argc,char**argv)
{
	FILE *fi;
	int min_len,max_len,first;
	char str[N],max_word[N],min_word[N];
	if (argc<2)
		return 1;
	fi = fopen(argv[1],"r");
	if (fi == NULL)
		return 1;
	while (fgets(str,sizeof(str),fi))
	{
		int len = strlen(str);
		str[len-1]=0;
		char* buf = NULL;
		buf = strtok(str," .");
		if (first)
		{
			first=0;
			min_len=max_len=strlen(buf);
			strcpy(max_word,buf);
			strcpy(min_word,buf);
			buf = strtok(NULL," .");
		}
		if(buf)
		{
			do{
				if(strlen(buf)>max_len)
				{
					max_len=strlen(buf);
					strcpy(max_word,buf);
				}
				if(strlen(buf)<min_len)
				{
					min_len=strlen(buf);
					strcpy(min_word,buf);
				}
			}while(buf=strtok(NULL," ."));
		}
	}
	fclose(fi);
	printf("%s %s\n",max_word,min_word);
	return 0;
}

