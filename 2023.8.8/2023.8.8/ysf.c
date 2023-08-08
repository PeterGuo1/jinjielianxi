#include<stdio.h>

int main()
{
	int i,j,x = 0;
	int n = 0;
	int m = 0;
	int arr[500] = {0};
	scanf("%d",&n);
	scanf("%d",&m);
	if(m<1||n>100)
		printf("error");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			x++;
			if(x>n)
				x=1;
			if(arr[x]!=0)
				j--;
		}
		printf("%d ",x);
		arr[x] = x;
	}
	
	return 0;
}
