//counthdt.cpp
//Bradley Morton
//9/30/18
//Contains definitions of functions for Assignment 4


#include "counthdt.h" //For prototypes
#include <vector>
using std::vector;


int countHDT(int dim_x, int dim_y, int forbid1_x, int forbid1_y, int forbid2_x, int forbid2_y)
{

	vector<vector<int>> board(dim_x, std::vector<int>(dim_y,0));
	board[forbid1_x][forbid1_y]=1;
	board[forbid2_x][forbid2_y]=1;
	return 0;
}

int countHDT_recurse(vector<vector<int>> board, int dim_x, int dim_y, int squaresLeft)
{

	if(squaresLeft==0)
	{
		return 1;
	}
	else
	{

		//Stuff
		return countHDT_recurse(board, dim_x, dim_y, squaresLeft-2);
	}
	return 0;

}

