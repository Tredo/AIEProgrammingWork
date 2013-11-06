//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "Play.h"
#include "Bullet.h"
#include "Sprite.h"

bool GameRunning = true;
int k = 1;

// SO MANY LINKER ERRORS

int main( int argc, char* argv[] )
{	
	Play::InitGame();

	do
	{
		switch(k)
		{
		case 1:
			{
				Play::UpdateGame();
				Play::DrawGame();
			}
			break;
		case 2:
			{
			}
			break;
		case 3:
			{
			}
			break;
		default:
		{
		}
			break;
		}
	}
		while(GameRunning == true);
	
	Shutdown();

	return 0;
}

