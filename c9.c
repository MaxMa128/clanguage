#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct vector
{
	double x;
	double y;
	double z;
};
double cos_angle_vectors(struct vector a, struct vector b){
	double cos=0;
	cos = ((a.x)*(b.x)+(a.y)*(b.y)+(a.z)*(b.z))/((sqrt((a.x)*(a.x)+(a.y)*(a.y)+(a.z)*(a.z)))*sqrt((b.x)*(b.x)+(b.y)*(b.y)+(b.z)*(b.z)));
	if (sqrt((a.x)*(a.x)+(a.y)*(a.y)+(a.z)*(a.z)) == 0||sqrt((b.x)*(b.x)+(b.y)*(b.y)+(b.z)*(b.z))==0){
		return -2;
	}else return cos;
}
int main()
{
	double cos;
	struct vector a;
	struct vector b;
	scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&a.z,&b.x,&b.y,&b.z);
	cos = cos_angle_vectors(a,b);
	printf("%.4lf",cos);
	return 0;
}
