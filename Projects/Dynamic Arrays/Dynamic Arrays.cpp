// Dynamic Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

char Array[10];



void Grow()
{
	//size of block of memory to be copied
	int nBytes = 80;
	//size of new array
	int i = 20;
	//creates temp array with size of i
	char* TempArray = new char [i];
	//moves values from original input array to temp array
	memcpy(Array, TempArray, nBytes);
	//creates dynamic array to store values that is twice as big
	char* DynamicArray = new char [i*2];
	//moves values from temp array to dynamic array
	memcpy(TempArray, DynamicArray, nBytes);
	//deletes temp array
	delete [] TempArray;
	//displays values of dynamic array
	cout << DynamicArray;
	//deletes dynamic array
	delete [] DynamicArray;
	//doubles default size of array
	i *= 2;
}



void Input()
{
	cout << "Input some shit!\n";
	cin >> Array;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Input();
	Grow();
	return 0;
}

