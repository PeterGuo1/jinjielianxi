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
/*
void inorder(btree ptr)//前序遍历
{
    if(ptr!=NULL)
	{
	    printf("[%2d]",ptr->data);
		inorder(ptr->left);
		inorder(ptr->right );
	}
}
void inorder(btree ptr)//后序遍历
{
    if(ptr!=NULL)
	{
		inorder(ptr->left);
		inorder(ptr->right );
		printf("[%2d]",ptr->data);
	}
}

*/
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

int main()
{
	int i,data[]={5,6,24,8,12,3,17,1,9};
	btree ptr=NULL;
	btree root=NULL;
	for(i=0;i<9;i++)
		ptr=creat_tree(ptr,data[i]);
	printf("=========================\n");
	printf("排序完成的结果:\n");
	inorder(ptr);
	printf("\n");
	system("pause");
	return 0;
}
