// Algorithm Design and Function Psuedocode.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include <iostream>

int main()
{
	int iDay,iMonth;
	bool bCorrectDate=false;
	std::cout<< "What is the current month number? (1-12)";
	std::cin>>iMonth;
		while(iMonth<1||iMonth>12)
		{
			std::cout<<"Please enter a valid month (1-12): "; 
			std::cin>>iMonth;}std::cout<<"What is the current date?(1-31)";
			std::cin>>iDay;
				while(!bCorrectDate)
				{
					switch(iMonth)
					{
					case 9:
					case 4:
					case 6:
					case 11:
						if(iDay>0&&iDay<31)bCorrectDate=true;
						break;
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						if(iDay>0&&iDay<32)bCorrectDate=true;
						break;
					case 2:
						if(iDay>0&&iDay<29)bCorrectDate=true;
						break;
					}
				if(!bCorrectDate)
					{
						std::cout<<"Please enter a correct date: ";
						std::cin >> iDay;
					}
				}
}

/*
int iScreenX = 600;
int iScreenY = 800:

int iPlayerW = 50;
int iPlayerH = 50;

struct position()
	{
		float x;
		float y;
	}

void playermove()
	{
		if(IsKeyDown 'W')
			player.position.y += 1;
		else if(isKeyDown 'S')
			player.position.y -= 1;
		else if(IsKeyDown 'A')
			player.position.x += 1;
		else if(IsKeyDown 'D')
			player.position.x -= 1;
	}

void wraparound()
	{
		if(player.position.x > iScreenX)
			player.position.x = 1;
		else if(player.position.x = 0)
			player.position.x = iScreenX - 1;
		else if(player.position.y > iScreenY)
			player.position.y = 1;
		else if(player.position.y = 0)
			player.position.y = iScreenY - 1;
	}

int xDif = abs(ghostx - pacmanx);
int yDif = abs(ghosty - pacmany);

while xDif > yDif
	