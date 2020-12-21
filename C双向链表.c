#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct lnode{
	char str[20];
	struct lnode* prev;
	struct lnode* next;
};
//����ͷ
struct lnode* createlist()
{
	struct lnode* headnode = (struct lnode *)malloc(sizeof(struct lnode));
	headnode->prev=headnode->next=headnode;//��ʼ����ָ������ 
	return headnode;
}
//������ڵ�
struct lnode* createnode(char* str)
{
	struct lnode* newnode = (struct lnode*)malloc(sizeof(struct lnode));
	strcpy(newnode->str,str);
	newnode->prev=newnode->next=NULL;;
	return newnode;
} 
//��ͷ���� 
void add_first(struct lnode*headnode,char* str)
{
	struct lnode* newnode = createnode(str);
	newnode->prev = headnode;
	newnode->next = headnode->next;
	headnode->next->prev = newnode;
	headnode->next = newnode;
}
//��β����
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
//ɾ��ָ��
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
			printf("������\n");
			return;
		}
	}
	posnodefront->next = posnode -> next;
	posnode->next->prev = posnodefront;
	free(posnode);
 } 
//��� 
void printlist(struct lnode* headnode)
{
	struct lnode* pmove = headnode->next;
	while(pmove!=headnode)//��pmove->tail����һ�� 
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
