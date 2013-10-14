// Reference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int Value = 12;
	int& ValueRef = Value;

	cout << ValueRef << "\n";

	ValueRef -= 4;

	cout << ValueRef << "\n";
	
	return 0;
}

