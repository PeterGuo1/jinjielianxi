#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left,*right;
};
typedef struct tree node;
typedef node *btree;
void inorder(btree ptr)//中序遍历
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("[%2d]",ptr->data);
		inorder(ptr->right );
	}
}

btree creat_tree(btree root,int val)
{
	btree newnode,current,backup;
	newnode=(btree)malloc(sizeof(node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	else
	{
		for(current=root;current!=NULL;)
		{
			backup=current;
			if(current->data>val)
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data>val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}


btree search(btree ptr,int val)
{
	while(1)
	{
		if(ptr==NULL)
			return NULL;
		if(ptr->data ==val)
			return ptr;
		else if(ptr->data>val)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
}
btree del(btree ptr,int val)
{
	btree tmp,before,t;
	if(search(ptr,val)==NULL)
	{
		printf("你要删除的数据不存在\n");
		return ptr;
	}
	else
	{
		t=search(ptr,val);
		tmp=t;
		tmp=tmp->left;before=NULL;
	while(tmp->right!=NULL&&tmp!=NULL)
	{
		before=tmp;
		tmp=tmp->right;
	}
	t->data=tmp->data;
	before->right=NULL;
	return ptr;
	
	}
}
int main()
{
	int i,x,data[]={5,6,24,8,12,3,17,1,9};
	btree ptr=NULL;
	btree root=NULL;
	for(i=0;i<9;i++)
		ptr=creat_tree(ptr,data[i]);
	printf("=========================\n");
	printf("排序完成的结果:\n");
	del(ptr,5);
	inorder(ptr);
	printf("\n");
	system("pause");
	return 0;
}