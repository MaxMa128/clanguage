#include<stdio.h>
#include<stdlib.h>
//只在linux上
// 输入 ./a.out 判断数 换行 输入树 再ctrl D 
struct tnode{
	int key;
	struct tnode *left;
	struct tnode *right;
};
void Print_tree(struct tnode *p,int level);
struct tnode * add_tnode(struct tnode *p,int key);
void FreeTree(struct tnode *p);
int SearchTree(struct tnode *p,int key);
int main(int argc,char **argv)
{
	struct tnode *root = NULL;
	int key,skey;
	while (scanf("%d",&key)!=EOF)
		root = add_tnode(root,key);
	Print_tree(root,0);
	if (argc<2)
	{
		printf("i need key\n");
		FreeTree(root);
		return -1;
	}
	skey = atoi(argv[1]);
	if(SearchTree(root,skey))
		printf("YES\n");
	else 
		printf("NO\n");
	FreeTree(root);
	return 0;
}
int SearchTree(struct tnode *p,int key)
{
	if (p == NULL)
		return 0;
	else if(p->key==key)
		return 1;
	else if(key > p->key)
		return SearchTree(p->right,key);
	else
		return SearchTree(p->left,key);
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
	
void FreeTree(struct tnode *p)
{
	if (p->left) FreeTree(p->left);
	if (p->right) FreeTree(p->right);
	free(p);
}

