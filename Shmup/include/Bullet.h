#pragma once
#include "Sprite.h"
class Bullet :
	public Sprite
{
public:
	Bullet(void);
	~Bullet(void);

	void setAlive(bool alive);
	bool isAlive();
	void FireBullet();
	
private:
	bool m_bisAlive;
};

