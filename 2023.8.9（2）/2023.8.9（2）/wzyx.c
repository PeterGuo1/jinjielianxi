 /*  为了求解使用给定词典来玩这个游戏所能达到的最大可能复杂度，可以使用递归回溯的方法进行求解。

首先，读入字典单词数量N和N个单词，并将单词存储在一个数组中。同时，创建一个标记数组，用于记录每个单词是否已经使用过。

然后，编写一个递归函数，该函数用于搜索从当前单词开始的最大可能复杂度。函数的参数包括当前单词的位置、当前已使用单词的个数、当前已使用单词的总长度。

在递归函数中，遍历字典中的每个单词，如果该单词没有被使用过且满足条件（即当前单词的最后一个字母与前一个单词的第一个字母一致），则将该单词标记为已使用，并更新当前已使用单词的个数和总长度。

然后，通过递归调用自身，继续搜索下一个单词的可能性。递归调用结束后，将当前单词标记为未使用，并将已使用单词的个数和总长度回滚到上一次的状态。

最后，返回所有可能复杂度中的最大值。*/


#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_DICT_SIZE 50

char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN + 1]; // 存储词典中的单词
int used[MAX_DICT_SIZE]; // 记录每个单词是否已使用

int max_complexity = 0; // 最大复杂度结果

// 递归求解最大可能复杂度
void solve(int pos, int count, int length, int n) {
    if (count == n) { // 所有单词均已使用过一次
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
    scanf("%d", &n); // 读入单词数量

    for (int i = 0; i < n; i++) 
{
        scanf("%s", dictionary[i]); // 读入单词
    }

    solve(-1, 0, 0, n); // 调用递归函数求解最大可能复杂度

    printf("%d\n", max_complexity); // 输出结果

    return 0;
}


/*
    #include <stdio.h>：包含了标准输入输出函数的头文件。
#include <string.h>：包含了字符串处理函数的头文件。

#define MAX_WORD_LEN 100：定义了一个宏，表示单词的最大长度为100。
#define MAX_DICT_SIZE 50：定义了一个宏，表示词典中单词的最大数量为50。

char dictionary[MAX_DICT_SIZE][MAX_WORD_LEN + 1]：定义了一个二维字符数组，用于存储词典中的单词。其中MAX_DICT_SIZE表示数组的行数，MAX_WORD_LEN+1表示每个单词的最大长度（+1是为了存储字符串结束符'\0'）。

int used[MAX_DICT_SIZE]：定义了一个整型数组，用于记录每个单词是否已被使用。数组的长度与词典中单词的数量相同。

int max_complexity = 0：定义了一个整型变量，表示最大复杂度的结果，初始值为0。

void solve(int pos, int count, int length, int n)：定义了一个递归函数solve，用于求解最大可能复杂度。参数pos表示当前操作的单词索引，count表示已使用的单词数量，length表示已组成的字符串的长度，n表示词典中单词的数量。

if (count == n)：如果所有单词均已使用过一次。

if (length > max_complexity)：如果当前组成的字符串长度大于最大复杂度结果。

for (int i = 0; i < n; i++)：循环遍历词典中的每个单词。

if (!used[i] && (pos == -1 || dictionary[i][0] == dictionary[pos][strlen(dictionary[pos]) - 1]))：如果当前单词未被使用且与前一个单词满足连贯规则。

used[i] = 1：标记当前单词为已使用。

solve(i, count + 1, length + strlen(dictionary[i]), n)：递归调用solve函数，传入更新后的参数。

used[i] = 0：将已使用标记恢复为未使用状态，以便进行下一次组合。

int main()：主函数，程序的入口。

int n; scanf("%d", &n)：读入单词数量。

for (int i = 0; i < n; i++)：循环读取n个单词。

scanf("%s", dictionary[i])：将输入的字符串赋值给词典中的相应位置。

solve(-1, 0, 0, n)：调用递归函数solve，求解最大可能复杂度。

printf("%d\n", max_complexity)：输出最大复杂度结果。

return 0：程序正常结束。