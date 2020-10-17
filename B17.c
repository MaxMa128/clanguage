#include<stdio.h>
#define n 10
int main()
{
	int arr[n][n];
	int max=0,sum=0,i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&arr[i][j]);
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (arr[i][j]>arr[i][max])
			max=j;
		}
		sum+=arr[i][max]; 
	}	
	printf("%d",sum);
	return 0;
}
