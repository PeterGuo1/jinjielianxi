//习题3-8　循环小数（Repeating Decimals, ACM/ICPC World Finals 1990, UVa202）

//输入整数a和b（0≤a≤3000，1≤b≤3000），输出a/b的循环小数表示以及循环节长度。例如a=5，b=43，小数表示为0.(116279069767441860465)，循环节长度为21。
#include <stdio.h>
#include <string.h>
#define maxn 3001
int main()
{
    int a,b,r;//r记录当前步骤的余数
    int d[maxn];//d记录小数部分的每一位
    int count=0;//记录循环节长度
    scanf("%d%d",&a,&b);
    printf("%d.(",a/b);//输出整数部分
    char s[maxn];//s用来记录每一步的余数
    memset(d,0,sizeof(d));//将小数数组清零
    memset(s,0,sizeof(s));//将余数数组清零
    if(a-b>0)//先将结果的整数位去除
    {
        a=a-b;
    }
    r=a%b;//初始化余数
    while(strchr(s,r)==NULL)//如果当前余数没有在被记录过
    {
        s[count]=r;
        r=r*10;
        d[count]=r/b;//记录小数位
        count++;
        r=r%b;//更新余数
    }
    for(int i=0;i<count;i++)
    {
    printf("%d",d[i]);
    }
    printf(")\n");
    printf("%d\n",count);
    return 0;
}
