#include <stdio.h>
#include <stdlib.h>
#include<string.h>
 
int searchWord(char S[],char W[]);
char* replaceWord(char S[], char W[], int pos, char R[]);
 
int main(){
	char S[1000];
	char temp0[5]="Cao";
	char temp1[5]="Ling";
	char *result;

	int i=0,m;
	gets(S);
	while(i!=-1){
		i=searchWord(S,temp0);
		result = replaceWord(S,temp0,i,temp1);
		for(m=0;m<strlen(result);m++)
			S[m] = result[m];
		i=searchWord(S,temp0);
	}
	printf("%s",S);
	return 0;
}

int searchWord(char S[],char W[]){
	int i,j;				
	int n,k=3;		//k=length"cao			
	n=strlen(S)+1;
	for(i=0;i<n-k;i++){			
		for(j=0;j<k;j++){			
			if(S[i+j]!=W[j]){	
				break;
			}
		}
		if(j==k){		
				return i;
			}
		}
	return -1;
}
char* replaceWord(char S[], char W[], int pos, char R[]){
	int sizeS = strlen(S)+1;
	int sizeW = strlen(W);
	int sizeR = strlen(R);
	int size = sizeS - sizeW + sizeR;
	int i, j;
	char result[1500];	
	for(i=0;i<pos;i++){
		result[i] = S[i];
	}
	for(i=pos;i<pos+sizeR;i++){
		result[i] = R[i-pos];
	}
	for(pos+sizeR;i<size;i++){
		result[i]=S[i+sizeW-sizeR];
	}
	return result;
}
