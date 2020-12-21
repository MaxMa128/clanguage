#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
struct lnode* add_first(struct lnode *cur,char *buf){//去掉 if 是按大小排列 
	struct lnode *new = NULL;
//	if(cur==NULL)
//	{
//		new=(struct lnode*)malloc(sizeof(struct lnode));
//		if(!new) return NULL;
//		strcpy(new->str,buf);
//		new->next = NULL;
//		new->prev = NULL;
//		return new;
//	}//fanxiangshuchu
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

}// jia yuansu
void Freelist(struct lnode* cur){
	while(cur)
	{
		struct lnode* next = cur ->next;
		free(cur);
		cur = next;
	}
}

int main()
{
	struct lnode *head = NULL;
	char buf[20];
	scanf("%19s",buf);
//	head = (struct lnode*)malloc(sizeof(struct lnode));
//	if (!head) exit(1);
//	strcpy(head->str,buf);
//	head->next = NULL;
//	head->prev = NULL;
//	Print_list(head);
	while(scanf("%19s",buf)!=EOF){
		struct lnode*cur = add_first(head,buf);
		if(cur)head=cur;
	}//fanxiang yongde
	insert(head,"new_element");//jiayuansu
	Print_list(head);
	Freelist(head);//void freelist
//	free(head);
	return 0;
}

