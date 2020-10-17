#include<stdio.h> 
#define n 100
int main()
{
	int arr1[n],arr2[n],arr3[n];
	int i,j=0,a=0,b=0;
	for (i=0;i<n;i++)
		scanf("%d",&arr1[i]);
	while (arr1[n-1]!=3){
		a=0;j=0;
		for (i=0;i<n;i++){
			if (arr1[i]==0){
			arr1[i]=3;
			j++;		
			}else if (arr1[i]==1) break;
		}
		arr2[b]=j;
		b++;
		for (i=0;i<n;i++){
			if (arr1[i]==1){
			arr1[i]=3;
			a++;		
			}else if (arr1[i]==0) break;
		}
		arr2[b]=a;
		b++; 
	}
	printf("[");
	if (arr2[b-1]==0) {
	for (i=0;i<b-2;i++)
		printf("%d,",arr2[i]);
		printf("%d]",arr2[b-2]);
	}else {
		for (i=0;i<b-1;i++)
		printf("%d,",arr2[i]);
		printf("%d]",arr2[b-1]);
	}
	
	return 0;
}
