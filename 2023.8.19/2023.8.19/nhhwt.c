#include <stdio.h>//八皇后问题

//参数：row表示起始行
//参数n表示列数
//参数（*chess）[8]表示指向每一行的指针
int count=0;

int notdanger(int row,int j,int (*chess)[8])
{
	int i,k,flag=0;
	//判断列方向
	for(i=0;i<8;i++)
	{
		if(*(*(chess+i)+j)!=0)
		{
			flag=1;
			break;
		}
	}
	//判断左上方
	for(i=row,k=j;i>=0&&k>=0;i--,k--)
	{
		if(*(*(chess+i)+k)!=0)
		{
			flag=1;
			break;
		} 
	}
	//判断右下方
	for(i=row,k=j;i<8&&k<8;i++,k++)
	{
		if(*(*(chess+i)+k)!=0)
		{
			flag=1;
			break;
		} 
	}
	//判断右上方
	for(i=row,k=j;i>=0&&k<8;i--,k++)
	{
		if(*(*(chess+i)+k)!=0)
		{
			flag=1;
			break;
		} 
	}
	//判断左下方
	for(i=row,k=j;i<8&&k>=0;i++,k--)
	{
		if(*(*(chess+i)+k)!=0)
		{
			flag=1;
			break;
		} 
	}
	if(flag)
		return 0;
	else
		return 1;
	}
void eightqueen(int row,int n,int (*chess)[8])
{
	int chess2[8][8],i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			chess2[i][j]=chess[i][j];
		}
	}if(8==row)
	{
		printf("第%d种\n",count+1);
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				printf("%d",*(*(chess2+i)+j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else
	{
		//判断位置是否有危险
		//如果没有危险继续往下判断
		for(j=0;j<n;j++)
		{
			if(notdanger(row,j,chess))
			{
				for(i=0;i<8;i++)
				{
					*(*(chess2+row)+i)=0;
				}
				*(*(chess2+row)+j) = 1;
				eightqueen(row+1,n,chess2);
			}
			}
	}
}

int main()
{
	int chess[8][8],i,j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			chess[i][j]=0;
	eightqueen(0,8,chess);
	printf("总共有%d总解决方法",count);
	return 0;
}