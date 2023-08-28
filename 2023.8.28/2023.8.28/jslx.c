#include<stdio.h>
int main()
{
	char a[5][6]={"TRGSJ","XDOKI","M VLN","WPABE","UQHCF"};
	char c[10];
	int i=2,j=1,k=0;
	scanf("%s",c);
	while(c[k]!='0'&&c[k]!='\n')
	{
		char tmp=' ';
		switch(c[k])
		{
		case 'A':
		    a[i][j]=a[i-1][j];
			a[i-1][j]=tmp;
			i--;
			break;
		case 'B':
			a[i][j]=a[i+1][j];
			a[i+1][j]=tmp;
			i++;
			break;
		case 'L':
			a[i][j]=a[i][j-1];
			a[i][j-1]=tmp;
			j--;
			break;
		case 'R':
			a[i][j]=a[i][j+1];
			a[i][j+1]=tmp;
			j++;
			break;
		}	
		k++;
	
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}





/*#include<stdio.h>
int main()
{
    char Q[5][6]= {"TRGSJ","XDOKI","M VLN","WPABE","UQHCF"};
    char s[10];
    int x=2,y=1;                 //空格的坐标
    scanf("%s",s);
    for(int i=0; s[i]!='0'&&s[i]!='\0'; i++)
    {
        switch(s[i])
        {
        case 'A':
        {
            if(x-1>=0)
            {
                Q[x][y]=Q[x-1][y];
                Q[x-1][y]=' ';
                --x;
            }
            else
               {
                printf("This puzzle has no final configuration.");
                return 0;
               }
        };
        break;
        case 'B':
        {
            if(x+1<=4)
            {
                Q[x][y]=Q[x+1][y];
                Q[x+1][y]=' ';
                ++x;
            }
            else
            {
                printf("This puzzle has no final configuration.");
                return 0;
            }
        };
        break;
        case 'L':
        {
            if(y-1>=0)
            {
                Q[x][y]=Q[x][y-1];
                Q[x][y-1]=' ';
                --y;
            }
            else
            {
                printf("This puzzle has no final configuration.");
                return 0;
            }
        };
        break;
        case 'R':
        {
            if(y+1<=4)
            {
                Q[x][y]=Q[x][y+1];
                Q[x][y+1]=' ';
                ++y;
            }
            else
            {
                printf("This puzzle has no final configuration.");
                return 0;
            }
        };
        break;
        }
    }
    for(int i=0; i<5; i++)
        printf("%s\n",Q[i]);
    return 0;
	*/
//原文链接：https://blog.csdn.net/myCsdn_Xm/article/details/81149799