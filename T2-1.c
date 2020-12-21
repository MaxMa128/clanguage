#include <stdio.h>

int main()
{
	unsigned int n;
    scanf("%u",&n);
    n = ((n&0xff)<<24) | (((n>>8)&0xff)<<16) | (((n>>16)&0xff)<<8) | ((n>>24)&0xff);
	printf("%u",n);
    return 0;
}
