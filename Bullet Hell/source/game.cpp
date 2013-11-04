#include "vector2d.h"
#include "AIE.h"
#include "game.h"
#include "bullet.h"
int BGImage = -1;

Bullet bulletr[25];
Bullet bulletl[25];
Sprite player;

int i, k;

const int iScreenWidth = 800;
const int iScreenHeight = 1000;

void InitGame()
{
	
	player.setX(iScreenWidth/2);
	player.setY(500);
	player.setHeight(100);
	player.setWidth(100);
	BGImage = CreateSprite ( "./images/BGImage.png", iScreenWidth, iScreenHeight, true );
	MoveSprite(BGImage, iScreenWidth/2, iScreenHeight/2);
	player.setSprite( CreateSprite( "./images/Player.png", player.getWidth(), player.getHeight(), true ));
	/*for(int u=0; u <=10; u++)
	{
		bulletr[u].setSprite( CreateSprite( "./images/player bullet.png", 7, 15, true ));
		bulletl[u].setSprite( CreateSprite( "./images/player bullet.png", 7, 15, true ));
	}
	*/
}

void FireBullet()
{
	int x = 0;
	
	bulletr[x].setX(player.getX());
	bulletr[x].setY(player.getY());
	bulletr[x].setSpeedX(1);

	x++;	 
}

void UpdateBullet()
{
	for(int y=0; y <=25; y++)
	{
		bulletr[y].update();
		bulletl[y].update();
	}
}

void PlayerInput()
{
	int iMouseX;
	int iMouseY;
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


void UpdateGame()
{
	//SpawnEnemy
	PlayerInput();
	/*MoveSprite(player.getSprite(), player.getX(), player.getY());	
	if(IsKeyDown((KEY_SPECIAL+66)) == true)
	{
		i = 3;
	}*/
	UpdateBullet();

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

void DrawGame()
{
	ClearScreen();
	DrawSprite(BGImage);
	DrawSprite(player.getSprite());
	for(int w=0; w <=10; w++)
	{
		DrawSprite(bulletr[w].getSprite());
		DrawSprite(bulletl[w].getSprite());
	}
	FrameworkUpdate();
}


