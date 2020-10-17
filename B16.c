#include<stdio.h>
#define n 1000
int main()
{
	int arr1[n],arr2[n];
	int max=0,min=0,i=0,j,k,a=0;
	for (i=0;i<n;i++){
			scanf("%d",&arr1[i]);
		if (arr1[i]==0) break;
	}
	j=i;
	for (i=0;i<j;i++)
	{
		if (arr1[i]>arr1[max])
			max=i;
		if (arr1[i]<arr1[min])
			min=i;		
	}	
	j++;
	for(i=0;i<j;i++){
		arr2[i]=arr1[min]+a;
		a++;
	}
	i=0;
	while(arr1[i]!=0){
		for (k=0;k<j;k++) {
			if (arr1[i]==arr2[k]) {
				arr2[k]=0;
				break;
			}
		}
		i++;
	}
	for (i=0;i<j;i++)
		if (arr2[i]!=0) printf("%d",arr2[i]);
	return 0;
}
