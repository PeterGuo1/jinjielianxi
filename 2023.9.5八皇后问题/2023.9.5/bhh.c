#include <stdio.h>
int sum=0;
int chess[8][8]={0};
int check(int row,int col)
{
	int i,j;
	for (i = 0; i < 8; i++) //�жϻʺ�������
	{
		if (chess[i][col] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) //�ж����¶Խ���
	{
		if (chess[i][j] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j < 8; i--, j++) //�ж����¶Խ���
	{
		if (chess[i][j] == 1)
			return 0;
	}
	return 1;
}


void print()
{
	int i,j;
	printf("��%d�����\n",sum+1);
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(chess[i][j]==1)
			     printf("Q");
			else
			     printf("#");
		}
		printf("\n");
	}
	printf("\n");
}

void search(int row)
{
	int col;
	if(row==8)
	{
		print();
		sum++;
		return;
	}
	for(col=0;col<8;col++)
	{
		if(check(row,col))
		{
			chess[row][col]=1;
            search(row+1);
			chess[row][col]=0;
		}
	}
}

int main()
{
	search(0);
	printf("һ����%d�ַ���",sum);
	return 0;
}