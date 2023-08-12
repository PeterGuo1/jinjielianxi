#include<stdio.h>
int arr[100];
int sz;
void push(int x)
{
	int count = 0;
	int i =1;
	for(i=30;i>0;i--)
		if(arr[i]!=0)
			count++;
	sz=count;
	if(arr[1]==0)
		arr[1]=x;
	else
		{
			arr[sz+1]=x;
	    }
}

int pop()
{
	if(arr[1]==0)
		printf("ERR_CANNOT_POP");
	else
	{
		int count = 0;
	    int i =1;
	    for(i=30;i>0;i--)
		if(arr[i]!=0)
			count++;
		for(i=1;i<=count;i++)
		{
			arr[i]=arr[i+1];
		}
	}

	return 0;
}

int query()
{
	if(arr[1]==0)
		printf("ERR_CANNOT_QUERY");
	else
		printf("%d\n",arr[1]);
	return 0;
}

int size()
{
	int count = 0;
	int i =1;
	for(i=30;i>0;i--)
		if(arr[i]!=0)
			count++;
	printf("%d\n",count);
	return 0;
}
int main()
{ 
	int n,i,k;
	scanf("%d",&n);
	for(i=n;i>0;i--)
	{
		scanf("%d",&k);
		switch(k)
		{
		case 1:
			int x;
			scanf("%d",&x);
			push(x);
			break;
		case 2:
			pop();
			break;
		case 3:
			query();
			break;
		case 4:
			size();
			break;
		}
	}
	return 0;
}