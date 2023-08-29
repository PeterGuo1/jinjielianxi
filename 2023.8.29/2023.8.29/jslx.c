/*#include<stdio.h>
int main()
{
	int a[6][2],b[4],k=0,i,j,t,sum1=0,sum2=0,len=0;//t用来标记相等的四个面的长度，b[4]存放四个相等的面的行下标
	for(i=0;i<6;i++)
	{
		for(j=0;j<2;j++)
	       scanf("%d",&a[i][j]);
	}
		t=a[0][0];//将输入的第一个面定为四个面的长
		for(i=0;i<6;i++)      //排除是正方形的情况
			for(j=0;j<2;j++)
				if(a[i][j]==t)
					len++;
				if(len==12)//正方形12条边相等
				{
					printf("YES\n");
					return 0;
				}
		for(i=0;i<6;i++)
		{
			if(a[i][0]==t)//找出四个相等的面，行下标存放在b[k]数组中
			{
				b[k]=i;
				k++;
			}
			if(k==4)
				break;
		}
		if(k!=4)//未找到四个相等的面，构不成长方体
		{
			printf("NO\n");
			return 0; 
		}
		else
		{
			for(i=0;i<4;i++)
				sum1+=a[b[i]][1];//sum1为四个相等的面宽的和
			for(i=0;i<6;i++)
			{
				if(a[i][0]!=t)
				{
				for(j=0;j<2;j++)
					sum2+=a[i][j];//sum2为长方体侧面的周长，转化为两侧面的长与宽的和
				}
			}

		}
		if(sum1==sum2)//当相等的四个面（前后上下）的宽的和与侧面周长相等时，则可构成正方体
			printf("yes\n");
		else
			printf("NO\n");
	return 0;
}

版权声明：本文为CSDN博主「Knock man」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Anterior_condyle/article/details/104179538————————————————
*/


#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
 
double M[15][35];
int E[15][35];
 
int main() {
	double a,b,c;
	int i,j,ai;
	for(i=0;i<10;++i)
		for(j=1;j<31;++j) {
			a = 1 - pow(2, -1-i);
			b = (1 << j) -1;
			c = log10(a) + b * log10(2);
			E[i][j] = floor(c);
			M[i][j] = pow(10, c-E[i][j]);
		}
	
	string s;
	while(cin >> s && s!="0e0") {
		for(i=0;i<s.size();++i)
			if(s[i] == 'e')
				s[i] = ' ';
		istringstream iss(s);
		iss >> a >> ai;
		while(a < 1) {
			a *= 10;
			--ai;
		}
		for(i=0;i<10;++i) {
			for(j=1;j<31;++j) {
				if(E[i][j] == ai && fabs(M[i][j]-a) < 1e-4) {
					cout << i << " " << j << endl;
				}
			}
		}
	}
	return 0;
}
 
————————————————
版权声明：本文为CSDN博主「漂流瓶jz」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq278672818/article/details/105742444