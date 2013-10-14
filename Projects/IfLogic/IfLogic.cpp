// IfLogic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char cval = 'a';
	int aCnt = 0;
	int eCnt = 0;
	int iouCnt = 0;

	switch (cval)
	{
	case 'a': 
		aCnt++;
		break;
	case 'e': 
		eCnt++;
		break;
	default: 
		iouCnt++;
		break;
	}
	cout << aCnt << endl;
	cout << eCnt << endl;
	cout << iouCnt << endl;
	return 0;
}

