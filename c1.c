#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main() {
	char* str,c;
	int i=0,j,k=0,n=0,s=0,x=0;
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
    while(str[i]!='\0'){
        if (str[i]>='a'&&str[i]<='z') s++;
         else if (str[i]>='A'&&str[i]<='Z') x++;
        i++;
    }
    printf("%d %d",s,x);
    free(str);
    return 0;
}
