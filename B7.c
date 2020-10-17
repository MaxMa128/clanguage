#include <stdio.h>
int main()
{
	short n;
	int k=1,n_bit=sizeof(short)*4;
	unsigned short mask=1u<<n_bit;
	scanf("%ho",&n);
	while(mask)
	{
		if(n&mask)
			printf("1");
		else
			printf("0");
		mask>>=1;
	}
	printf("\n");
	mask=1u<<n_bit;
	while(mask)
	{
		if((n&mask)&&(k%3==1))
			printf("r");
			else if((n&mask)&&(k%3==2))
				printf("w");
				else if ((n&mask)&&(k%3==0))
					printf("x");
		else
			printf("-");
		mask>>=1;
		k++;
	}
	 return 0;
 } 
