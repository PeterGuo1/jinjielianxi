#include <stdio.h>
#include<string.h>

int main()
{
	int n,i,j,k=0,m,l=0,z=1,s=1;
	int a[1000]={0},b[1000]={0},c[1000]={0};
	scanf_s("%d",&n);
	l=n;
	while(n!=0)
	{
		z=1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf_s("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		k=m;
		for(j=1;j<=m;j++)
		{
			scanf_s("%d",&b[i]);
			if(b[i]!=a[k])
				z=0;
			k--;
		}
		c[s]=z;
		s++;
		n--;
	}
	for(i=1;i<=l;i++)
		if(c[i]==1)
		printf("yes\n");
		else
		printf("no\n");


	return 0;
}