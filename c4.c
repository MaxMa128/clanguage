#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char *str,c;
	int i,count=0,max=0,id=0,k=0,m=0;
	str=(char*)malloc(sizeof(char));
	while(scanf("%c",&c)!=EOF&&c!='\n'){
		str[k]=c;
		k++;
		str=(char*)realloc(str,(k+1)*sizeof(char));
		if(str==NULL){
			free(str);
			return 0;
			}
	}
	str[k]=0;
	for(i=0;i<k;i++) 
		if (str[i]!=' ')
			count++;
		else {
			if((count==max)&&(max!=0))
				m=count;
			if (count>max){
				max=count;
				id=i-count;
			}
			count=0;
		}
	if((count==max)&&(max!=0))
		m=count;
	if(count>max){
		max=count;
		id=i-count;
	}//判断最后一个是不是 

	if (m!=max){
		for(i=id;i<id+max;i++)
			printf("%c",str[i]);
	}
	free(str);
	return 0;
}
