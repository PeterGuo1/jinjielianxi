//ϰ��3-8��ѭ��С����Repeating Decimals, ACM/ICPC World Finals 1990, UVa202��

//��������a��b��0��a��3000��1��b��3000�������a/b��ѭ��С����ʾ�Լ�ѭ���ڳ��ȡ�����a=5��b=43��С����ʾΪ0.(116279069767441860465)��ѭ���ڳ���Ϊ21��
#include <stdio.h>
#include <string.h>
#define maxn 3001
int main()
{
    int a,b,r;//r��¼��ǰ���������
    int d[maxn];//d��¼С�����ֵ�ÿһλ
    int count=0;//��¼ѭ���ڳ���
    scanf("%d%d",&a,&b);
    printf("%d.(",a/b);//�����������
    char s[maxn];//s������¼ÿһ��������
    memset(d,0,sizeof(d));//��С����������
    memset(s,0,sizeof(s));//��������������
    if(a-b>0)//�Ƚ����������λȥ��
    {
        a=a-b;
    }
    r=a%b;//��ʼ������
    while(strchr(s,r)==NULL)//�����ǰ����û���ڱ���¼��
    {
        s[count]=r;
        r=r*10;
        d[count]=r/b;//��¼С��λ
        count++;
        r=r%b;//��������
    }
    for(int i=0;i<count;i++)
    {
    printf("%d",d[i]);
    }
    printf(")\n");
    printf("%d\n",count);
    return 0;
}
