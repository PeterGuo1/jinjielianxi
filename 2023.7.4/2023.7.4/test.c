#include <stdio.h>

int count_bit_one(int n)
{
	int count = 0;
	while(n)
	{
		n=n&(n-1);
		count++;
	}
	return count;
}

int get_diff_bit(int m,int n)
{
	int tmp =m^n;//^������
	return count_bit_one(tmp);
}

void print(int m)//��������ż��ӡ
{
	int i;
	printf("����λ:\n");
	for(i=30;i>=0;i -= 2)
	{
		printf("%d",(m>>i)&1);
	}
	printf("\n");
	printf("ż��λ:\n");
	for(i=31;i>=1;i -= 2)
	{
		printf("%d",(m>>i)&1);
	}
	printf("\n");
}


void Print(int *p,int sz)
{
	int i;
	for(i=0;i<sz;i++)
	{
	  printf("%d",*(p+i));
	}
}

//int main()
//{
//	int m=0;
//	scanf("%d",&m);
//	print(m);
//	return 0;
//}

//int main()
//{
//	int arr[]={1,2,3,4,5,6,7,8,9};
//	int sz =sizeof(arr)/sizeof(arr[0]);
//	Print(arr,sz);
//
//	return 0;
//}

//�ṹ��  struct ***
//      {
//           int x;
//		     int y;
//	     }p1;p2;

//int main()
//{
//	int m ;
//	int n ;
//	int count;
//	scanf("%d%d", &m, &n);
 //   count = get_diff_bit(m, n);
//	printf("coount = %d\n", count);
//	return 0;
//}



struct S
{
	int a;
	char c;
	char arr[20];
	double d;
};
struct T
{
	char ch[10];
	struct S s;
	char *pc;
};
//int main()
//{
//	char arr[] ="hello bit\n";
//	struct T t={ "hehe",{100,'w',"hello world",3.14},arr};
//	printf("%s\n",t.ch);
//	printf("%s\n",t.s.arr);
//	printf("%lf\n",t.s.d);
//	printf("%s\n",t.pc);
//	return 0;
//}



typedef struct stu
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}stu;

void print1(stu tmp)
{
	printf("name: %s\n",tmp.name);
	printf("age: %d\n", tmp.age);
	printf("tele: %s\n", tmp.tele);
	printf("sex: %s\n", tmp.sex);
}
void print2(stu* ps)//ָ����ʽ�ṹ������������ã���ռ�ÿռ䡣�ṹ�崫��ʱһ�㴫��ַ
{
	printf("name: %s\n", ps->name);
	printf("age: %d\n", ps->age);
	printf("tele: %s\n", ps->tele);
	printf("sex: %s\n", ps->sex);
}

int main()
{
	stu s={"����", 40, "15595465622","��"};
	print1(s);
	print2(&s);
	return 0;
}