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
//		*post to c++ forum on how to convert vectormath into one class					//															
//		*HOW2CLASSES? convert sprites from movableObject to Sprite::Sprite				//																				
//		*Fix exiting the game															//
//		Create dynamic array for both right and left bullet								//
//		Play more Touhou																//
//		*Write a seek function that will move by the mag of vectors						//
//		SIMPLIFY THIS SHIT																//
//																						//												
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//

const int iScreenWidth = 800;
const int iScreenHeight = 1000;

int iPlayerOneX;
int iPlayerOneY;
int iPlayerOneWidth = 100;
int iPlayerOneHeight = 100;
int iMouseX;
int iMouseY;

int k = 0;
int j = 0;


int PMenu = -1;
int BGImage = -1;
//switch case variable
int i = 0;
int test = 1;


Sprite bulletr;
Sprite bulletl;
Sprite player;
Sprite cursor;
Sprite pbutton;
Sprite pbuttonhover;
Sprite qbutton;
Sprite qbuttonhover;




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
		bulletr.setX(player.getX() + 20);
		bulletr.setY(player.getY() + 10);
		bulletl.setX(player.getX() - 20);
		bulletl.setY(player.getY() + 10);
		bulletr.setSpeedY(2);
		bulletl.setSpeedY(2);
}

void PlayerInput()
{
	GetMouseLocation(iMouseX, iMouseY);
	if(player.getX() != iMouseX)
	{
		if(player.getX() > iMouseX)
		{
			player.setX(player.getX() - ((player.getX() - iMouseX)/250));
		}
		else if(player.getX() < iMouseX)
		{
			player.setX(player.getX() - ((player.getX() - iMouseX)/250));
		}
	}
	if(player.getY() != iMouseY)
	{
		if(player.getY() > iMouseY)
		{
			player.setY(player.getY() - ((player.getY() - iMouseY)/250));
		}
		else if(player.getY() < iMouseY)
		{
			player.setY(player.getY() - ((player.getY() - iMouseY)/250));
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
	qbutton.setX(iScreenWidth/2);
	qbutton.setY(650);
	qbutton.setWidth(100);
	qbutton.setHeight(50);
	qbuttonhover.setX(iScreenWidth/2);
	qbuttonhover.setY(2000);
	qbuttonhover.setWidth(100);
	qbuttonhover.setHeight(50);
	pbutton.setX(iScreenWidth/2);
	pbutton.setY(600);
	pbutton.setWidth(100);
	pbutton.setHeight(50);
	pbuttonhover.setX(iScreenWidth/2);
	pbuttonhover.setY(2000);
	pbuttonhover.setWidth(100);
	pbuttonhover.setHeight(50);
	cursor.setX(0);
	cursor.setY(0);
	cursor.setHeight(25);
	cursor.setWidth(25);
	PMenu = CreateSprite( "./images/PMenu.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(PMenu, iScreenWidth/2, iScreenHeight/2);
	pbuttonhover.setSprite( CreateSprite("./images/playbuttonhover.png", 100, 50, true));
	pbutton.setSprite( CreateSprite("./images/playbutton.png", 100, 50, true));
	qbuttonhover.setSprite( CreateSprite("./images/quitbuttonhover.png", 100, 50, true));
	qbutton.setSprite( CreateSprite("./images/quitbutton.png", 100, 50, true));
	cursor.setSprite( CreateSprite( "./images/cursor.png", 25, 25, false));
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
	DrawSprite(pbutton.getSprite());
	DrawSprite(pbuttonhover.getSprite());
	DrawSprite(qbutton.getSprite());
	DrawSprite(qbuttonhover.getSprite());
	DrawSprite(cursor.getSprite());
	FrameworkUpdate();
}


void UpdatePauseMenu()
{
	Cursor();
	MoveSprite(cursor.getSprite(), iMouseX, iMouseY);
	MoveSprite(pbutton.getSprite(), pbutton.getX(), pbutton.getY());
	MoveSprite(qbutton.getSprite(), qbutton.getX(), qbutton.getY());
	if(iMouseX > (pbutton.getX() - 50) && iMouseX < (pbutton.getX() + 50) && iMouseY > (pbutton.getY() - 25) && iMouseY < (pbutton.getY() + 25))
	{
		MoveSprite(pbuttonhover.getSprite(), pbutton.getX(), pbutton.getY());
	}
	else
	{
		MoveSprite(pbuttonhover.getSprite(), 1500, 1500);
	}

	if(CheckMenuRClick() == true && iMouseX > (pbutton.getX() - 50) && iMouseX < (pbutton.getX() + 50) && iMouseY > (pbutton.getY() - 25) && iMouseY < (pbutton.getY() + 25))
	{
		i = 1;
	}
	else
	{
		i = 3;
	}

	if(iMouseX > (qbutton.getX() - 50) && iMouseX < (qbutton.getX() + 50) && iMouseY > (qbutton.getY() - 25) && iMouseY < (qbutton.getY() + 25))
	{
		MoveSprite(qbuttonhover.getSprite(), qbutton.getX(), qbutton.getY());
	}
	else
	{
		MoveSprite(qbuttonhover.getSprite(), 1500, 1500);
	}

	if(CheckMenuRClick() == true && iMouseX > (qbutton.getX() - 50) && iMouseX < (qbutton.getX() + 50) && iMouseY > (qbutton.getY() - 25) && iMouseY < (qbutton.getY() + 25))
	{
		test = 0;
	}
	
}

void InitGame()
{
	player.setX(iScreenWidth/2);
	player.setY(500);
	player.setHeight(iPlayerOneHeight);
	player.setWidth(iPlayerOneWidth);
	BGImage = CreateSprite ( "./images/BGImage.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(BGImage, iScreenWidth/2, iScreenHeight/2);
	player.setSprite( CreateSprite( "./images/Player.png", iPlayerOneWidth, iPlayerOneHeight, true ));
	bulletr.setSprite( CreateSprite( "./images/player bullet.png", 7, 30, true));
	bulletl.setSprite( CreateSprite( "./images/player bullet.png", 7, 30, true));
	k++;
}

void DrawGame()
{
	ClearScreen();
	DrawSprite(BGImage);
	DrawSprite(bulletr.getSprite());
	DrawSprite(bulletl.getSprite());
	DrawSprite(player.getSprite());
	//draw player bullets
	//draw enemy bullets
	//draw enemy sprites
	//draw score + lives string
	FrameworkUpdate();
}
void UpdateBullet()
{
	bulletr.setX(bulletr.getX() - bulletr.getSpeedX());
	bulletr.setY(bulletr.getY() - bulletr.getSpeedY());
	bulletl.setX(bulletl.getX() - bulletl.getSpeedX());
	bulletl.setY(bulletl.getY() - bulletl.getSpeedY());
}

void UpdateGame()
{
	//SpawnEnemy
	PlayerInput();
	MoveSprite(player.getSprite(), player.getX(), player.getY());
	MoveSprite(bulletr.getSprite(), bulletr.getX(), bulletr.getY());
	MoveSprite(bulletl.getSprite(), bulletl.getX(), bulletl.getY());
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

