//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "VectorMath.h"

using namespace std;


//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
//																						//
//		Change Psuedocode into actual code												//
//		Figure out the best way to spawn enemies in waves								//
//		Figure out how to spawn more than one bullet and have separate hitboxes			//	
//		Write code to delete enemy hitboxes and sprites when they are desroyed			//
//		Write a destroy function that changes the sprite								//
//      to an explosion for 10-15 frames												//
//		Fix the gamestate switch case and the start and pause menus						//
//		Get user input at menus to start/ pause/ unpause game							//
//		Write code to allow for scrolling of the background image						//
//		Make a dynamic array for enemy health											//
//		Impliment classes into code
//		
//
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

const int iScreenWidth = 1280;
const int iScreenHeight = 720;

int iPlayerOneX;
int iPlayerOneY;
int iPlayerOneWidth;
int iPlayerOneHeight;
int iMouseX;
int iMouseY;

int PMenu = -1;
int BGImage = -1;

int i = 3;
int test = 1;


struct vector2
{
	float x;
	float y;
};

struct movableObject
{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};

movableObject player1 = {iScreenWidth/2, 300, 0, 0, -1 , iPlayerOneWidth, iPlayerOneHeight};

void UpdateObjectPosition(movableObject &obj) 
{
	obj.position = vectorAdd(obj.position, obj.speed);
}

void SpawnEnemy()
{
	//create new enemy and sprite
	//move enemy to random location
}

void MoveEnemy()
{
	//int i
	//enemy y = i
	//1++
}

void FireBullet()
{
	//create bullet and sprite at location in front of player
	//change bullet's speed to have it fly up the screen
}

void PlayerInput()
{
	GetMouseLocation(iMouseX, iMouseY);
	while(player1.position.x != iMouseX)
	{
		if(player1.position.x > iMouseX)
		{
			player1.position.x -= 1;
		}
		else if(player1.position.x < iMouseX)
		{
			player1.position.x += 1;
		}
	}
	while(player1.position.y != iMouseY)
	{
		if(player1.position.y > iMouseY)
		{
			player1.position.y -=1;
		}
		else if(player1.position.y < iMouseY)
		{
			player1.position.y +=1;
		}
	}
	while(GetMouseButtonDown(0) == true)
	{
		FireBullet();
	}
}

void EnemyHitbox()
{
	//if player bullet x is in between enemyx - 1/2 width and enemy x + 1/2 width AND
	//player bullet y is in between enemy y - 1/2 height and enemy y + 1/2 height
	//enemy takes damage
}

void PlayerHitbox()
{
	//if enemy bullet x is in between player x - 1/2 width and player x + 1/2 width AND
	//enemy bullet y is in between player y - 1/2 height and player y + 1/2 height
	//player is destroyed
}

void StartMenu()
{
	//create menu sprite
	//move menu sprite to middle of screen
	//draw option 1 string
	//draw option 2 string
	//draw option 3 string
}

void PauseMenu()
{
	
	PMenu = CreateSprite( "./images/PMenu.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(PMenu, iScreenWidth/2, iScreenHeight/2);
}

void InitGame()
{
	BGImage = CreateSprite ( "./images/BGImage.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(BGImage, iScreenWidth/2, iScreenHeight/2);
	player1.sprite = CreateSprite( "./images/Player.png", 200, 200, true );
}

void DrawGame()
{
	ClearScreen();
	DrawSprite(BGImage);
	DrawSprite(player1.sprite);
	//draw player bullets
	//draw enemy bullets
	//draw enemy sprites
	//draw score + lives string
	FrameworkUpdate();
}

void UpdateGame()
{
	//SpawnEnemy
	PlayerInput();
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);
	//update player bullet position
	//update enemy position
	//update enemy bullet position
	//check player collision
	//check enemy collision
	//move player bulllet sprites to player bullets' positions
	//MoveEnemy
	//move enemy sprites to enemy positions
	//move enemy bullet sprites to enemy bullets' sprites' positions
	//EnemyHitbox
	//PlayerHitbox
}
enum GameState
{
	Game = 1,
	Menu,
	Pause,
};


int main( int argc, char* argv[] )

{	
	Initialise(iScreenWidth, iScreenHeight, false );

	InitGame();

		do
		{
			switch(i)
			{
			case 1:
				PlayerInput();
				UpdateGame();
				DrawGame();
				break;
			case 2:
				StartMenu();
				break;
			case 3:
				PauseMenu();
				DrawSprite(PMenu);
				break;
			default:
				cout << "Error!\n";
				break;
			}
		}
		while(test == 1);
	
	
	Shutdown();

	return 0;
}

