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
	Bullet Bullet[20];
			
	void InitGame();
	void PlayerInput();	
	void UpdateGame();
	void DrawGame();
	
private:
	int BGImage;
};

