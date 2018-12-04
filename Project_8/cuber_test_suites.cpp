// cuber_test_suites.cpp
// Andrew Adler, Bradley Morton, Ian Ferguson
// Skeleton provided by Glenn G. Chappell
// 3 Dec 2018
//
// For CS 311 Fall 2018
// Tests for class Cuber: test suites
// For Project 8, Exercise B
// Uses the "Catch" unit-testing framework, version 2
// Requires cuber_test_main.cpp, catch.hpp, cuber.h

// Includes for code to be tested
#include "cuber.h"         // For class Cuber
#include "cuber.h"         // Double inclusion test

#define CATCH_CONFIG_FAST_COMPILE
                             // Disable some features for faster compile
#include "catch.hpp"         // For the "Catch" unit-testing framework

// Additional includes for this test program


// *********************************************************************
// Test Cases
// *********************************************************************

//Tests to see if 
TEST_CASE("Positive ints")
{
    Cuber cc;
    {
    	INFO("5 cubed is 125");
    	REQUIRE(cc(5)==125);
    }

    {
    	INFO("10 cubed is 1000");
    	REQUIRE(cc(10)==1000);
    }

    {
    	INFO("15 cubed is 3375");
    	REQUIRE(cc(15)==3375);
    }

    {
    	INFO("20 cubed is 8000");
    	REQUIRE(cc(20)==8000);
    }
}

TEST_CASE("Negative ints")
{
    Cuber cc;
    {
    	INFO("-5 cubed is -125");
    	REQUIRE(cc(-5)==-125);
    }

    {
    	INFO("-10 cubed is -1000");
    	REQUIRE(cc(-10)==-1000);
    }

    {
    	INFO("-15 cubed is -3375");
    	REQUIRE(cc(-15)==-3375);
    }

    {
    	INFO("-20 cubed is -8000");
    	REQUIRE(cc(-20)==-8000);
    }
}

TEST_CASE("Positive doubles")
{
	Cuber cc;
	{
		INFO("1.1 cubed is 1.331");
		REQUIRE(cc(1.1)==Approx(1.331));
	}

	{
		INFO("2.2 cubed is 10.648");
		REQUIRE(cc(2.2)==Approx(10.648));
	}

	{
		INFO("3.3 cubed is 35.937");
		REQUIRE(cc(3.3)==Approx(35.937));
	}

	{
		INFO("4.4 cubed is 85.184");
		REQUIRE(cc(4.4)==Approx(85.184));
	}
}


TEST_CASE("Negative doubles")
{
	Cuber cc;
	{
		INFO("-1.1 cubed is -1.331");
		REQUIRE(cc(-1.1)==Approx(-1.331));
	}

	{
		INFO("-2.2 cubed is -10.648");
		REQUIRE(cc(-2.2)==Approx(-10.648));
	}

	{
		INFO("-3.3 cubed is -35.937");
		REQUIRE(cc(-3.3)==Approx(-35.937));
	}

	{
		INFO("-4.4 cubed is -85.184");
		REQUIRE(cc(-4.4)==Approx(-85.184));
	}

}

TEST_CASE("Const Cubers")
{
    const Cuber cc{};
	{
		INFO("5 cubed is 125");
		REQUIRE(cc(5)==125);
	}
}
