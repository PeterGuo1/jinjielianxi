#include <cstdio>
const int mod = 10000;
int x,s,t; //x�ǵ�ǰ������s�Ǻͣ�t�ǵ�ǰ�εĳ˻�
char c;
int main(){
    scanf("%d",&t);//�ȶ����һ������֮��ÿ�ζ���һ������һ����
    while(scanf("%c",&c) && c != '\n'){ //����������з�
        scanf("%d",&x);
        if(c == '*') t = t * x % mod; //�ǳ˺ž����
        else s = (s + t) % mod,t = x;
        //�Ӻžͼ�����һ�εĻ���t��Ϊ��һ�εĵ�һ����
    }
    printf("%d\n",(s + t) % mod); //�������һ�εĻ�
    return 0;
}


//https://www.luogu.com.cn/problem/solution/P1981









#include <iostream>
#include <stack>
using namespace std;
stack <int> x;//һ�������ֲ�������������ӵ�ջ
int main()
{
	int a,b;
	char c;
	cin>>a;//������һ�������Ժ����+��������
	int m=10000;
	a=a%m;//����Ĳ���
	x.push(a);//ѹ��ջ��
	while(cin>>c>>b)
	{
		if(c=='*')//��*֮ǰ��������*֮������ֻ�����
		{
			a=x.top();
			x.pop();
			x.push(a*b%m);
		}
		else//��b����
			x.push(b);
	}
	a=0;
	while(x.size())
	{
		a+=x.top();
		a%=m;//ȡģ�����֮Դ
		x.pop();
	}
	cout<<a<<endl;
	return 0;
}
