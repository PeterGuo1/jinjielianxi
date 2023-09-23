#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
       int data;
       struct TreeNode *left;
       struct TreeNode *right;
 };
typedef struct TreeNode node;
typedef node *btree;

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

void pre(btree ptr)
{
	if(ptr!=NULL)
	{
		pre(ptr->left);
		printf("[%2d]",ptr->data);
		pre(ptr->right);
	}
}
int main()
{
	int a[7]={12,56,11,53,35,69,7};
	int i;
	btree ptr,head;
	head=ptr=NULL;
	for(i=0;i<7;i++)
		ptr=creat_tree(ptr,a[i]);
	pre(ptr);
}


