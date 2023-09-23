#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
	 newnode->data =val;
	 newnode->left=NULL;
	 newnode->right=NULL;
	 if(root==NULL)
		 root=newnode;
	 else
		 for(current=root;current!=NULL;)
		 {
			 backup=current;
			 if(current->data >val)
				 current=current->left;
			 else
				 current=current->right;
		 }
		 if(backup->data>val)
			 backup->left=newnode;
		 else
			 backup->right=newnode;

 }
 void midoreder(btree ptr)
 {
	 if(ptr!=NULL)
	 {
		 midoreder(ptr->left);
		 printf("[%2d]",ptr->data);
		 midoreder(ptr->right);
	 }
 }
 int max(int a,int b)
 {
	 return a>=b?a:b;
 }
 int maxdepth(btree ptr)
 {
	  if (ptr==NULL) return 0;
        return max(maxdepth(ptr->left), maxdepth(ptr->right)) + 1;


 }

 int main()
 {
	 int a[7]={37,12,45,36,25,89,65},i,x;
	 btree tree;
	 tree=NULL;
	 for(i=0;i<7;i++)
		 creat_tree(tree,a[i]);
	 x=maxdepth(tree);
	 printf("%d",x);
 }