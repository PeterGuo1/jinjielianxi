#include<stdio.h>//汉诺塔

void move(int n,char x,char y,char z)//将n个盘子借助y移动到z上
{
	if(1==n)
	{
		printf("%c-->%c\n",x,z);
	}
	else
	{
		move(n-1,x,z,y);//将n-1个盘子从x借助z移动到y上
		printf("%c-->%c",x,z);//将第n个盘子从x移到z上
		move(n-1,y,x,z);//将n-1个盘子从y借助x移动到z上
	}
}
int main()
{
	int n;char x,y,z;
	printf("请输入汉诺塔的层数:");
	printf("%d",&n);
	printf("移动的步骤如下:\n");
	move(n,x,y,z);
	return 0;
}
