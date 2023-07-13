#include<stdio.h>
//自定义数据类型--结构体
//声明一个结构体类型
//声明一个学生类型，是想通过学生类型来创建学生变量
/*struct stu
{
	char name[20];//名字
	char tele[12];//电话
	char sex[10];//性别
	int age;//年龄
};
struct stu s3;//全局变量
int main()
{
	//创建结构体变量
	struct stu s1;
	struct stu s2;

	return 0;
}
struct//匿名结构体类型，只能定义全局变量
{

}*p;//结构体指针类型，会报错，因为结构体里数据类型不同
struct node//结构体的自引用
{
	int data;
	//struct node n;//结构体不能在自己内部调用自己会死循环
	struct node* next;//指向每一个数据后的地址找到下一个数据涉及数据域和指针域的关系
};*/

//结构体变量的定义和初始化
/*struct s
{
	char c;
	int a;
	double d;
	char arr[20];
};
int main()
{
	struct s z={'c', 100, 3.14, "hello bit"};//结构体初始化
	printf("%c %d %lf %s\n",z.c, z.a, z.d, z.arr);
}*/

//结构体内存对齐
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




/*#pragma pack(4)//修改默认对齐数用来节省访问字节空间，减少浪费字节数
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
	//offsetof();计算结构体成员相对于起始位置偏移量的多少
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
void print2(const struct S* p)//传地址的方法更优，只是传输四个字节的地址,用const防止地址改变
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

//位段(也是结构体的一种类型)--成员必须是int--unsigned int -或者signed int 类型,位段成员后边有一个冒号和数字
//位--二进制位，冒号后面表示需要占用几个比特位（bit），一个字节8个bit；
/*struct A
{
      int _a:2;
	  int _b:5;
	  int _c:10;
	  int _d:30;//最大比特位是32
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

//枚举--把可能的取值一一例举
//枚举类型定义举例
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
	enum color c = BLUE;//c被定义后只能取定义的元素
	printf("%d %d %d\n",RED, YELLOW, BLUE);
	return 0;
}*/



//联合-联合体-共用体--开辟一款空间都从起始位置出发所以取地址会相同---变量的大小至少是最大成员的大小
/*union un//在同一时刻只能使用联合体中的一个成员；
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

//判断计算机是大端还是小端
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
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}*/




