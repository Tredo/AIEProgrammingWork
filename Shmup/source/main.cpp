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

// BULLETS DONT FIRE WHY?

int main( int argc, char* argv[] )
{	
	
	Play fl;
	Initialise(800, 1000, false,"asdfkhasdf");
	fl.InitGame();
		
	do
	{
		switch(k)
		{
		case 1:
			{
				fl.EnemyWaveOne();
				fl.EnemyHitbox();
				fl.UpdateGame();
				fl.DrawGame();
				
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

