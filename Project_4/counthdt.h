//counthdt.h
//Bradley Morton
//9/30/18
//Contains prototypes of functions for Assignment 4


#ifndef COUNTHDT_H
#define COUNTHDT_H

#include <vector>
using std::vector;


//Main function that is called by the testing program
//Preconditions-dim_x and dim_y must be greater than or euqual to 1,
//and at least one of dim_x and dim_y must be odd. 
//Additionally, both forbid*_x values must be less than or equal to dim_x,
//with the same for dim_y. Further, both forbid*_* sets must be distinct,
//at least one of the values must be different. 
int countHDT(int dim_x, int dim_y, int forbid1_x, int forbid1_y, int forbid2_x, int forbid2_y);

//This is the workhorse function that gets called by the countHDT function.
//This function takes input formatted by the aforementioned function, then
//formats it as input to this function, which then performs operations and calls itself. 
//The precondidtions are that the countHDT preconditions concerning inputs are met, as 
//those inputs provide the format for this function. 
int countHDT_recurse(vector<vector<int>> board, int dim_x, int dim_y, int squaresLeft);






#endif