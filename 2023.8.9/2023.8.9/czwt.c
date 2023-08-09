#include<stdio.h>
#include<stdlib.h>
/*int main()
{
	int bus[50] = {0};
	int up[50] = {0};
	int down[50] ={0};
	int n = 0;
	int x = 0;
	int i,j,k;
	scanf("%d %d %d %d",&j,&n,&k,&x);
	bus[1]=j;
	bus[2]=bus[1];
	up[1]=bus[1];
	while(bus[n]!=k)
	{
	up[2]=rand()%100+1;//运行时间太长
	down[2]=up[2];
	for(i=3;i<=n;i++)
	{
		
			
		up[i]=up[i-1]+up[i-2];
		down[i]=up[i-1];
		bus[i]=bus[i-1]+up[i]-down[i];
		if(i==n)
			bus[i]=bus[i-1];
	}
	}
	printf("%d",bus[x]);
	return 0;


}*/




int main() {
    int a, n, m, x, i, b;
	int a_s[25]={0}, b_s[25]={0};
	scanf("%d %d %d %d",&a,&n,&m,&x);//https://zhuanlan.zhihu.com/p/394774324
    a_s[2] = 1; a_s[3] = 2;
    for( i = 4; i < n; i++)
	{
        a_s[i] = a_s[i - 1] + a_s[i - 2] - 1;
        b_s[i] = b_s[i - 1] + b_s[i - 2] + 1;
    }
     b = (m - a * (a_s[n - 1])) /( b_s[n - 1]);
    printf("%d", a*a_s[x] + b*b_s[x]);
    return 0;
}