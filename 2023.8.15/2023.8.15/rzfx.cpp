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


/*������˵һ����Ŀ���⣺���ǿ��԰���Ŀ����һ��ջ������Ŀ��Ҫ����������ջ���������ջ����ջ�Ͳ�ѯ�Ĺ�����

����˼·��������f[i]Ϊջ�д��µ��ϵ�i��Ԫ���е����ֵ�������Ǽ���һ����Ԫ��xʱ��t++�����ڶ���һ��Ԫ�أ�����f[t]=max(f[t-1],x)����ô�ڳ�ջʱֻҪ���f[t-1]���ڲ���ʱֻҪ���f[t]��

�ο����룺




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