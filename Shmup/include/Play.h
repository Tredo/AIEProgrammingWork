#pragma once
#include "AIE.h"
#include "Sprite.h"
#include "Bullet.h"
class Play
{
public:
	Play(void);
	~Play(void);

	Sprite player;
	Sprite enemy;
	Sprite BGImage;
	Bullet Bullet[20];
			
	void InitGame();
	void EnemyWaveOne();
	void PlayerInput();	
	void UpdateGame();
	void DrawGame();
	void EnemyHitbox();
	
private:
	
};

