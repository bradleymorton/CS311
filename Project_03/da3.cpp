// da3.cpp
// Bradley Morton
//Skeleton provided by Glenn G. Chappell
// 24 Sep 2018
//
// For CS 311 Fall 2018
// Source for Project 3 Functions

#include "da3.h"       // For Project 3 prototypes & templates



//This function is prototyped in da3.h, and is to be called by
//the test program.
int modExp(int a,
           int b,
           int n)
{
	a=a%n;
    if(b==0&&n%2==0)
    {
    	return 1;
    }
    else if(b==0&&n%2==1)
    {
    	return 0;
    }
    else if(b==1)
    {
    	return a;
    }
    else if(b%2==0)
    {
    	return modExp(a*a%n,b/2,n);
    }
    else
    {
    	return a*modExp(a,b-1,n)%n;
    }
}




