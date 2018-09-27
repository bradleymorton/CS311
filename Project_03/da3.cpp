// da3.cpp
// Bradley Morton
//Skeleton provided by Glenn G. Chappell
// 24 Sep 2018
//
// For CS 311 Fall 2018
// Source for Project 3 Functions

#include "da3.h"       // For Project 3 prototypes & templates


//This function is recursive and called by the 
//modExp function, and cannot be called by the 
//test program, or any other program linked to these
//files. 
int exp(std::size_t base, std::size_t exponent)
{
	if(exponent==1)
	{
		return base;
	}
	else return base*exp(base, exponent-1);
}


//This function is prototyped in da3.h, and is to be called by
//the test program.
int modExp(int a,
           int b,
           int n)
{
	std::size_t aa=a;
	std::size_t bb=b;
	std::size_t nn=n;
    if(n==1)
    {
    	return 0;
    }
    else if(b==0)
    {
    	return 1;
    }
    else if(b%2==0)
    {
    	return exp(aa,bb/2)*exp(aa,bb/2)%nn;
    }
    else
    {
    	return ((aa%nn)*(exp(aa,bb/2)*exp(aa,bb/2))%nn)%nn;
    }
}




