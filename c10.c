#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct person{
	char name[20]; 
	int age; 
};
int main()
{
	struct person students[20];
	struct person *p = students,*q = 0;
	struct person temp;
	int n = 0,i,j,k=20;
	while (scanf("%s %d",&p->name,&p->age) != EOF){//等于 eof 
		n++;
		p++;
		if (n==k) break;//或等于20 
	}
	q = p;
	p=students;
	for(i=1;i<=n;i++)
		for(j=0;j<n-i;j++)
			if(strcmp(p[j].name, p[j + 1].name)>0)
			{		
				temp=p[j];
   				p[j]= p[j+1];
   				p[j+1]= temp;//temp 的类型为 struct person 
			}else if(strcmp(p[j].name, p[j + 1].name) == 0){
				if( p[j].age > p[j+1].age){		
					temp=p[j];
   					p[j] = p[j+1];
   					p[j+1]= temp; 
				}
			}
	for (p=students;p<q;p++){
		printf("%s %d\n",p->name,p->age);
	}
	return 0;
}
