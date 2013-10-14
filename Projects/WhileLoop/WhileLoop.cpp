// WhileLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctype.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	bool loop = true;
	int value = 0;
	int num = 0;
	char oper = 'a';
	while(loop)

	{
		cout << "please type a number: ";
		int someVal;

		while(!(cin >> num)) {
			cin.clear();
			cout << "Not a number! Try again.";
			cin.ignore(10000,'\n');
		}
		cout << "What operation would you like to use?\n [A]dd [S]ubtract [M]ultiply [D]ivide" << endl;
		cin >> oper;
		switch (oper)
		{
		case 'a':
			value = value += num;
			cout << "Successfully added!" << endl;
			break;
		case 's':
			value = value -= num;
			cout << "Successfully subtracted!" << endl;
			break;
		case 'm':
			value = value * num;
			cout << "Successfully multiplied!" << endl;
			break;
		case 'd':
			value = value / num;
			cout << "Successfully divided!" << endl;
			break;
		default:
			cout << "Not a valid operation!" << endl; 
			break;
		}
		cout << "Your current total is: " << value << endl << "Do you wish to continue?" << endl << "[Y]es [N]o" << endl;
		cin >> oper;
			switch (oper)
			{
			case 'y':
				loop = true;
				break;
			case 'n':
				loop = false;
				break;
			default:
				cout << "Not a valid operation!" << endl;
				break;
			}
	}

	return 0;
}

