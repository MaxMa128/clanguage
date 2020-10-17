#include<stdio.h>
#include<stdlib.h>
struct tnode{
	int key;
	struct tnode *left;
	struct tnode *right;
};

void Print_tree(struct tnode *p,int level);
struct tnode * add_tnode(struct tnode *p,int key);

int main()
{
	struct tnode *root = NULL;
	int key;

	while (scanf("%d",&key)!=EOF)
		root = add_tnode(root,key);
	Print_tree(root,0);
	return 0;
}
void Print_tree(struct tnode *p,int level)
{
	int i;
	if (p != NULL)
	{
		Print_tree(p->right,level+1);
		for(i = 0;i < level ;i++)
			printf("  ");
		printf("%4d\n",p->key);
		Print_tree(p->left,level+1);
	}
}

struct tnode * add_tnode(struct tnode* p,int key)
{
	if (p == NULL)
	{
		p = (struct tnode*)malloc(sizeof(struct tnode));
		p->key = key;
		p->left = NULL;
		p->right = NULL;
	}
	else if (key < p->key)
		p->left = add_tnode(p->left,key);
	else if (key > p->key)
		p->right = add_tnode(p->right,key);
	else ;
	return p;
}

