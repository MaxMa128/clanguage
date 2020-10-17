#include<stdio.h>
int main()
{
	int n,i=0,k,j;
	int a[100];
	scanf("%d",&n);
	while(n)
	{
	a[i]=n%10;
	i++;
	n/=10;
	}
	for(j=0;j<i-1;j++)
		for(k=0;k<i-1-j;k++)
	{
		if(a[k]<a[k+1]){
			n=a[k+1];
			a[k+1]=a[k];
			a[k]=n;
		}
	}
	for (j=0;j<i;j++)
		printf("%d",a[j]);
}
