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
	if(!headnode) return NULL;
	headnode->prev=headnode->next=headnode;//��ʼ����ָ������ 
	return headnode;
}
//������ڵ�
struct lnode* createnode(char* str)
{
	struct lnode* newnode = (struct lnode*)malloc(sizeof(struct lnode));
	if(!newnode) return NULL;
	strcpy(newnode->str,str);
	newnode->prev=newnode->next=NULL;;
	return newnode;
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

//��� 
void printlist(struct lnode* headnode)
{
	struct lnode* pmove = headnode->next;
	while(pmove!=headnode)//��pmove->next����һ�� 
	{
		printf("%s\n",pmove->str);
		pmove = pmove->next;
	}
	printf("\n");
}
//free
void freememory(struct lnode *headnode)  
{  
    struct lnode* pt = NULL;  
    while (headnode != NULL)  
    {  
        pt = headnode->next->next;  
        if (headnode->next == headnode)  
        {  
            free(headnode);  
            headnode = NULL;  
        }  
        else  
        {  
            free(headnode->next);  
            headnode->next = pt;  
            pt->prev = headnode;  
        }  
    }  
}  
int main()
{
	struct lnode* list = createlist();
	char str[20],str0[20],ch[20],c;
	int n=0;
	while(scanf("%c",&c)!=EOF&&c!='.')
	{
		
		if(c==' '){
			str[n]=0;
			add_end(list,str);
			n=0;
			strcpy(str,str0);
		}else {
			str[n]=c;
			n++;
		}
	}
	if (list!=NULL){
			str[n]=0;
			add_end(list,str);
		}
	printlist(list);
	freememory(list);
	return 0;
}
