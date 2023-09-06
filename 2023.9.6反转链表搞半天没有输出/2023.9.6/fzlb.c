#include <stdio.h>
#include<stdlib.h>
struct ListNode 
{
 	int data;
 	struct ListNode *next;
};
typedef struct ListNode x ;
typedef x *linknode;
 

int main()
{
	int a[5]={1,2,3,4,0},i=0;
	linknode head,ptr,node,last,before;
	head=(linknode)malloc(sizeof(x));
	head->data =a[i];
	head->next=NULL;
	ptr=head;i++;
	while(a[i]!=0)
	{
		node=(linknode)malloc(sizeof(x));
	    node->data =a[i];
		node->next=NULL;
		ptr->next =node;
		ptr=ptr->next;
		i++;
	}
	ptr=head;
	before=NULL;
	while(ptr!=NULL);
	{
		last=before;
		before=ptr;
		ptr=ptr->next;
		before->next=last;
	}
	ptr=before;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
	return 0;
}