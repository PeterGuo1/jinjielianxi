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
void midorder(btree ptr)
{
	if(ptr!=NULL)
	{
		midorder(ptr->left);
		printf("[%2d]",ptr->data);
		midorder(ptr->right);
	}
}
btree inverttree(btree ptr)
{
	btree tmp=NULL;
	if(ptr==NULL)
		return ;
	tmp=ptr->left;
	ptr->left=ptr->right;
	ptr->right=tmp;
	inverttree(ptr->left);
	inverttree(ptr->right);


}
int main()
{
	int i,a[7]={53,12,54,43,35,23,36};
	btree ptr=NULL;
	for(i=0;i<7;i++)
		ptr=creat_tree(ptr,a[i]);
	midorder(ptr);
	printf("\n");
	inverttree(ptr);
	midorder(ptr);
}