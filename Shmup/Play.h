#pragma once
#include "AIE.h"
#include "Sprite.h"
#include "Bullet.h"
class Play
{
public:
	Play(void);
	~Play(void);

	static Sprite player;
	static Bullet Bullet[20];

	static const int iScreenWidth = 800;
	static const int iScreenHeight = 1000;

	static void InitGame()
	{
	
		player.setX(iScreenWidth/2);
		player.setY(500);
		player.setHeight(100);
		player.setWidth(100);
		BGImage = CreateSprite ( "./images/BGImage.png", iScreenWidth, iScreenHeight, true );
		MoveSprite(BGImage, iScreenWidth/2, iScreenHeight/2);
		player.setSprite( CreateSprite( "./images/Player.png", player.getWidth(), player.getHeight(), true ));
		for(int u=0; u <=25; u++)
		{
			Bullet[u].setSprite( CreateSprite( "./images/player bullet.png", 7, 15, true ));
			Bullet[u].setSprite( CreateSprite( "./images/player bullet.png", 7, 15, true ));
		}
		
	}

	static void PlayerInput()
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
			static int bCount = 0;
			if(Bullet[bCount].isAlive() == true)
			{
				Bullet[bCount].FireBullet();
				bCount++;
			}
			else
			{
				bCount++;
			}
		}
	
	}

	static void UpdateGame()
	{
		//SpawnEnemy
		PlayerInput();
		MoveSprite(player.getSprite(), player.getX(), player.getY());	
		for(int w=0; w <=25; w++)
		{
			MoveSprite(Bullet[w].getSprite(), Bullet[w].getX(), Bullet[w].getY());
		}
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

	static void DrawGame()
	{
		ClearScreen();
		DrawSprite(BGImage);
		DrawSprite(player.getSprite());
		for(int w=0; w <=25; w++)
		{
			DrawSprite(Bullet[w].getSprite());
		}
		FrameworkUpdate();
}
private:
	static int BGImage;
};

