#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void remove_blank(char *ch)//去空格 
{
	char *c;//指向字符串的字符处
	while (*ch!=' '){
		if (*ch=='\0')
			return;
		ch++;
	}//ch指向第一个空格位置
	c=ch+1;//c指向空格后的一位 
	while (*c!='\0'){
		if (*c!=' '){
			*ch=*c;
			*c=' ';
			ch++;
		}//将空格换为后面出现的字符，换过去的字符置为空格
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
		}//去重复 
	}
	str[k]='\0';
	printf("%s",str);
	free(str);
	return 0;
}
