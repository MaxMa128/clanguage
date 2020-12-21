#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//�ַ��������һ������ 
struct lnode{
	char str[20];
	struct lnode* next;
	struct lnode* prev;
};

void Print_list(struct lnode* cur){
	while(cur)
	{
		printf("%s ",cur->str);
		cur = cur->next;
	}
	printf("\n");
}

struct lnode* add_first(struct lnode *cur,char *buf){//ȥ�� if �ǰ���С����
	struct lnode *new = NULL;
	if(cur==NULL)
	{
		new=(struct lnode*)malloc(sizeof(struct lnode));
		if(!new) return NULL;
		strcpy(new->str,buf);
		new->next = NULL;
		new->prev = NULL;
		return new;
	}//�������
	while(cur->prev)
		cur = cur -> prev;
	new = (struct lnode*)malloc(sizeof(struct lnode));
	if (!new) return NULL;
	strcpy(new->str,buf);
	new->next = cur;
	new->prev = NULL;
	cur->prev = new;
	return new;
};

int add_end(struct lnode* cur,char* str){
	struct lnode* new = NULL;
	while (cur ->next)
		cur = cur -> next;
	new = (struct lnode*)malloc(sizeof(struct lnode));
	if(!new) return 1;
	strcpy(new -> str,str);
	cur -> next = new;
	new -> prev = cur;
	new -> next = NULL;
	return 0;
}

int insert(struct lnode *cur,char *buf){
	struct lnode *new;
	if(cur == NULL)
		return -1;
	new = (struct lnode*)malloc(sizeof(struct lnode));
	if (!new) return 1;
	strcpy(new->str,buf);
	new->prev =cur;
	new->next = cur->next;
	cur->next->prev = new;
	cur->next = new;
	return 0;
}// ��Ԫ�� 

void Freelist(struct lnode* cur){
	while(cur)
	{
		struct lnode* next = cur ->next;
		free(cur);
		cur = next;
	}
}//�ͷ�
 
int main()
{
	struct lnode *head = NULL;
	char buf[20];
	scanf("%19s",buf);
	head = (struct lnode*)malloc(sizeof(struct lnode));
	if (!head) exit(1);
	strcpy(head->str,buf);
	head->next = NULL;
	head->prev = NULL;
	Print_list(head);
	while(scanf("%19s",buf)!=EOF){
//		struct lnode*cur = add_first(head,buf);
//		if(cur)head=cur;
		if (add_end(head,buf))
			return 1;
	}//fanxiang yongde
//	insert(head,"new_element");//jiayuansu
	Print_list(head);
	Freelist(head);//�ͷ� 
	free(head);
	return 0;
}

