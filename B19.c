#include<stdio.h>
int main()
{
	int n=10,arr[n];
	int odd=0,even=0,i,j,k;
	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for (i=0;i<n;i++){
		if (arr[i]%2!=0)
			odd++;
		if (arr[i]%2==0)
			even++;	
	}	
	if (odd<even){
		for (i=0;i<n;i++){
			k=1;
			if (arr[i]%2!=0){
				while (arr[i]!=0){
					if ((arr[i]%10)%2!=0) k*=arr[i]%10;
					arr[i]/=10;
				}
				arr[i]=k;
			}
	}}
	if (odd>=even){
		for (i=0;i<n;i++){
			k=1;
			if (arr[i]%2==0){
				while (arr[i]!=0){
					if ((arr[i]%10)%2==0) k*=arr[i]%10;
					arr[i]/=10;
				}
				arr[i]=k;
			}
	}}
	for (i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}
