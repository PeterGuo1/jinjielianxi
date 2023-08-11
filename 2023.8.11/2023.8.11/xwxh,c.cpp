#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i,j,y;
	int b[10000]={0};
	scanf("%d%d",&n,&m);
	int a[10000][1];
	memset(a,0,sizeof(a)); 
	for(i=1;i<=n;i++)
		scanf("%d ",&a[i][0]);
	for(j=1;j<=m;j++)
	{
		int x;
		scanf("%d",&x);
		b[j]=a[x][0];
	}
	for(y=1;y<=m;y++)
	{
		printf("%d\n",b[y]);
	}


	return 0;
}