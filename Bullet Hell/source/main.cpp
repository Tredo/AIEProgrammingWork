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
//		*Impliment classes into code													//
//		*post to c++ forum on how to convert vectormath into one class					//															//
//		HOW2CLASSES?																	//																				
//		Fix exiting the game															//
//		Create dynamic array for both right and left bullet								//
//		Play more Touhou																//
//		Create large array for left and right bullets and a for loop to fire them       //																				//
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

const int iScreenWidth = 700;
const int iScreenHeight = 900;

int iPlayerOneX;
int iPlayerOneY;
int iPlayerOneWidth = 100;
int iPlayerOneHeight = 100;
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



movableObject bulletr;
movableObject player;
movableObject cursor;
movableObject pbutton;
movableObject pbuttonhover;
movableObject qbutton;
movableObject qbuttonhover;


movableObject bulletl;

//void UpdateObjectPosition(movableObject &obj) 
//{
//	obj.position = vectorAdd(obj.position, obj.speed);
//}

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
		bulletr.position.setX(player.position.getX() + 15);
		bulletr.position.setY(player.position.getY());
		bulletl.position.setX(player.position.getX() - 15);
		bulletl.position.setY(player.position.getY());
		bulletr.speed.setY(2);
		bulletl.speed.setY(2);
}

void PlayerInput()
{
	GetMouseLocation(iMouseX, iMouseY);
	while(player.position.getX() != iMouseX)
	{
		if(player.position.getX() > iMouseX)
		{
			player.position.setX(player.position.getX() - .5);
		}
		else if(player.position.getX() < iMouseX)
		{
			player.position.setX(player.position.getX() + .5);
		}
	}
	while(player.position.getY() != iMouseY)
	{
		if(player.position.getY() > iMouseY)
		{
			player.position.setY(player.position.getY() - .5);
		}
		else if(player.position.getY() < iMouseY)
		{
			player.position.setY(player.position.getY() + .5);
		}
	}
	if(GetMouseButtonDown(0) == true)
	{
		FireBullet();
	}
}

void EnemyHitbox()
{
	//need for loop for enemy array and for player bullet array
	//if player bullet x is in between enemyx - 1/2 width and enemy x + 1/2 width AND
	//player bullet y is in between enemy y - 1/2 height and enemy y + 1/2 height
	//enemy takes damage
}

void PlayerHitbox()
{
	//need for loop for enemy bullet array checking
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
	qbutton.position.setX(iScreenWidth/2);
	qbutton.position.setY(650);
	qbutton.width = 100;
	qbutton.height = 50;
	qbuttonhover.position.setX(iScreenWidth/2);
	qbuttonhover.position.setY(2000);
	qbuttonhover.width = 100;
	qbuttonhover.height = 50;
	pbutton.position.setX(iScreenWidth/2);
	pbutton.position.setY(600);
	pbutton.width = 100;
	pbutton.height = 50;
	pbuttonhover.position.setX(iScreenWidth/2);
	pbuttonhover.position.setY(2000);
	pbuttonhover.width = 100;
	pbuttonhover.height = 50;
	cursor.position.setX(0);
	cursor.position.setY(0);
	cursor.height = 25;
	cursor.width = 25;
	PMenu = CreateSprite( "./images/PMenu.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(PMenu, iScreenWidth/2, iScreenHeight/2);
	pbuttonhover.sprite = CreateSprite("./images/playbuttonhover.png", 100, 50, true);
	pbutton.sprite = CreateSprite("./images/playbutton.png", 100, 50, true);
	qbuttonhover.sprite = CreateSprite("./images/quitbuttonhover.png", 100, 50, true);
	qbutton.sprite = CreateSprite("./images/quitbutton.png", 100, 50, true);
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
	DrawSprite(qbutton.sprite);
	DrawSprite(qbuttonhover.sprite);
	DrawSprite(cursor.sprite);
	FrameworkUpdate();
}


void UpdatePauseMenu()
{
	Cursor();
	MoveSprite(cursor.sprite, iMouseX, iMouseY);
	MoveSprite(pbutton.sprite, pbutton.position.getX(), pbutton.position.getY());
	MoveSprite(qbutton.sprite, qbutton.position.getX(), qbutton.position.getY());
	if(iMouseX > (pbutton.position.getX() - 50) && iMouseX < (pbutton.position.getX() + 50) && iMouseY > (pbutton.position.getY() - 25) && iMouseY < (pbutton.position.getY() + 25))
	{
		MoveSprite(pbuttonhover.sprite, pbutton.position.getX(), pbutton.position.getY());
	}
	else
	{
		MoveSprite(pbuttonhover.sprite, 1500, 1500);
	}

	if(CheckMenuRClick() == true && iMouseX > (pbutton.position.getX() - 50) && iMouseX < (pbutton.position.getX() + 50) && iMouseY > (pbutton.position.getY() - 25) && iMouseY < (pbutton.position.getY() + 25))
	{
		i = 1;
	}
	else
	{
		i = 3;
	}

	if(iMouseX > (qbutton.position.getX() - 50) && iMouseX < (qbutton.position.getX() + 50) && iMouseY > (qbutton.position.getY() - 25) && iMouseY < (qbutton.position.getY() + 25))
	{
		MoveSprite(qbuttonhover.sprite, qbutton.position.getX(), qbutton.position.getY());
	}
	else
	{
		MoveSprite(qbuttonhover.sprite, 1500, 1500);
	}

	if(CheckMenuRClick() == true && iMouseX > (qbutton.position.getX() - 50) && iMouseX < (qbutton.position.getX() + 50) && iMouseY > (qbutton.position.getY() - 25) && iMouseY < (qbutton.position.getY() + 25))
	{
		test = 0;
	}
	
}

void InitGame()
{
	player.position.setX(iScreenWidth/2);
	player.position.setY(500);
	player.height = iPlayerOneHeight;
	player.width = iPlayerOneWidth;
	BGImage = CreateSprite ( "./images/BGImage.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(BGImage, iScreenWidth/2, iScreenHeight/2);
	player.sprite = CreateSprite( "./images/Player.png", iPlayerOneWidth, iPlayerOneHeight, true );
	bulletr.sprite = CreateSprite( "./images/player bullet.png", 7, 30, true);
	bulletl.sprite = CreateSprite( "./images/player bullet.png", 7, 30, true);
	k++;
}

void DrawGame()
{
	ClearScreen();
	DrawSprite(BGImage);
	DrawSprite(bulletr.sprite);
	DrawSprite(bulletl.sprite);
	DrawSprite(player.sprite);
	//draw player bullets
	//draw enemy bullets
	//draw enemy sprites
	//draw score + lives string
	FrameworkUpdate();
}
void UpdateBullet()
{
	bulletr.position.setX(bulletr.position.getX() - bulletr.speed.getX());
	bulletr.position.setY(bulletr.position.getY() - bulletr.speed.getY());
	bulletl.position.setX(bulletl.position.getX() - bulletl.speed.getX());
	bulletl.position.setY(bulletl.position.getY() - bulletl.speed.getY());
}

void UpdateGame()
{
	//SpawnEnemy
	PlayerInput();
	MoveSprite(player.sprite, player.position.getX(), player.position.getY());
	MoveSprite(bulletr.sprite, bulletr.position.getX(), bulletr.position.getY());
	MoveSprite(bulletl.sprite, bulletl.position.getX(), bulletl.position.getY());
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
					UpdateBullet();
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

