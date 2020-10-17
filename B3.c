#include<stdio.h>
float sinus(float x)
{
	float x1=1,x2=1,s=0,f=1,a,b=1,c=0; 
	c=x;
	while (c>90){
		while (c>=360)
			c=c-360;
		while (c>=180)
			c=-(c-180);
		if (c>90) c=180-c;
	}
	while (c<-90){
		while (c<=-360)
			c=c+360;
		while (c<=-180)
			c=-(c+180);
		if (c<-90) c=-(180+c);
	} 
	c=c*3.1415926/180;
	for(a=1;a<=10;a+=2)   
	{
		while(b<=a)
		{	
			x1*=c;
			x2*=b;
			b++;
		}	
		f=-f;
		s=s-f*(x1/x2);	
	}
	printf("%.3f\n",s);
	return 0;
 } 
int main()
{
	float m;
	scanf("%f",&m);
	sinus(m);
	return 0;
}
