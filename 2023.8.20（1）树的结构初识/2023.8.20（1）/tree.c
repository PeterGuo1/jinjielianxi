//˫�ױ�ʾ��
#define max_tree_size 100
typedef int elemtype;

typedef struct ptnode
{
	elemtype data;//�ڵ�����
	int parent;//˫��λ��
}ptnode;
typedef struct
{
	ptnode nodes[max_tree_size];
	int r;//����λ��
	int n;//�ڵ���Ŀ
}ptree;

//���ı�ʾ����1.˫�ױ�ʾ��2.���ӱ�ʾ��3.����˫�ױ�ʾ����


//˫�׺��ӱ�ʾ��
#define max_tree_size 100
//���ӽڵ�
typedef struct ctnode
{
	int child;//���ӽڵ���±�
	struct ctnode *next;//ָ����һ�����ӽڵ��ָ��
}*childptr;

//��ͷ�ṹ
typedef struct
{
	elemtype data;//��������нڵ������
	int parent;//���˫�׵��±�
	childptr firstchild;//ָ���һ�����ӵ�ָ��
}ctbox;


//���ṹ
typedef struct
{
	ctbox nodes[max_tree_size];//�ڵ�����
	int r,n;//����λ�úͽڵ����ݣ�
}
