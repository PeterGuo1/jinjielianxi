#include<stdio.h>

int main()
{
	int i,j,k,max=0,s=0,n,m,z=0;
	int a[100000]={0};
	int b[100000]={0};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		if(m==0)
		{
			scanf("%d",&k);
			s++;
			a[s]=k;
			if(max<k)
				max=k;
		}
		else if(m==1)
		{
			a[s]=0;
			s--;
			max=0;
			for(j=1;j<=s;j++)
				if(max<a[j])
					max=a[j];
		}
		else if(m==2)
		{
			z++;
			b[z]=max;
		}
	}
	for(i=1;i<=z;i++)
		printf("%d\n",b[i]);


	return 0;
}


/*首先我说一下题目大意：我们可以把题目看成一个栈，而题目的要求就是在这个栈里面进行入栈、出栈和查询的工作。

解题思路：我们设f[i]为栈中从下到上的i个元素中的最大值，当我们加入一个新元素x时，t++，由于多了一个元素，所以f[t]=max(f[t-1],x)。那么在出栈时只要输出f[t-1]，在查找时只要输出f[t]。

参考代码：




#include<iostream>   
#include<cstdio>   
#include<cmath>   
using namespace std;   
int f[200001],n,x,y,t=0;   //https://www.luogu.com.cn/problem/solution/P1165
int main()   
{   
    cin>>n;   
    f[0]=0;   
    for (int i=1; i<=n; i++)   
    {   
        cin>>x;   
        if (x==0)    
        {   
                  cin>>y;   
.                  t++;   
                  f[t]=max(f[t-1],y);   
        }   
        if (x==1) if (t!=0) t--;   
        if (x==2) cout<<f[t]<<endl;   
    }   
 
    return 0;   
}  