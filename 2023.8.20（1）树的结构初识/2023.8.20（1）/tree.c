//双亲表示法
#define max_tree_size 100
typedef int elemtype;

typedef struct ptnode
{
	elemtype data;//节点数据
	int parent;//双亲位置
}ptnode;
typedef struct
{
	ptnode nodes[max_tree_size];
	int r;//根的位置
	int n;//节点数目
}ptree;

//树的表示法：1.双亲表示法2.孩子表示法3.孩子双亲表示法；


//双亲孩子表示法
#define max_tree_size 100
//孩子节点
typedef struct ctnode
{
	int child;//孩子节点的下标
	struct ctnode *next;//指向下一个孩子节点的指针
}*childptr;

//表头结构
typedef struct
{
	elemtype data;//存放在树中节点的数据
	int parent;//存放双亲的下标
	childptr firstchild;//指向第一个孩子的指针
}ctbox;


//树结构
typedef struct
{
	ctbox nodes[max_tree_size];//节点数组
	int r,n;//根的位置和节点数据；
}
