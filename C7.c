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
        	printf("%c",*(a+i));//���
    return 0;
}

char * deblank(char * str)
{
    char * left = str;//left����ֵ
    char * right = str;//rightѰ�ҷǿո��ַ���ָ��
    while (*right)
    {
        if (*right != ' ')
        {
            if (left<right)
                *left = *right;//��ֵ
            left++;
        }
        if (*right == ' '&&*(right + 1) != ' ')//Ѱ�ҵ���һ������ʱ����left�Ĳ���
        {
            *left = ' ';
            left++;
        }
        right++;
    }
    *left = '\0';
    return str;
}
