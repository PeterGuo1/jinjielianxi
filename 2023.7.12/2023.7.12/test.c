#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<errno.h>
//字符串和内存函数的进阶学习
/*int my_strlen(char* str)
{
	int count = 0;
	assert(str != NULL);
		while(*str != '\0')//while(*str)
		{
			count++;
			str++;
		}
		return count;
}

int main()
{
	//int len = my_strlen("abcdef");
	//printf("%d\n", len);
	//return 0;
	if((strlen("abc")-strlen("abcdef"))>0)//strlen返回类型是size_t--(unsigned int)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
}*/

//strcpy--char* strcpy(char* destination, const char* source);//更改字符串

/*char* my_strcpy(char* dest,const char* src)
{
	assert(dest !=NULL);
	assert(src !=NULL);
	char* ret = dest;//拷贝src指向的字符串到dest指向的空间，包含'\0'；
	while(*dest++ == *src++)//while(*src != '\0')
	{
		;//*dest++ = *src++;   //*dest = *src;
		//dest++;
		//src++;
	}
	return ret;
}
int main()
{
	char arr1[] = "abcdefghi";
	char arr2[] = "bit";
	my_strcpy(arr1,arr2);
	//strcpy(arr1,arr2);
	return 0;
}*/

//strcat--strcat(char* destination,const char* soure)//连接字符串

/*char* my_strcat(char* dest,char* src)
{
	char* ret =dest;
	assert(dest && src);
	while(*dest !=0)//找到\0
	{
		dest++;
	}
	//追加
    while(*dest++ = *src++)
	{
		;
	}
	return ret;

}
int main()
{
	char arr1[30] = "hello";
	char arr2[] = "world";
	my_strcat(arr1,arr1);
	printf("%s\n",arr1);
	return 0;
}*/

//strcmp--int strcmp(const char* str1,const char* str2)

/*int my_strcmp(const char* str1, const char* str2)//比较字符串大小
{
	assert(str1&&str2);
	while(*str1 == *str2)
	{
		if(*str1== '\0')
			return 0;
		str1++;
		str2++;
	}
	if(*str1>*str2)
		return 1;
	else if(*str1<*str2)
		return -1;
}
int main()
{
	char* p1="abcdef";
	char* p2="squer";
	int ret = my_strcmp(p1,p2);//>--1;=--0;<---1;
	printf("%d\n",ret);
	return 0;
}*/

//char* strncpy(char* str1,char* str2,size_t num)--追加部分不够的补"\0"
//char* strncat(char* str1,char* str2,size_t count)--追加完之后主动放一个“\0”，如果长度超过str2长度就只是追加一个"\0"
//char* strncmp(const char* str1,const char* str2,size_t num)--比较前num个字符大小

//strstr--查找字符串

/*char* my_strstr(const char* p1,const char* p2)
{
	char* s1 = NULL;
    char* s2 = NULL;
	char* cur = (char*)p1;
	assert(p1 && p2);
	if(*p2 == '\0')
		return (char*)p1;
	while(*cur)
	{
		s1 = cur;
		s2 = p2;
		if((*s1!='\0')&&(*s2!='\0')&&(*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if(*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}

int main()
{
	char* p1 = "abcdefghi";
	char* p2 = "def";
	char* ret = my_strstr(p1,p2);//返回p中第一次出现字符的位置
	if(ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}*/

//strtok--char* strtok(char* str,const* sep)--分割字符串将某一段拿出来
/*int main()
{
	char* ret;
	char arr[] = "zpw@bitedu.tech";
	char* p = "@.";
	char buf[1024] = {0};
	strcpy(buf,arr);
	for(ret = strtok(arr,p); ret !=NULL; ret = strtok(NULL,p))
	{
		printf("%s\n",ret);
	}
	ret = strtok(arr,p);//调用方法
	printf("%s\n",ret);
	ret = strtok(NULL,p);
	printf("%s\n",ret);
	ret = strtok(NULL,p);
	printf("%s\n",ret);
	return 0;
}*/

//strerror--char* strerror( int errnum);--返回错误码，所对应的错误信息
/*int main()
{
	//错误码
	//0-No error
	//1-Operation not permitted
	//2-No such file or directory
	//.....
	//errno是一个全局的错误码变量
	//当C语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中
	//char* str = strerror(0);//NO error
	//char* str = strerror(errno);//把错误码翻译成对应信息
	//printf("%s\n",str);

	//打开文件
	FILE* pf = fopen("test.txt", "r");//fopen返回一个指针，调用一个文件，文件若不存在则会调用失败
	if(pf == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	else
	{
		printf("open file success\n");
	}
	return 0;
}*/

//内存函数
//符号函数在处理内存的时候有很大局限，只能对字符操作，而内存函数采用void*--void*类型的变量无法进行解引用操作或是加减
//void* memcpy(void* destination, const void* source, size_t num);--size_t num用来确定拷贝几个字节以此来解决不同类型的问题
/*void* my_memcpy(void* dest, void*src, size_t num)//要实现转换就要有一个字节一个字节转换的能力，可以强制转换成char*
{
	void* ret = dest;
	assert(dest&&src);
	while(num--)
	{
	*(char*)dest = *(char*)src;
	++(char*)dest;
	++(char*)src;
	}
	return ret;
}
struct s
{
	char name[20];
	int age;
};
int main()
{
	int arr1[] = {1,2,3,4,5,};
	int arr2[5] = {0};
	struct s arr3[] = { {"张三",20},{"李四",30} };
	struct s arr4[3] = {0};
	my_memcpy(arr4,arr3,sizeof(arr3));
	//memcpy(arr2,arr1,sizeof(arr1));
	return 0;
}*/

//memcpy只能处理不重叠的内存拷贝而memmove可以处理重叠部分的拷贝

void* my_memmove(void* dest, void*src, size_t num)//dest<src从前向后拷贝，dest>src从后向前拷贝;
{
	void* ret = dest;
	assert(dest&&src);
	if(dest>src)
	{
	while(num--)//从后向前拷贝
	{
	*(char*)dest = *(char*)src;
	++(char*)dest;
	++(char*)src;
	}
	}
	else
	{
		while(num--)
		{
			*((char*)dest+num) = *((char*)src+num);
		}
	}
}