#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **str1;//创建二维指针来指向数组
	int **str2;
	int i, j, k,temp;
	int x, y, z1,z2;

	scanf("%d %d", &x,&y);//str1行列数
	//二维数组动态内存申请
	str1 = (int **)malloc(sizeof(int*) * x);//行数
	if(str1==NULL){
		printf("-1");
		return 0;
	}
	for (i=0; i<x; i++){
		str1[i] = (int *)malloc(sizeof(int) * y);//列数
		if(str1[i]==NULL){
			printf("-1");
			return 0;
		}
	}
	
	//二维数组数据输入
	for (i=0; i<x; i++){
		for (j=0; j<y; j++){
			scanf("%d", &str1[i][j]);
		}
	}
	
 	scanf("%d %d", &z1,&z2);//str2行列数
	
	str2 = (int **)malloc(sizeof(int*) * z1);
	if(str2==NULL){
		printf("-1");
		return 0;
	}
	for (i=0; i<z1; i++){
		str2[i] = (int *)malloc(sizeof(int) * z2);
			if(str2[i]==NULL){
				printf("-1");
				return 0;
		}
	}
 
	for (i=0; i<z1; i++){
		for (j=0; j<z2; j++){
			scanf("%d", &str2[i][j]);
		}
	}
 
	if (y!=z1){
		printf("-1");
		goto t;
	} 

	for (i=0; i<x; i++){
		for (k=0; k<z2; k++){
			temp = 0;
			for (j=0; j<y; j++){
				temp += str1[i][j] * str2[j][k];
			}
			
			if (k == z2-1){
				printf("%d", temp);
			} 
			else{
				printf("%d ", temp);
			}
		}
		printf("\n");
	}

t:
	for (i=0; i<x; i++){
		free(str1[i]);//free一维指针
	}
	free(str1);//free二维指针
 
	for (i=0; i<z1; i++){
		free(str2[i]);
	}
	free(str2);
	return 0;
}
