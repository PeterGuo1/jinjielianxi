#include<stdio.h>//��ŵ��

void move(int n,char x,char y,char z)//��n�����ӽ���y�ƶ���z��
{
	if(1==n)
	{
		printf("%c-->%c\n",x,z);
	}
	else
	{
		move(n-1,x,z,y);//��n-1�����Ӵ�x����z�ƶ���y��
		printf("%c-->%c",x,z);//����n�����Ӵ�x�Ƶ�z��
		move(n-1,y,x,z);//��n-1�����Ӵ�y����x�ƶ���z��
	}
}
int main()
{
	int n;char x,y,z;
	printf("�����뺺ŵ���Ĳ���:");
	printf("%d",&n);
	printf("�ƶ��Ĳ�������:\n");
	move(n,x,y,z);
	return 0;
}
