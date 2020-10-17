#include<stdio.h>
#include<stdlib.h>
#define n 100
int main()
{   
	int l1,l2,c1,c2;
    int i,j,k,o=-1;
    int temp;
    int arr1[n][n], arr2[n][n], arr3[n][n];
    scanf("%d %d", &l1,&c1);
    for (i=0;i<l1;i++)
    {
        for (j=0;j<c1; j++)
        {
            scanf("%d", &temp);
            arr1[i][j] = temp;
        }
    }//input1
	scanf("%d %d",&l2,&c2);
    for (i=0;i<l2;i++)
    {
        for (j=0;j<c2;j++)
        {
            scanf("%d",&temp);
            arr2[i][j]=temp;
        }
    }//input2
    if (c1==l2&&l1>0&&c1>0&&c2>0){
    	for(i=0;i<l1;i++)
			for(j=0;j<c2;j++){
				arr3[i][j]=0;
				for(k=0;k<c1;k++)
					arr3[i][j]+=arr1[i][k]*arr2[k][j];
			}
		for (i = 0; i<l1; i++){
     	   for (j = 0; j<c2; j++)
        	    printf("%ld ", arr3[i][j]);
        printf("\n");
    	}
	}else printf("-1");//output
    return 0;
}
