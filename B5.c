#include<stdio.h>
int main()
{
	char x;
	int a=0;
	scanf("%c",&x);
	while(x!='.')
	{
		if (x=='(')
			a++;
		if (x==')')
			a--;
		scanf("%c",&x);
		if (a<0) {
			printf("NO\n");
			goto x;
		}
	}
	if(a==0)
		printf("YES\n");
	else printf("NO\n");
	x:
	return 0;
} 
