#include<stdio.h>
#include<stdlib.h>

void Btree_create(int *btree,int *data,int length)
{
	int i,level;
	for(i=1;i<length;i++)
	{
		for(level=1;btree[level]!=0;)
		{
			if(data[i]>btree[level])
				level=level*2+1;
			else
				level=level*2;
		}
		btree[level]=data[i];
	}
}

int main()
{
	int i,length=9;
	int data[]={0,6,3,5,4,7,8,9,2};
	int btree[16]={0};
	printf("ԭʼ���������:\n");
	for(i=0;i<length;i++)
		printf("[%2d]",data[i]);
	printf("\n");
	Btree_create(btree,data,9);
	printf("������������:\n");
	for(i=1;i<16;i++)
		printf("[%2d]",btree[i]);
	printf("\n");
	system("pause");
	return 0;
}