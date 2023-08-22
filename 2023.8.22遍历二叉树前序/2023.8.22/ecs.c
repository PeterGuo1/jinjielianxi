#include <stdio.h>
#include <stdlib.h>
typedef char elemtype
typedef struct bitnode
{
	elemtype data;
	struct bitnode *lchild,*rchild;
}bitnode,*bitree;

//创建一颗二叉树,约定按照前序遍历的方式输入数据
void createbitree(bitree *T)
{
	char c;
	scanf("%c",c);
	if(' '==c)
	{
		*T=NULL;
	}
	else
	{
		*T=malloc(sizeof(bitnode));
		(*T)->data=c;
		createbitree(&(*T)->lchild);
		createbitree(&(*T)->rchild);
	}
}


//访问二叉树结点的具体操作，你想干嘛？

void visit(char c,int level)
{
	printf("%c位于第%d层\n",c,level);
}

//遍历二叉树
void preorder(bitree T,int level)
{
	if(T)
	{
		visit(T->data,level);
		preorder(T->lchild,level+1);
		preorder(T->rchild,level+1);
	}
}
int main()
{
	int level = 1;
	bitree T = NULL;
	createbitree(&T);
	preorder(T,level);
	return 0;
}