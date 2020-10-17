#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main()
{
	char* str,c;
	int k=0;
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
 	
	free(str);
 	return 0;
}
