#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Student{
	char name[20]; 
	int age; 
};
void scanf1(struct Student *stu){
	printf("请输入姓名 年龄\n");
	scanf("%s %d",&stu->name,&stu->age); 
}
int main()
{
	struct Student students[20];
	struct Student *p = students,*q = 0;
	struct Student temp;
	int n = 0,i,j;
	while (1){
		scanf1(p);
		if (p->age<0) break;
		n++;
		p++;
	}
	printf("%d\n",n);
	q = p;
	p=students;
	for(i=1;i<=n;i++)
		for(j=0;j<=n-i-1;j++)
			if( (p+j)->name < (p+j+1)->name)
			{		
				temp=*(p+j);
   				*(p+j) = *(p+j+1);
   				*(p+j+1)= temp;//注意 temp 的类型为Student 
			}else if( (p+j)->name == (p+j+1)->name){
				if( (p+j)->age < (p+j+1)->age)
			{		
				temp=*(p+j);
   				*(p+j) = *(p+j+1);
   				*(p+j+1)= temp;//注意 temp 的类型为Student 
			}
			}

	for (p=students;p<q;p++){
		printf("%s\t%d\n",p->name,p->age);
	}
	return 0;
}
