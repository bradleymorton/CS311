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
	if(exponent==1)
	{
		return base;
	}
	else return base*exp(base, exponent-1);
}

int modExp(int a,
           int b,
           int n)
{
	long long aa=a;
	long long bb=b;
	long long nn=n;
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




