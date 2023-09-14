#include<stdio.h>
#include<stdlib.h>
struct listnode
{
	int num;
	struct listnode* next;
};
typedef struct listnode node;
typedef node* link;

int main()
{
	link head,ptr,tmp;
	int n,k,x,y1,y2,max=0;
	scanf("%d",&n);
	k=n-1;
	scanf("%d",&x);
	head=(link)malloc(sizeof(node));
	head->num=x;
	head->next=NULL;
	ptr=head;
	do
	{
		tmp=(link)malloc(sizeof(node));
		scanf("%d",&x);
		tmp->num=x;
		tmp->next=NULL;
		ptr->next=tmp;
		ptr=ptr->next;
		k--;
	}while(k);
	n=n/2;
	do
	{
		ptr=head;
		head=head->next;
		y1=ptr->num;
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;
		}
		y2=ptr->next->num;
		ptr->next=NULL;
		if(y1+y2>max)
			max=y1+y2;
		
		n--;
	}while(n);
	printf("%d",max);
	


	return 0;
}
