#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define stack_Init_size 20
#define stackincrement 10
#define maxbuffer 10

typedef char elemtype;
typedef struct
{
	elemtype *base;
	elemtype *top;
	int stacksize;
}sqstack;

void Initstack(sqstack *s)
{
	s->base = (elemtype*)malloc(stack_Init_size*sizeof(elemtype));
	if(!s->base)
	{
		exit(0);
	}
	s->top=s->base;
	s->stacksize=stack_Init_size;
}
void push(sqstack *s,double e)
{
	if((s->top-s->base)>=s->stacksize )
	{
		s->base  = (elemtype*)realloc(s->base ,(s->stacksize +stackincrement)*sizeof(elemtype));
		if(!s->base )
		{
			exit(0);
		}
	}

	*(s->top)=e;
	s->top++;
}

void pop(sqstack *s,double *e)
{
	if(s->top ==s->base )
		return;
	*e = *--(s->top );
}

int stacklen(sqstack s)
{
	return (s.top -s.base );
}

int main()
{
	elemtype c;
	sqstack s;
	double d,e;
	int i = 0;
	char str[maxbuffer];//������
	Initstack(&s);
	printf("�밴���沨�����ʽ������������ݣ������������֮���ÿո��������#��Ϊ������־:");
	scanf("%c",&c);
	while(c!='#')
	{
		scanf("%c",&c);
		while(isdigit(c)||c=='.')
		{
			str[i++] = c;
			str[i]='\0';
			if(i>=10)
			{
				printf("����;����ĵ������ݹ���!\n");
				return -1;
			}
			scanf("%c",&c);
			if(c==' ')
			{
				d = atof(str);//atof()���ַ���ת��Ϊ������
				push(&s,d);
				i=0;
				break;
			}
		}
		switch(c)
		{
		case '+':
				pop(&s,&e);
				pop(&s,&d);
				push(&s, d+e);
				break;
		case '-':
			pop(&s,&e);
			pop(&s,&d);
			push(&s, d-e);
			break;
		case'*':
			pop(&s,&e);
			pop(&s,&d);
			push(&s, d*e);
			break;
		case'/':
			pop(&s,&e);
			pop(&s,&d);
			if(e!=0)
			{
			    push(&s, d/e);
			}
			else
			{
				printf("\n����:����Ϊ��!\n");
				return -1;
			}
			break;
		}

		}
	pop(&s,&d);
	printf("\n���յļ�����;%f\n",d);
	return 0;
	}
	