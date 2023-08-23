#include<stdio.h>
//杨辉三角





/*int main()
{
	int arr[10][10] = {0};
	int i = 0;
	int j = 0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(j == 0)
				arr[i][j]=1;
			if(i == j)
				arr[i][j]=1;
			if(i>=2&&j>=1)
			{
				arr[i][j] =arr[i-1][j]+arr[i-1][j-1];
			}
		}
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
	}*/
			
//猜凶手
//杀人凶手为四个人中的一个
//A说：不是我
//B说：是c
//C说：是D
//D说：c在胡说
/*int main()
{
	int killer = 0;
	for(killer = 'a';killer <='d';killer++)
	{   if((killer !='a')+(killer == 'c')+(killer =='d')+(killer !='d') == 3)
	{
		   printf("killer = %c\n", killer);
	}
	}
	return 0;
}*/

//赛马问题：三十六匹马，六个跑道，没有计时器，请确定比赛的前三名，请问最少比赛几次
//先赛六次，得到六个第一名，然后六个第一名赛一次，得到前三名，第二和但三名在一起和第一名的二三号选手赛一次决出第二和第三名。
//烧香问题：一种香，质地不均匀，但没根都可以烧一个小时，给你两根香，确定一个15分钟的时间段
//第一根香两头同时点，半个小时燃尽，在第一根香点燃的同时，将第二根一端点燃，等第一根半个小时燃尽后，将第二根另一端也点燃即可确定十五分钟时间段。

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for(a=1;a<=5;a++)
	{
		for(b=1;b<=5;b++)
		{
			for(c=1;c<=5;c++)
			{
				for(d=1;d<=5;d++)
				{
					for(e=1;e<=5;e++)
					{
						if(((b==2)+(a==3)==1)&&
						   ((b==2)+(e==4)==1)&&
						   ((c==1)+(d==2)==1)&&
						   ((c==5)+(d==3)==1)&&
						   ((e==4)+(a==1)==1)&&
						   a*b*c*d*e==120)
						{
							printf("a=%d b=%d c=%d d=%d e=%d", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
	return 0;
}
		
