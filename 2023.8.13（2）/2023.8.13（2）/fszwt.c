#include<stdio.h>

int main()
{
	int a[1000][2]={0};
	int b[1000]={0};
	int n,i,j,k,max=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	for(k=1;k<=n-1;k++)
	{
	  for(j=k+1;j<=n;j++)
	 {
		 if(a[k][0]<a[j][0])
		 {
			b[j]=b[j]+a[k][1];
			 break;
		 }
	  }
	}
	for(k=n;k>=2;k--)
	{
	  for(j=k-1;j>=1;j--)
	 {
		 if(a[k][0]<a[j][0])
		 {
			 b[j]=b[j]+a[k][1];
			 break;
		 }
	  }
	}
	for(i=1;i<=n;i++)
		if(max<b[i])
			max=b[i];
	printf("%d",max);
	return 0;
}