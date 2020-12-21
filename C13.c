#include<stdio.h>
#include<stdlib.h>
struct tnode{
	int key;
	struct tnode *left;
	struct tnode *right;
};

int Min1_tree(struct tnode *p);
int Min2_tree(struct tnode *p,int min2);
struct tnode * add_tnode(struct tnode *p,int key);
void FreeTree(struct tnode *p);

int main()
{
	int a,b;
	struct tnode *root = NULL;
	int key;
	while (scanf("%d",&key)!=EOF)
		root = add_tnode(root,key);
	b = Min2_tree(root,0);
	a = Min1_tree(root);
	printf("%d %d",a,b);
	FreeTree(root);
	return 0;
}

int Min1_tree(struct tnode *p)
{
	if(p->left == NULL && p->right == NULL) 
		return p->key;
	if(p->left == NULL && p->right != NULL)
		return p->key;
	if(p->left != NULL)
		Min1_tree(p->left);
}

int Min2_tree(struct tnode *p,int min2)
{
	if(p->left == NULL && p->right == NULL) 
		return min2;
	if(p->left == NULL && p->right != NULL){
		if(p->right->left == NULL) 
			return p->right->key;
		else {
			p = p->right;	
			while (p->left)
				p = p->left;
			return p->key;
		}
		
	}
	if(p->left != NULL){
		min2 = p->key;
		Min2_tree(p->left,min2);
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
	return p;
}

void FreeTree(struct tnode *p)
 {
 	if (p->left) FreeTree(p->left);
 	if (p->right) FreeTree(p->right);
 	free(p);
 }
