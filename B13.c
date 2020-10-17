#include<stdio.h>
int main()
{
	int n=10,arr[n];
	int max=0,s,i,j,z;
	for (i=0;i<10;i++)
		scanf("%d",&arr[i]);
	i=0;
	for (j=0;j<10;j++)
	{
		z=arr[i];
		if (z<0)
			max=i;	
		i++;		
	}	
	i=0;
	for (j=0;j<10;j++)
	{
		z=arr[i];
		if (z<0&&z>arr[max])
			max=i;
		i++;		
	}
	if (max!=0||arr[max]<0){
	s=arr[9];
	arr[9]=arr[max];
	arr[max]=s;
	}
	for (i=0;i<10;i++)
		printf("%d ",arr[i]);
	
	return 0;
}
