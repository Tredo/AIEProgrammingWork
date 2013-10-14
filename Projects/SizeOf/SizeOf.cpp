// SizeOf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	float num = 0;
	float multi = 9.876557;
	float divi = 5.432194;
	float solution = 0;
	cin >> num;
	solution = num * multi;
	solution = solution / divi;
	solution = solution * divi;
	solution = solution / multi;
	
	cout << solution << endl;

	return 0;
}

