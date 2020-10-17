#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main()
{
	char* str,c;
	int* arr,k=0,i,j,n,m=0,s=0,tem;
	str=(char*)malloc(sizeof(char));
	arr=(int*)malloc(sizeof(int));
	while(scanf("%c",&c)!=EOF&&c!='\n'){
		str[k]=c;
		k++;
		str=(char*)realloc(str,(k+1)*sizeof(char));
		if(str==NULL){
			free(str);
			return 0;
			}
	}//字符串分配动态内存； 
	str[k]=0;
	for(i=0;i<k;i++){
		if(str[i]>='0'&&str[i]<='9'){
			while(str[i]>='0'&&str[i]<='9'){
				n=str[i]-'0';
				s=s*10+n;
				if(str[i+1]>='0'&&str[i+1]<='9')
					i++;
				else break;
			}
		arr[m]=s;
		m++; 
		arr=(int*)realloc(arr,(m+1)*sizeof(int));
		if(arr==NULL){
			free(arr);
			return 0;
		}//分配arr内存 
		s=0;
		n=0;
		}
	} 
	for (i=0;i<m-1;i++)
		for(j=0;j<m-1;j++)
			if (arr[j]>arr[j+1]){
                tem=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=tem;
            }//比较大小 
	for (i=0;i<m;i++)
		printf("%d ",arr[i]);
	free(arr); 
 	free(str);
 	return 0;
}
