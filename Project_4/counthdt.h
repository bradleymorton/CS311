//counthdt.h
//Bradley Morton
//9/30/18
//Contains prototypes of functions for Assignment 4


#ifndef COUNTHDT_H
#define COUNTHDT_H

#include <vector>
using std::vector;

int countHDT(int dim_x, int dim_y, int forbid1_x, int forbid1_y, int forbid2_x, int forbid2_y);


int countHDT_recurse(vector<vector<int>> board, int dim_x, int dim_y, int squaresLeft);






#endif