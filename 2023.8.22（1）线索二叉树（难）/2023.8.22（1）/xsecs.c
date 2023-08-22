//����������
#include<stdio.h>
#include<stdlib.h>

typedef char elemtype;

typedef enum{link,thread} pointertag;//�����洢��־λ��link��0����ʾָ�����Һ��ӵ�ָ�룬thread��1����ʾָ��ǰ����̵�����

typedef struct bithrnode
{
	char data;
	struct bithrnode *lchild,*rchild;
	pointertag ltag;
	pointertag rtag;
}bithrnode,*bithrtree;

//ȫ�ֱ���ʼ��ָ���Ǹ��ոշ��ʹ��Ľڵ�
bithrnode *pre;

//����һ����������Լ���û�����ǰ������ķ�ʽ��������
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
//�������������
int inthreading(bithrtree T)
{
	if(T)
	{
		inthreading(T->lchild );//�ݹ�����������
		if(!T->lchild )  //���û�����ӣ�����ltagΪthread������lchildָ��ոշ��ʵĽڵ�
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
		inthreading(T->rchild );//�ݹ��Һ���������
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

//����������������ǵݹ�
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
	printf("�������������Ϊ��");
	inordertra(p);
	return 0;
}
