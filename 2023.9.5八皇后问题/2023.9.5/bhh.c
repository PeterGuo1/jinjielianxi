#include <stdio.h>
int sum=0;
int chess[8][8]={0};
int check(int row,int col)
{
	int i,j;
	for (i = 0; i < 8; i++) //判断皇后所在列
	{
		if (chess[i][col] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) //判断左下对角线
	{
		if (chess[i][j] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j < 8; i--, j++) //判断右下对角线
	{
		if (chess[i][j] == 1)
			return 0;
	}
	return 1;
}


void print()
{
	int i,j;
	printf("第%d种情况\n",sum+1);
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
	printf("一共有%d种方法",sum);
	return 0;
}