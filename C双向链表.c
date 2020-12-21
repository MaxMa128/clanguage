#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct lnode{
	char str[20];
	struct lnode* prev;
	struct lnode* next;
};
//创表头
struct lnode* createlist()
{
	struct lnode* headnode = (struct lnode *)malloc(sizeof(struct lnode));
	headnode->prev=headnode->next=headnode;//初始化，指向自身 
	return headnode;
}
//创插入节点
struct lnode* createnode(char* str)
{
	struct lnode* newnode = (struct lnode*)malloc(sizeof(struct lnode));
	strcpy(newnode->str,str);
	newnode->prev=newnode->next=NULL;;
	return newnode;
} 
//表头插入 
void add_first(struct lnode*headnode,char* str)
{
	struct lnode* newnode = createnode(str);
	newnode->prev = headnode;
	newnode->next = headnode->next;
	headnode->next->prev = newnode;
	headnode->next = newnode;
}
//表尾插入
void add_end(struct lnode*headnode,char* str)
{
	struct lnode* newnode = createnode(str);
	struct lnode* lastnode = headnode;
	while(lastnode->next!=headnode)
	{
		lastnode = lastnode->next;
	}
	headnode->prev=newnode;
	newnode->next=headnode;
	lastnode->next=newnode;
	newnode->prev=lastnode;
}
//删除指定
void deletenode(struct lnode* headnode,char* posstr)
{
	struct lnode* posnode = headnode->next;
	struct lnode* posnodefront = headnode;
	while(strcmp(posnode->str,posstr)!=0)
	{
		posnodefront = posnode;
		posnode = posnodefront->next;
		if(posnode->next == headnode)
		{
			printf("不存在\n");
			return;
		}
	}
	posnodefront->next = posnode -> next;
	posnode->next->prev = posnodefront;
	free(posnode);
 } 
//输出 
void printlist(struct lnode* headnode)
{
	struct lnode* pmove = headnode->next;
	while(pmove!=headnode)//用pmove->tail会少一个 
	{
		printf("%s ",pmove->str);
		pmove = pmove->next;
	}
	printf("\n");
}
int main()
{
	struct lnode* list = createlist();
	add_first(list,"a");
	add_first(list,"b");
	printlist(list);
	add_end(list,"d");
	deletenode(list,"b");
	printlist(list);
	return 0;
}
