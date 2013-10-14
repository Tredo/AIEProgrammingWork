// Function Overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void Max(int a, int b)
{
	if(a > b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void Max(unsigned int a, unsigned int b)
{
	if(a > b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void Max(float a, float b)
{
	if(a > b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void Max(double a, double b)
{
	if(a > b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void Min(int a, int b)
{
	if(a < b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void Min(unsigned int a, unsigned int b)
{
	if(a < b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void Min(float a, float b)
{
	if(a < b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

void Min(double a, double b)
{
	if(a < b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	float a = 5;
	float b = 9;

	Max(a,b);
	Min(a,b);

	return 0;
}

