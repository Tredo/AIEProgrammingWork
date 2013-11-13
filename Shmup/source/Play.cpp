#include "Play.h"


Play::Play(void)
{	
}

Play::~Play(void)
{
}



void Play::InitGame()
{
	int iScreenWidth = 800;
	int iScreenHeight = 1000;
	
	for(int k = 0; k <=10; k++)
	{
		enemy[k].setX(400);
		enemy[k].setSpeedX(2);
		enemy[k].setSprite( CreateSprite( "./images/enemy.png", 50, 50, true ));
	}
	player.setX(iScreenWidth/2);
	player.setY(500);
	player.setHeight(100);
	player.setWidth(100);
	BGImage.setSprite( CreateSprite ( "./images/BGImage.png", iScreenWidth, iScreenHeight, true ));
	MoveSprite(BGImage.getSprite(), iScreenWidth/2, iScreenHeight/2);
	player.setSprite( CreateSprite( "./images/Player.png", player.getWidth(), player.getHeight(), true ));
	
	for(int u=0; u <=50; u++)
	{
		Bullet[u].setSprite( CreateSprite( "./images/player bullet.png", 10, 15, true ));
	}
	
}

void Play::EnemyWaveOne()
{
	for(int k = 0; k <=10; k++)
	{
		enemy[k].setY(100);
		if(enemy[k].getX() < 0)
		{
			enemy[k].setX(20);
			enemy[k].setSpeedX( enemy[k].getSpeedX() * -1);
		
		}
		else if(enemy[k].getX() > 800)
		{
			enemy[k].setX(780);
			enemy[k].setSpeedX( enemy[k].getSpeedX() * -1);
		}
	}
}

void Play::PlayerInput()
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
	static int fire = 20;
	
	if(GetMouseButtonDown(0) == true && fire == 20)
	{
		static int bCount = 0;
		
		if(Bullet[bCount].isAlive() == false)
		{
			Bullet[bCount].setX(player.getX());
			Bullet[bCount].setY(player.getY());
			Bullet[bCount].FireBullet();
			bCount++;
						
			if(bCount > 50)
			{
				bCount = 0;
			}

		}
		else
		{
			bCount++;
		}
	}
	fire++;

	if(fire > 20)
	{
		fire = 0;
	}
}

void Play::UpdateGame()
{	
	PlayerInput();
	MoveSprite(player.getSprite(), player.getX(), player.getY());
	MoveSprite(enemy.getSprite(), enemy.getX(), enemy.getY());
		
	for(int w=0; w <=50; w++)
	{
		if(Bullet[w].getX() > 0 && Bullet[w].getX() < 800 && Bullet[w].getY() > 0 && Bullet[w].getY() < 1000)
		{
			Bullet[w].setAlive(true);
		}
		else
		{
			Bullet[w].setAlive(false);
		}
				
		if(Bullet[w].isIdle() == true)
		{
			Bullet[w].setX(player.getX());
			Bullet[w].setY(player.getY());
		}

		Bullet[w].setX(Bullet[w].getX() + Bullet[w].getSpeedX());
		Bullet[w].setY(Bullet[w].getY() + Bullet[w].getSpeedY());
		MoveSprite(Bullet[w].getSprite(), Bullet[w].getX(), Bullet[w].getY());
	}

	enemy.setX(enemy.getX() + enemy.getSpeedX());
	enemy.setY(enemy.getY() + enemy.getSpeedY());
}

void Play::DrawGame()
{
	ClearScreen();
	DrawSprite(BGImage.getSprite());
	DrawSprite(player.getSprite());
	DrawSprite(enemy.getSprite());
	for(int w=0; w <=50; w++)
	{
		DrawSprite(Bullet[w].getSprite());
	}
	FrameworkUpdate();
}

void Play::EnemyHitbox()
{

	for(int w=0; w <=50; w++)
	{
		if(Bullet[w].getX() > (enemy.getX() - 25) && Bullet[w].getX() < (enemy.getX() + 25) && Bullet[w].getY() > (enemy.getY() - 25) && Bullet[w].getY() < (enemy.getY() + 25))
		{
			DestroySprite(enemy.getSprite());
		}

	}

}