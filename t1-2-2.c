#include<stdio.h>  
#include<string.h>  
int main(void){  
char a[20200],b[101],maxT[101]="",minT[101]="";  
int i=0,j=0;  
int max=-1,min=101,newLen;  
int f=0;  //f=0表示当前遇到的分隔符（空格或逗号）是新单词前的分隔符  
  
gets(a);  
while(a[i]!='\0'){  //扫描a串生成一个新的单词，然后测其长度，再与max,min对比  
if(a[i]=='.'){  
if(f==1){   //f=1表示当前遇到的分隔符前面有一个刚刚扫描形成的单词  
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
f=1;  //开始或是正在构造一个单词  
}  
i++;  
}  
//处理末尾单词  
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
