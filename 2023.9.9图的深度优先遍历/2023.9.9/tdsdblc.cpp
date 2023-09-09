#include<stdio.h>
#include<stdlib.h>

struct list
{
	int val;
	struct list *next;
};
typedef struct list node;
typedef node *link;
struct list* head[9];
int run[9];

void dfs(int current)
{
	link ptr;
	run[current]=1;
	printf("[%d]",current);
	ptr=head[current]->next;
	while(ptr!=NULL)
	{
		if(run[ptr->val ]==0)
			dfs(ptr->val);
		ptr=ptr->next;
	}
}

int main()
{
	link ptr,newnode;
	int data[20][2]={{1,2},{2,1},{1,3},{3,1},
	                 {2,4},{4,2},{2,5},{5,2},
	                 {3,6},{6,3},{3,7},{7,3},
	                 {6,8},{8,6},{8,7},{7,8}};
	int i,j;
	for(i=1;i<=8;i++)
	{
		run[i]=0;
		head[i]=(link)malloc(sizeof(node));
		head[i]->val=i;
		head[i]->next=NULL;
		ptr=head[i];
		for(j=0;j<20;j++)
		{
			if(data[j][0]==i)
			{
				newnode=(link)malloc(sizeof(node));
				newnode->val=data[j][1];
				newnode->next=NULL;
				do
				{
					ptr->next=newnode;
					ptr=ptr->next;
				}while(ptr->next!=NULL);
			}
		}
	}
	printf("图的邻表接内容：\n");
		for(i=1;i<=8;i++)
		{
			ptr=head[i];
			printf("顶点 %d=> ",i);
			ptr=ptr->next;
			while(ptr!=NULL)
			{
				printf("[%d]",ptr->val);
				ptr=ptr->next;
			}
			printf("\n");
		}
		printf("深度优先遍历的顶点:\n");
		dfs(1);
		printf("\n");
		system("pause");
		return 0;
}