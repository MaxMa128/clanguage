#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void remove_blank(char *ch)//ȥ�ո� 
{
	char *c;//ָ���ַ������ַ���
	while (*ch!=' '){
		if (*ch=='\0')
			return;
		ch++;
	}//chָ���һ���ո�λ��
	c=ch+1;//cָ��ո���һλ 
	while (*c!='\0'){
		if (*c!=' '){
			*ch=*c;
			*c=' ';
			ch++;
		}//���ո�Ϊ������ֵ��ַ�������ȥ���ַ���Ϊ�ո�
		c++;
	}
	*ch = '\0';
	return;
}

int main()
{
	char* str,c;
	int i,j,s,k=0;
	str=(char*)malloc(sizeof(char));
	while(scanf("%c",&c)!=EOF&&c!='\n'){
		str[k]=c;
		k++;
		str=(char*)realloc(str,(k+1)*sizeof(char));
		if (str==NULL){
			free(str);
			return 0;
		}	
	}
	str[k]=0; 
	remove_blank(str);
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(str[i]==str[j]){
				for(s=j;s<k;s++){
					str[s]=str[s+1];
			 	}
				k--;
				j--; 
			}
		}//ȥ�ظ� 
	}
	str[k]='\0';
	printf("%s",str);
	free(str);
	return 0;
}
