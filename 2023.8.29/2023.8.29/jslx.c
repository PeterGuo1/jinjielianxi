/*#include<stdio.h>
int main()
{
	int a[6][2],b[4],k=0,i,j,t,sum1=0,sum2=0,len=0;//t���������ȵ��ĸ���ĳ��ȣ�b[4]����ĸ���ȵ�������±�
	for(i=0;i<6;i++)
	{
		for(j=0;j<2;j++)
	       scanf("%d",&a[i][j]);
	}
		t=a[0][0];//������ĵ�һ���涨Ϊ�ĸ���ĳ�
		for(i=0;i<6;i++)      //�ų��������ε����
			for(j=0;j<2;j++)
				if(a[i][j]==t)
					len++;
				if(len==12)//������12�������
				{
					printf("YES\n");
					return 0;
				}
		for(i=0;i<6;i++)
		{
			if(a[i][0]==t)//�ҳ��ĸ���ȵ��棬���±�����b[k]������
			{
				b[k]=i;
				k++;
			}
			if(k==4)
				break;
		}
		if(k!=4)//δ�ҵ��ĸ���ȵ��棬�����ɳ�����
		{
			printf("NO\n");
			return 0; 
		}
		else
		{
			for(i=0;i<4;i++)
				sum1+=a[b[i]][1];//sum1Ϊ�ĸ���ȵ����ĺ�
			for(i=0;i<6;i++)
			{
				if(a[i][0]!=t)
				{
				for(j=0;j<2;j++)
					sum2+=a[i][j];//sum2Ϊ�����������ܳ���ת��Ϊ������ĳ����ĺ�
				}
			}

		}
		if(sum1==sum2)//����ȵ��ĸ��棨ǰ�����£��Ŀ�ĺ�������ܳ����ʱ����ɹ���������
			printf("yes\n");
		else
			printf("NO\n");
	return 0;
}

��Ȩ����������ΪCSDN������Knock man����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/Anterior_condyle/article/details/104179538��������������������������������
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
 
��������������������������������
��Ȩ����������ΪCSDN������Ư��ƿjz����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq278672818/article/details/105742444