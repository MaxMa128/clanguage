#include<stdio.h> 
#define n 20
int main()
{
	int arr1[n],arr2[n],arr3[n];
	int i,j=0,a=0;
	for (i=0;i<n;i++)
		scanf("%d",&arr1[i]);
	for (i=0;i<n;i++)
		if (arr1[i]%2==0){
			arr2[j]=arr1[i];
			j++;
		}else{
			arr3[a]=arr1[i];
			a++;
		}
	for (i=0;i<j;i++)
		printf("%d ",arr2[i]);
	for (i=0;i<a;i++)
		printf("%d ",arr3[i]);
	return 0;
		
}
