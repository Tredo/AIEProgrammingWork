// Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Point2D
{
	float x, y;	
};

struct player
{
	int iPScore;
	int iPHealth;
	Point2D PlayerPosition;
	Point2D PlayerDirection;

};

struct grunt
{
	int iGHealth;
	int iGBullets;
	Point2D GruntPosition;
	Point2D GruntTarget;
};

struct triangle
{
	Point2D X;
	Point2D Y;
	Point2D Z;
	char Color;
};



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "It worked!";
	return 0;
}

