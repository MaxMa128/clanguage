#include<stdio.h>
void print_bin(unsigned char c)
{
	int mask = 1;
	for(mask <<= 7;mask;mask>>=1)
	{
		if (c&mask) printf("1");
		else printf("0");
	}
	printf("\n");
}//shuchuerjinzhi

int main()
{
	unsigned char c,ch;
	int mask;
	scanf("%hhu",&c);
	print_bin(c);
	mask = 3; 
	mask <<= 6;
	ch = (c&mask)>>6 | c<<2;
	print_bin(ch);
	printf("%hhu\n",ch);
	return 0 ;
}
