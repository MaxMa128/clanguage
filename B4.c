#include<stdio.h>
int is_happy_number(int n)
{
	int a=0,b=1;
	while(n!=0)
	{
		a=a+n%10;
		b=b*(n%10);
		n=n/10;
	}
	if (a==b)
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}
int main()
{
	int m;
	scanf("%d",&m);
	is_happy_number(m);
	return 0;
}
