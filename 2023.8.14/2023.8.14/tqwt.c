#include<stdio.h>

int a[5000][3000];
int main()
{
	int i,j,k,z,m,count=0;
	int n,p;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
	{
		m=0;
		scanf("%d%d",&k,&z);
		if(a[k][z]==0)
			m++;
		a[k][z]=1;
		for(j=z+1;j<=p;j++)
			if(a[k][j]!=0)
			{
				m++;
				a[k][j]=0;
			}
		count+=m;
	}
	printf("%d",count);

		
	return 0;
}