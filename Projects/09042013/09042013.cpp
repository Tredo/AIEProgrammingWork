// 09042013.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
int iNumOne = 0;
int iNumTwo = 0;
	
for ( iNumTwo = 0; iNumTwo <= 9; iNumTwo++ )
{
	for( iNumOne = 0; iNumOne <= 9; iNumOne++)
	{
		cout << iNumOne;
	}
		cout << endl;
}

}