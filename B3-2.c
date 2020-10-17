#include<stdio.h>
int main()
{
	float x,s;
	scanf("%f",&x);
	x=x*3.1415926/180;
	s=x-x*x*x/6+x*x*x*x*x/120;
	printf("%.3f",s);
}
