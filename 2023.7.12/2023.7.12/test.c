#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<errno.h>
//�ַ������ڴ溯���Ľ���ѧϰ
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
	if((strlen("abc")-strlen("abcdef"))>0)//strlen����������size_t--(unsigned int)
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}
}*/

//strcpy--char* strcpy(char* destination, const char* source);//�����ַ���

/*char* my_strcpy(char* dest,const char* src)
{
	assert(dest !=NULL);
	assert(src !=NULL);
	char* ret = dest;//����srcָ����ַ�����destָ��Ŀռ䣬����'\0'��
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

//strcat--strcat(char* destination,const char* soure)//�����ַ���

/*char* my_strcat(char* dest,char* src)
{
	char* ret =dest;
	assert(dest && src);
	while(*dest !=0)//�ҵ�\0
	{
		dest++;
	}
	//׷��
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

/*int my_strcmp(const char* str1, const char* str2)//�Ƚ��ַ�����С
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

//char* strncpy(char* str1,char* str2,size_t num)--׷�Ӳ��ֲ����Ĳ�"\0"
//char* strncat(char* str1,char* str2,size_t count)--׷����֮��������һ����\0����������ȳ���str2���Ⱦ�ֻ��׷��һ��"\0"
//char* strncmp(const char* str1,const char* str2,size_t num)--�Ƚ�ǰnum���ַ���С

//strstr--�����ַ���

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
	char* ret = my_strstr(p1,p2);//����p�е�һ�γ����ַ���λ��
	if(ret == NULL)
	{
		printf("�Ӵ�������\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}*/

//strtok--char* strtok(char* str,const* sep)--�ָ��ַ�����ĳһ���ó���
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
	ret = strtok(arr,p);//���÷���
	printf("%s\n",ret);
	ret = strtok(NULL,p);
	printf("%s\n",ret);
	ret = strtok(NULL,p);
	printf("%s\n",ret);
	return 0;
}*/

//strerror--char* strerror( int errnum);--���ش����룬����Ӧ�Ĵ�����Ϣ
/*int main()
{
	//������
	//0-No error
	//1-Operation not permitted
	//2-No such file or directory
	//.....
	//errno��һ��ȫ�ֵĴ��������
	//��C���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
	//char* str = strerror(0);//NO error
	//char* str = strerror(errno);//�Ѵ����뷭��ɶ�Ӧ��Ϣ
	//printf("%s\n",str);

	//���ļ�
	FILE* pf = fopen("test.txt", "r");//fopen����һ��ָ�룬����һ���ļ����ļ���������������ʧ��
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

//�ڴ溯��
//���ź����ڴ����ڴ��ʱ���кܴ���ޣ�ֻ�ܶ��ַ����������ڴ溯������void*--void*���͵ı����޷����н����ò������ǼӼ�
//void* memcpy(void* destination, const void* source, size_t num);--size_t num����ȷ�����������ֽ��Դ��������ͬ���͵�����
/*void* my_memcpy(void* dest, void*src, size_t num)//Ҫʵ��ת����Ҫ��һ���ֽ�һ���ֽ�ת��������������ǿ��ת����char*
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
	struct s arr3[] = { {"����",20},{"����",30} };
	struct s arr4[3] = {0};
	my_memcpy(arr4,arr3,sizeof(arr3));
	//memcpy(arr2,arr1,sizeof(arr1));
	return 0;
}*/

//memcpyֻ�ܴ����ص����ڴ濽����memmove���Դ����ص����ֵĿ���

void* my_memmove(void* dest, void*src, size_t num)//dest<src��ǰ��󿽱���dest>src�Ӻ���ǰ����;
{
	void* ret = dest;
	assert(dest&&src);
	if(dest>src)
	{
	while(num--)//�Ӻ���ǰ����
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