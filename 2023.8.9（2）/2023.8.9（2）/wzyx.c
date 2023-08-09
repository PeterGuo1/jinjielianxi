 /*  Ϊ�����ʹ�ø����ʵ����������Ϸ���ܴﵽ�������ܸ��Ӷȣ�����ʹ�õݹ���ݵķ���������⡣

���ȣ������ֵ䵥������N��N�����ʣ��������ʴ洢��һ�������С�ͬʱ������һ��������飬���ڼ�¼ÿ�������Ƿ��Ѿ�ʹ�ù���

Ȼ�󣬱�дһ���ݹ麯�����ú������������ӵ�ǰ���ʿ�ʼ�������ܸ��Ӷȡ������Ĳ���������ǰ���ʵ�λ�á���ǰ��ʹ�õ��ʵĸ�������ǰ��ʹ�õ��ʵ��ܳ��ȡ�

�ڵݹ麯���У������ֵ��е�ÿ�����ʣ�����õ���û�б�ʹ�ù�����������������ǰ���ʵ����һ����ĸ��ǰһ�����ʵĵ�һ����ĸһ�£����򽫸õ��ʱ��Ϊ��ʹ�ã������µ�ǰ��ʹ�õ��ʵĸ������ܳ��ȡ�

Ȼ��ͨ���ݹ������������������һ�����ʵĿ����ԡ��ݹ���ý����󣬽���ǰ���ʱ��Ϊδʹ�ã�������ʹ�õ��ʵĸ������ܳ��Ȼع�����һ�ε�״̬��

��󣬷������п��ܸ��Ӷ��е����ֵ��*/


#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_SIZE 50

char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN + 1]; // �洢�ʵ��еĵ���
int used[MAX_DICT_SIZE]; // ��¼ÿ�������Ƿ���ʹ��

int max_complexity = 0; // ����ӶȽ��

// �ݹ���������ܸ��Ӷ�
void solve(int pos, int count, int length, int n) {
    if (count == n) { // ���е��ʾ���ʹ�ù�һ��
        if (length > max_complexity) 
		{
            max_complexity = length;
        }
        return ;
    }

    for (int i = 0; i < n; i++) 
	{

        if (!used[i] && (pos == -1 || dictionary[i][0] == dictionary[pos][strlen(dictionary[pos]) - 1]))
		{
            used[i] = 1;
            solve(i, count + 1, length + strlen(dictionary[i]), n);
            used[i] = 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // ���뵥������

    for (int i = 0; i < n; i++) 
{
        scanf("%s", dictionary[i]); // ���뵥��
    }

    solve(-1, 0, 0, n); // ���õݹ麯����������ܸ��Ӷ�

    printf("%d\n", max_complexity); // ������

    return 0;
}


/*
    #include <stdio.h>�������˱�׼�������������ͷ�ļ���
#include <string.h>���������ַ�����������ͷ�ļ���

#define MAX_WORD_LEN 100��������һ���꣬��ʾ���ʵ���󳤶�Ϊ100��
#define MAX_DICT_SIZE 50��������һ���꣬��ʾ�ʵ��е��ʵ��������Ϊ50��

char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN + 1]��������һ����ά�ַ����飬���ڴ洢�ʵ��еĵ��ʡ�����MAX_DICT_SIZE��ʾ�����������MAX_WORD_LEN+1��ʾÿ�����ʵ���󳤶ȣ�+1��Ϊ�˴洢�ַ���������'\0'����

int used[MAX_DICT_SIZE]��������һ���������飬���ڼ�¼ÿ�������Ƿ��ѱ�ʹ�á�����ĳ�����ʵ��е��ʵ�������ͬ��

int max_complexity = 0��������һ�����ͱ�������ʾ����ӶȵĽ������ʼֵΪ0��

void solve(int pos, int count, int length, int n)��������һ���ݹ麯��solve��������������ܸ��Ӷȡ�����pos��ʾ��ǰ�����ĵ���������count��ʾ��ʹ�õĵ���������length��ʾ����ɵ��ַ����ĳ��ȣ�n��ʾ�ʵ��е��ʵ�������

if (count == n)��������е��ʾ���ʹ�ù�һ�Ρ�

if (length > max_complexity)�������ǰ��ɵ��ַ������ȴ�������ӶȽ����

for (int i = 0; i < n; i++)��ѭ�������ʵ��е�ÿ�����ʡ�

if (!used[i] && (pos == -1 || dictionary[i][0] == dictionary[pos][strlen(dictionary[pos]) - 1]))�������ǰ����δ��ʹ������ǰһ�����������������

used[i] = 1����ǵ�ǰ����Ϊ��ʹ�á�

solve(i, count + 1, length + strlen(dictionary[i]), n)���ݹ����solve������������º�Ĳ�����

used[i] = 0������ʹ�ñ�ǻָ�Ϊδʹ��״̬���Ա������һ����ϡ�

int main()�����������������ڡ�

int n; scanf("%d", &n)�����뵥��������

for (int i = 0; i < n; i++)��ѭ����ȡn�����ʡ�

scanf("%s", dictionary[i])����������ַ�����ֵ���ʵ��е���Ӧλ�á�

solve(-1, 0, 0, n)�����õݹ麯��solve����������ܸ��Ӷȡ�

printf("%d\n", max_complexity)���������ӶȽ����

return 0����������������