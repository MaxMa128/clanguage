#include <stdio.h>
int change(int n) 
{
	int a,b=1,c=0;
    for (a=0;a<64;a++)
	{
        if(n==0)
		{
            c>>=1;
            break;
        }
        if(n&b==1)
		{
            c++;
            c<<=1;
        } else
            c<<=1;
        n>>=1;
    }
    printf("%d",c);
    return 0;
}
int main()
{
	int n;
    scanf("%d",&n);
    change(n);
    return 0;
}
