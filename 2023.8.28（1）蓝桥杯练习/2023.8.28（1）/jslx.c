

/*小强从小就喜欢生命科学，他总是好奇花草鸟兽从哪里来的。终于， 小强上中学了，接触到了神圣的名词--DNA.它有一个双螺旋的结构。这让一根筋的小强抓破头皮，“要是能画出来就好了” 小强喊道。现在就请你帮助他吧

输入

输入包含多组测试数据。第一个整数N（N<=15）,N表示组数，每组数据包含两个整数a,b。a表示一个单位的DNA串的行数，a为奇数且 3<=a<=39。b表示重复度(1<=b<=20)。

输出

输出DNA的形状，每组输出间有一空行。

样例输入

2
3 1
5 4
样例输出

X X
 X
X X

X   X
 X X
  X
 X X
X   X
 X X
  X
 X X
X   X
 X X
  X
 X X
X   X
 X X
  X
 X X
X   X
*/
#include<stdio.h>
int main()
{
	int a,b,n,i,j,k;
	scanf("%d",&n);
	while(n--)
	{
		int f=0;
		scanf("%d%d",&a,&b);
		for(i=0;i<b;i++)
		{
			for(j=0;j<a;j++)
			{
				if(f==0||j!=0)
				{
					for(k=0;k<a;k++)
					{
						if(j==k||j==a-k-1)
						{
							printf("X");
						}
						else
						printf(" ");
						f=1;
					}
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}

