//counthdt.cpp
//Bradley Morton
//9/30/18
//Contains definitions of functions for Assignment 4


#include "counthdt.h" //For prototypes
#include <vector>
using std::vector;
#include <iostream>


int countHDT(int dim_x, int dim_y, int forbid1_x, int forbid1_y, int forbid2_x, int forbid2_y)
{

	vector<vector<int>> board(dim_x, std::vector<int>(dim_y,0));
	board[forbid1_x][forbid1_y]=1;
	board[forbid2_x][forbid2_y]=1;
	int total=countHDT_recurse(board, dim_x, dim_y, dim_y*dim_x-2);
	return total;
}

int countHDT_recurse(vector<vector<int>> board, int dim_x, int dim_y, int squaresLeft)
{	

	if(squaresLeft==0)
	{
		return 1;
	}

	int total=0;
	for(int i=0; i<dim_x; ++i)
	{
		for(int j=0; j<dim_y; ++j)
		{
			if(board[i][j]==1)
					continue;
			if(i+1<dim_x)
			{
				if(board[i+1][j]==0)
				{
					board[i][j]=1;
					board[i+1][j]=1;
					total+= countHDT_recurse(board, dim_x, dim_y, squaresLeft-2);
					board[i][j]=0;
					board[i+1][j]=0;
				}	
			}
			if(j+1<dim_y)
				if(board[i][j+1]==0)
				{
					board[i][j]=1;
					board[i][j+1]=1;
					total+= countHDT_recurse(board, dim_x, dim_y, squaresLeft-2);
					board[i][j]=0;
					board[i][j+1]=0;
				}	
			return total;		
		}
	}
	return 0;

}

