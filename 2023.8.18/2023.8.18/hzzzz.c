#include<stdio.h>//��׺ת��׺
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
void push(sqstack *s,char e)
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

void pop(sqstack *s,char *e)
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
	elemtype c,e;
	sqstack s;
	int i = 0;
	char str[maxbuffer];//������
	Initstack(&s);
	printf("��������׺���ʽ����#��Ϊ������־:");
	scanf("%c",&c);
	while(c!='#')
	{
		if(c>='0'&&c<='9')
		{
			printf("%c",c);
		}
		else if(')'==c)
		{
			pop(&s,&e);
			while('('!=e)
			{
				printf("%c",e);
				pop(&s,&e);
			}
		}
		else if('+'==c||'-'==c)
		{
			if(!stacklen(s))
			{
				push(&s,c);
			}
			else 
			{
				do
				{
					pop(&s,&e);
					if('('==e)
					{
						push(&s,e);
					}
					else
					{
						printf("%c",e);
					}
				}while(stacklen(s)&&'('!=e);
				push(&s,c);
		}
		}
		else if('*'==c||'/'==c||'('==c)
		{
			push(&s,c);
		}
		else
		{
			printf("\n���������ʽ����!\n");
			return -1;
		}
		scanf("%c",&c);
	}
	while(stacklen(s))
	{
		pop(&s,&e);
		printf("%c",e);
	}
		
	return 0;
	}
	