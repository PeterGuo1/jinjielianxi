//https://www.luogu.com.cn/problem/solution/P1706
/*#include<iostream>
#include <algorithm>

using namespace std;
int a[10];
int main()
{
	int n,i,j=1,k;
	cin>>n;
	for(i=1;i<=n;i++)
	 {
		 a[i]=n-i+1;j*=i;
	 }//��Ŀ����û˵Ҫ��С�������
     //������������ǳ�ʼ��ֵΪ�������
     //��a[1~n]=n~1;˳�����n!
	for(i=1;i<=j;i++)
	 {next_permutation(a+1,a+n+1);
	  for(k=1;k<=n;k++)
	   cout<<"    "<<a[k];//��һ�����һ��
       //�ո��鸴��
	  cout<<endl;
	 }
	 return 0;
}*/


#include<iostream>
using namespace std;
int n;
bool vis[15];
int step=1;
int a[15];
int main()
{
    if(step==1)
    {
        cin>>n;
    }
    int i;
    if(step-1==n)
    {
        for(i=1;i<=n;i++)
        printf("%5d",a[i]);
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            a[step]=i;
            step++;
            main();
            step--;
            vis[i]=0;
        }
    }
    return 0;
}