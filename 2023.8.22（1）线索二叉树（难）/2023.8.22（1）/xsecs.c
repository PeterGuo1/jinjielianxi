//线索二叉树
#include<stdio.h>
#include<stdlib.h>

typedef char elemtype;

typedef enum{link,thread} pointertag;//线索存储标志位：link（0）表示指向左右孩子的指针，thread（1）表示指向前驱后继的线索

typedef struct bithrnode
{
	char data;
	struct bithrnode *lchild,*rchild;
	pointertag ltag;
	pointertag rtag;
}bithrnode,*bithrtree;

//全局变量始终指向那个刚刚访问过的节点
bithrnode *pre;

//创建一个二叉树，约定用户遵照前序遍历的方式输入数据
int createbithrtree(bithrtree *T)
{
	char c;
	scanf("%c",c);
	if(' '==c)
	{
		*T=NULL;
	}
	else
	{
		*T=(bithrnode*)malloc(sizeof(bithrnode));
		(*T)->data=c;
		(*T)->ltag=link;
		(*T)->rtag=link;
		createbithrtree(&(*T)->lchild);
		createbithrtree(&(*T)->rchild);
	}
	return ;
}
//中序遍历线索化
int inthreading(bithrtree T)
{
	if(T)
	{
		inthreading(T->lchild );//递归左孩子线索化
		if(!T->lchild )  //如果没有左孩子，设置ltag为thread，并把lchild指向刚刚访问的节点
		{
			T->ltag =thread;
			T->lchild=pre;
		}
		if(!pre->rchild )
		{
			pre->rtag =thread;
			pre->rchild =T;
		}
		pre=T;
		inthreading(T->rchild );//递归右孩子线索化
	}
	return ;
}


int inorder(bithrtree *p,bithrtree T)
{
	*p=malloc(sizeof(bithrnode));
	(*p)->ltag=link;
	(*p)->rtag=thread;
	(*p)->rchild =*p;
	if(!T)
	{
		(*p)->lchild =*p;
	}
	else
	{
		(*p)->lchild=T;
		pre=*p;
		inthreading(T);
		pre->rchild=*p;
		pre->rtag =thread;
		(*p)->rchild =pre;
	}
	return ;
}

//中序遍历二叉树，非递归
void visit(char c)
{
	printf("%c",c);
}
void inordertra(bithrtree T)
{
	bithrtree p;
	p=T->lchild ;
	while(p!=T)
	{
		while(p->ltag==link)
		{
			p=p->lchild ;
		}
		visit(p->data );
		while(p->rtag ==thread&&p->rchild !=T)
		{
			p=p->rchild ;
			visit(p->data );
		}
		p=p->rchild ;
	}
}

int main()
{
	bithrtree p,T=NULL;
	createbithrtree(&T);
	inorder(&p,T);
	printf("中序遍历输出结果为：");
	inordertra(p);
	return 0;
}
