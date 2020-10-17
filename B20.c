#include<stdio.h>
int facto(int n){
    int i,s=1;
	for(i=1;i<=n;i++)
		s=s*i;
	return s;
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		for(j=0;j<=i;j++)
			printf("%d ",facto(i)/(facto(i-j)*facto(j)));
		printf("\n");
	}
    return 0;
}
