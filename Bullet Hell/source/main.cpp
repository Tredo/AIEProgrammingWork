//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>

using namespace std;


const int iScreenWidth = 1280;
const int iScreenHeight = 780;

int iPlayerOneX;
int iPlayerOneY;
int iPlayerOneWidth;
int iPlayerOneHeight;
//movableObject player1;

int i = 3;


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
	//get mouse location
	//while players x location != mouse x location
	//if players x location is > mouse x then player x location -1
	//else if players x location is <  mouse x then player x location +1
	//while players y location != mouse y location
	//if players y location is > mouse y then player y location -1
	//else if players y location < mouse y then player y location +1
	//while mouse left click is down firebullet
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

}

void PauseMenu()
{
	int PMenu = -1;
	PMenu = CreateSprite( "./images/PMenu.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(PMenu, iScreenWidth/2, iScreenHeight/2);
}

void InitGame()
{
	//create background sprite
	//move background sprite to middle of screen
	//create player sprite
}

void DrawGame()
{
	//draw background
	//draw player bullets
	//draw enemy bullets
	//draw player sprite
	//draw enemy sprites
	//draw score + lives string
	//clear screen
	//frameworkupdate
}

void UpdateGame()
{
	//SpawnEnemy
	//update player position
	//update player bullet position
	//update enemy position
	//update enemy bullet position
	//check player collision
	//check enemy collision
	//move player sprite to player position
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

		
	switch(i)
	{
	case 1:
		PlayerInput;
		UpdateGame;
		DrawGame;
		break;
	case 2:
		StartMenu();
		break;
	case 3:
		PauseMenu();
		break;
	default:
		cout << "Error!\n";
		break;
	}

	return 0;
}

