#include<stdio.h>
#include<string.h>
int a[100010][3],n,m;
int main()
{
	int i,x,j=1;
    scanf("%d",&n); 
    memset(a,0,sizeof(a)); 
	a[1][1]=1;
    for( i=2;i<=n;i++)
    {
        int x,y; scanf("%d %d",&x,&y);
        a[i][1]=i;
        if(y==0)
        {
            a[a[x][3]][2]=i; 
			a[i][2]=x;
            a[i][3]=a[x][3];
			a[x][3]=i;
            if(x==j) j=i;
        }
        else
        {
            a[i][2]=a[x][2]; 
			a[a[x][2]][3]=i;
            a[x][2]=i;
			a[i][3]=x;
        }
    }
    scanf("%d",&m);
    for( i=1;i<=m;i++)
    {
         scanf("%d",&x);
        if(a[x][1]!=0)
        {
            a[x][1]=0;
            a[a[x][3]][2]=a[x][2];
            a[a[x][2]][3]=a[x][3];
            n--;
            if(x==j) j=a[x][3];
        }
    }
     i=1;
	 x=j;
    while(i<=n)
    {
        printf("%d ",a[x][1]);
        x=a[x][2]; i++;
    }
    return 0;
}