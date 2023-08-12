/*#include<stdio.h>

int arr[50];
int main()
{
	int n,m,i,j,x,y,k,count=0;
	scanf_s("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf_s("%d",&x);
		y=0;
		for(j=1;j<=n;j++)
		{
			if(arr[j]==x)
				y++;
		}
		if(y==0)
		{
			if(arr[n]!=0)
			{
				for(j=1;i<=n;j++)
					arr[j]=arr[j+1];
				arr[n]=x;
			}
			else
			{
				k=1;
				while(arr[k])
					k++;
				arr[k]=x;
			}
			count++;
					
		
		}
	}
	printf("%d",count);
	return 0;
		
			
}*/


/*#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	int m,n,i,count=0,sum=0,temp;
	scanf("%d%d",&m,&n);
	int mem[m],art[n];
	int num[1000]={0};
	for(i=0;i<n;i++){
		scanf("%d",&art[i]);
		if(num[art[i]]==1){
		}
		else if(count<m){
			mem[count++]=art[i];
			num[art[i]]=1;
		}
		else{
			temp=mem[count%m];
			mem[count%m]=art[i];
			count++;
			num[temp]=0;
			num[art[i]]=1;
		}
	}
	printf("%d",count);
	return 0;
}
 
