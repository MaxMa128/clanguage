#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct lnode{
	char *st;
	struct Node *next;
};
struct lnode *creatlist(){
	struct lnode *headnode=(struct lnode*)malloc(sizeof(struct lnode));
	headnode -> next = NULL;
	return headnode;
}
struct lnode *creatnode(char *str){
	struct lnode *newnode=(struct lnode*)malloc(sizeof(struct lnode));	
	newnode -> st = str;
	newnode -> next = NULL;
	return newnode;
}
void insertnode(struct lnode*headnode,char *str){
	struct lnode *newnode = creatnode(str);
	newnode -> next = headnode ->next;
	headnode-> next = newnode;
} 
void deletenode(struct lnode*headnode,char *str){
	struct lnode* posnode = headnode->next;
	struct lnode* posnodefront = headnode;
	if (posnode==NULL)
		printf("Á´±í¿Õ\n");
	else
	{
		while(strcmp(posnode->st,str)!=0)
		{
			posnodefront = posnode;
			posnode = posnodefront->next;
			if(posnode==NULL)
			{
				printf("Ã»ÕÒµ½\n");
				return;
			}
		}
		posnodefront->next=posnode->next;
		free(posnode);
	}
}
void printlist(struct lnode *headnode){
	struct lnode *pmove = headnode->next;
	while(pmove)
	{
		printf("%s ",pmove->st);
		pmove = pmove -> next;
	}
	printf("\n");
}

int main()
{
	struct lnode *list = creatlist();
	int k=0,i=0;
	char *str,str1[20],c;
	gets(str1);
	str=(char*)malloc(sizeof(char));
	if (str == NULL) exit(1);
	while(scanf("%c",&c)!=EOF&&c!='\n'){
		str[k]=c;
		k++;
		str=(char*)realloc(str,(k+1)*sizeof(char));
		if(str==NULL){
			free(str);
			return 0;
			}
		if (c==" "){
			str[k]=0;
			insertnode(list,str);
			k = 0;
			str[0] = 0;
			free(str);
			str=(char*)malloc(sizeof(char));
		    if (str == NULL) exit(1);
		}
	}
	str[k]=" ";
	str[k+1]=0;
	insertnode(list,str);
	printlist(list);
	deletenode(list,str1);
	printlist(list);
	free(str);
	return 0;
}
