#include<stdio.h>  
#include<string.h>  
int main(void){  
char a[20200],b[101],maxT[101]="",minT[101]="";  
int i=0,j=0;  
int max=-1,min=101,newLen;  
int f=0;  //f=0��ʾ��ǰ�����ķָ������ո�򶺺ţ����µ���ǰ�ķָ���  
  
gets(a);  
while(a[i]!='\0'){  //ɨ��a������һ���µĵ��ʣ�Ȼ����䳤�ȣ�����max,min�Ա�  
if(a[i]=='.'){  
if(f==1){   //f=1��ʾ��ǰ�����ķָ���ǰ����һ���ո�ɨ���γɵĵ���  
b[j]='\0';  
newLen=strlen(b);  
if(newLen>max) {  
max=newLen;  
strcpy(maxT,b);  
}  
if(newLen<min){  
min=newLen;  
strcpy(minT,b);  
}  
f=0;  
j=0;  
}  
}  
else{  
b[j]=a[i];  
j++;  
f=1;  //��ʼ�������ڹ���һ������  
}  
i++;  
}  
//����ĩβ����  
b[j]='\0';  
newLen=strlen(b);  
if(newLen>max) {  
max=newLen;  
strcpy(maxT,b);  
}  
if(newLen<min){  
min=newLen;  
strcpy(minT,b);  
}  
printf("%s\n%s\n",maxT,minT);  
return 0;  
}  
