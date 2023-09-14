/*#include<stdio.h>
#include<stdlib.h>
int main()
{
	int grid[5][5] = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
	int i=0,j=0,k=0;
	while(1)
	{
		
		if(grid[i+2][j+1]==k)
		{
			i+=2;j+=1;
		}
		else if(grid[i-2][j+1]==k)
		{
			i-=2;j+=1;
		}
		else if(grid[i+2][j-1]==k)
		{
			i+=2;j-=1;
		}
		else if(grid[i-2][j+1]==k)
		{
			i-=2;j+=1;
		}
		else if(grid[i+1][j+2]==k)
		{
			i+=1;j+=2;
		}
		else if(grid[i-1][j+2]==k)
		{
			i-=1;j+=2;
		}
		else if(grid[i+1][j-2]=k)
		{
			i+=1;j-=2;
		}
		else if(grid[i-1][j-2]=k)
		{
			i-=1;j-=2;
		}
		else
		{
			printf("false");
			break;
		}
		if(k==24)
		{
			printf("true");
		  break;
		}
	k++;
	}
	return 0;
}*/

bool checkValidGrid(int** grid, int gridSize, int* gridColSize) {
    if (grid[0][0] != 0) {
        return false;
    }
    int n = gridSize;
    int indices[n * n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            indices[grid[i][j]][0] = i;
            indices[grid[i][j]][1] = j;
        }
    }
    for (int i = 1; i < n * n; i++) {
        int dx = abs(indices[i][0] - indices[i - 1][0]);
        int dy = abs(indices[i][1] - indices[i - 1][1]);
        if (dx * dy != 2) {
            return false;
        }
    }
    return true;
}

