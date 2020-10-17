#include<stdio.h>
#define n 5
int main()
{
	int arr[n][n];
	float aver=0;
	int max=0,i=0,j=0,k=0;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	for (i=0;i<n;i++){ 
		aver+=arr[i][k];
		k++;
		}
		aver=aver/n; 
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (arr[i][j]>aver) max++;	
	printf("%d",max);
	return 0;
}
