#include<stdio.h>
int main()
{
	int n=10,arr[n];
	int max=0,min=0,s,i,j;
	for (i=0;i<10;i++)
		scanf("%d",&arr[i]);
	i=0;
	for (j=0;j<10;j++)
	{
		if (arr[i]>arr[max])
			max=i;
		if (arr[i]<arr[min])
			min=i;	
		i++;		
	}	
	s=arr[max];
	arr[max]=arr[min];
	i=0;
	for (j=0;j<10;j++)
	{
		if (arr[i]>arr[max])
			max=i;
		i++;		
	}	
	s+=arr[max];
	printf("%d",s);
	return 0;
}
