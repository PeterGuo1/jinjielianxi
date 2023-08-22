#include <stdio.h>
#include <stdlib.h>
typedef char elemtype
typedef struct bitnode
{
	elemtype data;
	struct bitnode *lchild,*rchild;
}bitnode,*bitree;

//����һ�Ŷ�����,Լ������ǰ������ķ�ʽ��������
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


//���ʶ��������ľ��������������

void visit(char c,int level)
{
	printf("%cλ�ڵ�%d��\n",c,level);
}

//����������
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