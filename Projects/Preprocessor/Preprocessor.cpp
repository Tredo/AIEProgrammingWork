// Preprocessor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))

int _tmain(int argc, _TCHAR* argv[])
{
		
	cout << Max(9,5) << endl;

	return 0;
}

