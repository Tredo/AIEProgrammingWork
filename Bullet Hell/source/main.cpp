//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
#include "VectorMath.h"
#include "vector2d.h"
#include <algorithm>

using namespace std;


//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
//																						//
//		Change Psuedocode into actual code												//
//		Figure out the best way to spawn enemies in waves								//
//		Figure out how to spawn bullets and have separate hitboxes and sprites			//	
//		Write code to delete enemy hitboxes and sprites when they are desroyed			//
//		Write a destroy function that changes the sprite								//
//      to an explosion for 10-15 frames												//
//		Fix the gamestate switch case and the start and pause menus						//
//		*Get user input at menus to start/ pause/ unpause game							//
//		Write code to allow for scrolling of the background image						//
//		Make a dynamic array for enemy health											//
//		Impliment classes into code														//
//		post to c++ forum on how to convert vectormath into one class					//															//
//		HOW2CLASSES?																	//																				
//		Fix exiting the game															//
//																						//
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

const int iScreenWidth = 1280;
const int iScreenHeight = 720;

int iPlayerOneX;
int iPlayerOneY;
int iPlayerOneWidth;
int iPlayerOneHeight;
int iMouseX;
int iMouseY;

int PlayerB[100];

int k = 0;
int j = 0;


int PMenu = -1;
int BGImage = -1;
//switch case variable
int i = 0;
int test = 1;

struct movableObject
{
	Vector2D position;
	Vector2D speed;
	int sprite;
	int width;
	int height;
};

movableObject player1 = {iScreenWidth/2, 300, 1, 1, -1 , iPlayerOneWidth, iPlayerOneHeight};
movableObject cursor = {iScreenWidth/2, iScreenHeight/2, 0, 0, -1, 25, 25 };
movableObject pbutton = {iScreenWidth/2, 600, 0, 0, -1, 100, 50};
movableObject pbuttonhover = {iScreenWidth/2, 1000, 0, 0, -1, 100, 50};
movableObject bulletr = {iScreenWidth/2, -100, 0, 0, -1, 10, 10};
movableObject bulletl = {iScreenWidth/2, -100, 0, 0, -1, 10, 10};

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
		bulletr.position.x = player1.position.x + 15;
		bulletr.position.y = player1.position.y;
		bulletl.position.x = player1.position.x - 15;
		bulletl.position.y = player1.position.y;
		bulletr.speed.y = 1;
		bulletl.speed.y = 1;
}

void PlayerInput()
{
	GetMouseLocation(iMouseX, iMouseY);
	while(player1.position.x != iMouseX)
	{
		if(player1.position.x > iMouseX)
		{
			player1.position.x -= .5;
		}
		else if(player1.position.x < iMouseX)
		{
			player1.position.x += .5;
		}
	}
	while(player1.position.y != iMouseY)
	{
		if(player1.position.y > iMouseY)
		{
			player1.position.y -= .5;
		}
		else if(player1.position.y < iMouseY)
		{
			player1.position.y += .5;
		}
	}
	if(GetMouseButtonDown(0) == true)
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

void InitPMenu()
{
	PMenu = CreateSprite( "./images/PMenu.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(PMenu, iScreenWidth/2, iScreenHeight/2);
	pbuttonhover.sprite = CreateSprite("./images/playbuttonhover.png", 100, 50, true);
	pbutton.sprite = CreateSprite("./images/playbutton.png", 100, 50, true);
	cursor.sprite = CreateSprite( "./images/cursor.png", 25, 25, false);
	j++;
}

void Cursor()
{
	GetMouseLocation(iMouseX, iMouseY);
}

bool CheckMenuRClick()
{
	if(GetMouseButtonDown(0) == true)
		return true;
	else
		return false;
}

void DrawPauseMenu()
{
	ClearScreen();
	DrawSprite(PMenu);
	DrawSprite(pbutton.sprite);
	DrawSprite(pbuttonhover.sprite);
	DrawSprite(cursor.sprite);
	FrameworkUpdate();
}


void UpdatePauseMenu()
{
	Cursor();
	MoveSprite(cursor.sprite, iMouseX, iMouseY);
	MoveSprite(pbutton.sprite, pbutton.position.x, pbutton.position.y);
	if(iMouseX > pbutton.position.x - 75 && iMouseX < pbutton.position.x + 75 && iMouseY > pbutton.position.y - 50 && iMouseY < pbutton.position.y + 50)
	{
		MoveSprite(pbuttonhover.sprite, pbutton.position.x, pbutton.position.y);
	}
	else
	{
		MoveSprite(pbuttonhover.sprite, 1500, 1500);
	}

	if(CheckMenuRClick() == true && iMouseX > pbutton.position.x - 75 && iMouseX < pbutton.position.x + 75 && iMouseY > pbutton.position.y - 50 && iMouseY < pbutton.position.y + 50)
	{
		i = 1;
	}
	else
	{
		i = 3;
	}
	
}

void InitGame()
{
	BGImage = CreateSprite ( "./images/BGImage.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(BGImage, iScreenWidth/2, iScreenHeight/2);
	player1.sprite = CreateSprite( "./images/Player.png", 50, 50, true );
	/*bulletr.sprite = CreateSprite( "./images/bullet.png", 10, 10, true);
	bulletl.sprite = CreateSprite( "./images/bullet.png", 10, 10, true);*/
	k++;
}

void DrawGame()
{
	ClearScreen();
	DrawSprite(BGImage);
	/*DrawSprite(bulletr.sprite);
	DrawSprite(bulletl.sprite);*/
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
	/*MoveSprite(bulletr.sprite, bulletr.position.x, bulletr.position.y);
	MoveSprite(bulletl.sprite, bulletl.position.x, bulletl.position.y);*/
	if(IsKeyDown((KEY_SPECIAL+66)) == true)
	{
		i = 3;
	}
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
		
		do
		{
			switch(i)
			{
			case 1:

				if(k == 0)
				{
					InitGame();
				}
				else
				{
					UpdateGame();
					DrawGame();
				}
				break;
			case 2:
				StartMenu();
				break;
			case 3:
				if(j == 0)
				{
					InitPMenu();
				}
				else
				{
					UpdatePauseMenu();
					DrawPauseMenu();
				}
				break;
			default:
				if(j == 0)
				{
					InitPMenu();
				}
				else
				{
					UpdatePauseMenu();
					DrawPauseMenu();
				}
				break;
			}
		}
		while(test == 1);
	
	
	Shutdown();

	return 0;
}

