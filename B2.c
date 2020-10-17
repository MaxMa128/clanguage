#include<stdio.h>
void print_simple(int n)
{
	int k,i;
	while(n!=1)
	{
		for(k=2;k<=n;++k)
		{
			for(i=1;i<k;++i)
			{
				if(k%i==0)
				break;
			}
			if(k==i||n%k==0)
			break;
		}
		printf("%d ",k);
		n=n/k;
	}
}
int main()
{
	int m;
	scanf("%d",&m);
	print_simple(m);
}
