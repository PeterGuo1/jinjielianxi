#include<stdio.h>
//�Զ�����������--�ṹ��
//����һ���ṹ������
//����һ��ѧ�����ͣ�����ͨ��ѧ������������ѧ������
/*struct stu
{
	char name[20];//����
	char tele[12];//�绰
	char sex[10];//�Ա�
	int age;//����
};
struct stu s3;//ȫ�ֱ���
int main()
{
	//�����ṹ�����
	struct stu s1;
	struct stu s2;

	return 0;
}
struct//�����ṹ�����ͣ�ֻ�ܶ���ȫ�ֱ���
{

}*p;//�ṹ��ָ�����ͣ��ᱨ����Ϊ�ṹ�����������Ͳ�ͬ
struct node//�ṹ���������
{
	int data;
	//struct node n;//�ṹ�岻�����Լ��ڲ������Լ�����ѭ��
	struct node* next;//ָ��ÿһ�����ݺ�ĵ�ַ�ҵ���һ�������漰�������ָ����Ĺ�ϵ
};*/

//�ṹ������Ķ���ͳ�ʼ��
/*struct s
{
	char c;
	int a;
	double d;
	char arr[20];
};
int main()
{
	struct s z={'c', 100, 3.14, "hello bit"};//�ṹ���ʼ��
	printf("%c %d %lf %s\n",z.c, z.a, z.d, z.arr);
}*/

//�ṹ���ڴ����
/*struct s1
{
	char c1;
	int a;
	char c2;
};
struct s2
{
	char c1;
	char c2;
	int a;
};
int main()
{
	struct s1 s1={0};
	struct s2 s2={0};
	printf("%d\n", sizeof(s1));//12
	printf("%d\n",sizeof(s2));//8
	return 0;
}*/




/*#pragma pack(4)//�޸�Ĭ�϶�����������ʡ�����ֽڿռ䣬�����˷��ֽ���
struct s
{
	char c1;//1--7;1--4

	double d;//8
};
#pragma pack()*/

/*#include<stddef.h>
struct s
{
	char c;
	int i;
	double d;
};
int main()
{
	//offsetof();����ṹ���Ա�������ʼλ��ƫ�����Ķ���
	printf("%d\n",offsetof(struct s,i));
	return 0;
}*/

/*struct S 
{
	int a;
	char c;
	double d;
};
void Init(struct S* ps)
{
	ps->a = 100;
	ps->c = 'w';
	ps->d = 3.14;
}
void print1(struct S tmp)
{
	printf("%d %c %lf\n", tmp.a,tmp.c,tmp.d);
}
void print2(const struct S* p)//����ַ�ķ������ţ�ֻ�Ǵ����ĸ��ֽڵĵ�ַ,��const��ֹ��ַ�ı�
{
	printf("%d %c %lf\n",p->a,p->c,p->d);
}
int main()
{
	struct S s = {0};
	Init(&s);
	print1(s);
	print2(&s);
	printf("%d %c %lf\n", s.a,s.c,s.d);
	return 0;
}*/

//λ��(Ҳ�ǽṹ���һ������)--��Ա������int--unsigned int -����signed int ����,λ�γ�Ա�����һ��ð�ź�����
//λ--������λ��ð�ź����ʾ��Ҫռ�ü�������λ��bit����һ���ֽ�8��bit��
/*struct A
{
      int _a:2;
	  int _b:5;
	  int _c:10;
	  int _d:30;//������λ��32
};
int main()
{
	struct A s;
	printf("%d\n", sizeof(s));//8
	return 0;
}*/

/*struct s
{
	char a:3;
	char b:4;
	char c:5;
	char d:4;
};
int main()
{
	struct s x = {0};
	x.a = 10;
	x.b = 20;
	x.c = 3;
	x.d = 4;

	return 0;
}*/

//ö��--�ѿ��ܵ�ȡֵһһ����
//ö�����Ͷ������
/*enum sex
{
	MALE,
	FEMALE,
	SECRET
};
enum color
{
	RED,//0
	YELLOW,//1
	BLUE//2
};
int main()
{
	enum sex s = MALE;
	enum color c = BLUE;//c�������ֻ��ȡ�����Ԫ��
	printf("%d %d %d\n",RED, YELLOW, BLUE);
	return 0;
}*/



//����-������-������--����һ��ռ䶼����ʼλ�ó�������ȡ��ַ����ͬ---�����Ĵ�С����������Ա�Ĵ�С
/*union un//��ͬһʱ��ֻ��ʹ���������е�һ����Ա��
{
	char c;
	int i;
	double d;
};
int main()
{
	union un u;
	printf("%d\n", sizeof(u));
	printf("%p\n",&u);
	printf("%p\n",&(u.c));
	printf("%p\n",&(u.d));
	return 0;
}

//�жϼ�����Ǵ�˻���С��
int check()
{
	int a = 1;
	return *(char*)&a;
}
int check1()
{
	union un
	{
		char c;
		int i;
	}u;
	u.i = 1;
	return u.c;
}
int main()
{
	int a = 1;
	if(1 == *(char*)&a)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}*/




