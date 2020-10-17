#include<stdio.h>
#include<string.h>
int is_palindrom(char s[]);
int main()
{
    char str[1001];
	char c;
    int i,k=0,n=0;
   	while(scanf("%c",&c)!=EOF&&c!='\n'){
		str[n]=c;
		n++;
	}
	str[n]=0;
	k = is_palindrom(str);
	if (k==1){
		printf("YES");
	}else printf("NO");
    return 0;
}

int is_palindrom(char *s)
{
	int arr[26],i,n=0,k=0;
	for(i = 0;i < 26;i++)
		arr[i]=0;
	for(i = 0;i < strlen(s);i++)
	{
		if (s[i]>='a'&&s[i]<='z')
		{
			n = s[i]-'a';
			arr[n]++;
		}
	}
	for(i = 0;i < 26;i++)
	{
		if(arr[i]%2!=0)
			k++;
	}
	return k;
}
