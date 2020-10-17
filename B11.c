#include<stdio.h>
int main()
{
	int arr[10];
	int i,j,s;
	for (i=0;i<10;i++)
		scanf("%d",&arr[i]);
	s=arr[0]; arr[0]=arr[4]; arr[4]=s;
	s=arr[1]; arr[1]=arr[3]; arr[3]=s;
	s=arr[5]; arr[5]=arr[9]; arr[9]=s;
	s=arr[6]; arr[6]=arr[8]; arr[8]=s;
	for (i=0;i<10;i++)
		printf("%d ",arr[i]);
	return 0;
}
