// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Hello World!\n";
	int age = 0;
	int randNum = 0;
	char name[16] = "";
	char input[16] = "";
	float score = 0;
	bool win = false;
	float division = 0.76f;
	double multi = 1.34;
	cout << sizeof(int);
	cout << "Let me ask you a couple of questions...\n";
	cout << "What is your name?\n";
	cin >> name;
	cout << name << "... Ok... And how old are you?\n";
	cin >> age;
	cout << age << "??? Wow... You're over the hill...\n";
	cout << "Now type the first number that comes to mind!\n";
	cin >> randNum;
	cout << "alright, let me assess your level of awesomeness... One sec...\n";
	score = age * randNum / division * multi;
	cout << "Your score is: " << score << "!\n";
	if (score >= 1000)
	{
		win = true;
		cout << "WOOT WOOT! You win!\n";
	}


	return 0;
}

