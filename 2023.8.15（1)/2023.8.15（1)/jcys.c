#include <cstdio>
const int mod = 10000;
int x,s,t; //x是当前的数，s是和，t是当前段的乘积
char c;
int main(){
    scanf("%d",&t);//先读入第一个数，之后每次读入一个符号一个数
    while(scanf("%c",&c) && c != '\n'){ //最后会读到换行符
        scanf("%d",&x);
        if(c == '*') t = t * x % mod; //是乘号就相乘
        else s = (s + t) % mod,t = x;
        //加号就加上上一段的积，t变为下一段的第一个数
    }
    printf("%d\n",(s + t) % mod); //加上最后一段的积
    return 0;
}


//https://www.luogu.com.cn/problem/solution/P1981









#include <iostream>
#include <stack>
using namespace std;
stack <int> x;//一个存数字并在最后把它们相加的栈
int main()
{
	int a,b;
	char c;
	cin>>a;//先输入一个数，以后符号+数字输入
	int m=10000;
	a=a%m;//必须的操作
	x.push(a);//压入栈中
	while(cin>>c>>b)
	{
		if(c=='*')//将*之前的数字与*之后的数字积存入
		{
			a=x.top();
			x.pop();
			x.push(a*b%m);
		}
		else//将b存入
			x.push(b);
	}
	a=0;
	while(x.size())
	{
		a+=x.top();
		a%=m;//取模是万恶之源
		x.pop();
	}
	cout<<a<<endl;
	return 0;
}
