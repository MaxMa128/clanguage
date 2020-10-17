#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char* str,c;
	char *b;
	int i,j,k=0,n=0;
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
	for (i=0;i<k;i++){ // count uppercase letter
		if (str[i]>='A'&&str[i]<='Z')
			n++;
	}
	for (i=0;i<n;i++){ 
		for(j=0;j<k;j++){
			if (str[j]>='A'&&str[j]<='Z'){
				if(str[j+1]!=0){
					c=str[j];
					str[j]=str[j+1];
					str[j+1]=c;
				}else break;
			}
		}
	} 
	printf("%s",str);
	free(str);
	return 0;
}
