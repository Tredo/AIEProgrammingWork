// Stack and Heap Memory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;
	int temp;
	char* input = new char[10];
	
	cin >> input;
	for((i=0); i< (15); i++)
	{
		for (j = (i+1); j < 16; j++)
		{
			if(input[i] > input[j])
			{
				temp= input[i];
				input[i] = input [j];
				input[j]= temp;
			}
		}
	}
	cout << input;
	delete [] input;
	return 0;
}

