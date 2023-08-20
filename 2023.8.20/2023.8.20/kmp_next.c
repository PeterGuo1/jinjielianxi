#include<stdio.h>

typedef char* string

void get_next(string T,int *next)
{
	int j = 0;
	int i = 1;
	next[1] = 0;
	while(i<T[0])
	{
		if(0==j||T[i]==T[j])
		{
			i++;
			j++;
			if(T[i]!=T[j])
			{
				next[i]=j;
			}
			else
			{
				next[i]=next[j];
			}

		}
		else
		{
			j=next[j];
		}
	}
	
}
//�����Ӵ�T������s��pos���ַ�֮���λ��
//�������ڷ���0
int index_kmp(string s,string T,int pos)
{
	int i =pos;
	int j =i;
	int next[255];
	get_next(T,next);
	while(i<=s[0]&&j<=T[0])
	{
		if(0==j||s[i]==T[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
}
