#include<stdio.h>
#include<string.h>
char * deblank(char * str);
int main()
{
    char str[1001];
	char *a,c;
    int i,k=0,n=0;
   	while(scanf("%c",&c)!=EOF&&c!='\n'){
		str[n]=c;
		n++;
	}
	str[n]=0;
	a = deblank(str);
    for (i = 0; i < strlen(a); i++)
    	if (*(a+i)!=' ') {
    		k=i;
    		break;
		}
    for (i = k; i < strlen(a); i++)
        	printf("%c",*(a+i));//输出
    return 0;
}

char * deblank(char * str)
{
    char * left = str;//left负责赋值
    char * right = str;//right寻找非空格字符的指针
    while (*right)
    {
        if (*right != ' ')
        {
            if (left<right)
                *left = *right;//赋值
            left++;
        }
        if (*right == ' '&&*(right + 1) != ' ')//寻找到下一个单词时，对left的操作
        {
            *left = ' ';
            left++;
        }
        right++;
    }
    *left = '\0';
    return str;
}
