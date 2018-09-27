// da3.cpp
// Bradley Morton
//Skeleton provided by Glenn G. Chappell
// 24 Sep 2018
//
// For CS 311 Fall 2018
// Source for Project 3 Functions

#include "da3.h"       // For Project 3 prototypes & templates


//This function is recursive and called
int exp(int base, int exponent)
{
	if(exponent==0)
	{
		return 1;
	}
	else return base*exp(base, exponent-1);
}

int modExp(int a,
           int b,
           int n)
{
    if(n==1)
    {
    	return 0;
    }
    else if(b==0)
    {
    	return 1;
    }
    else
    {
    	return exp(a,b/2);
    }
}




