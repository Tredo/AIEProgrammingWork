#pragma once
#include "Sprite.h"
class Bullet :
	public Sprite
{
public:
	Bullet(void);
	~Bullet(void);

	void setAlive(bool alive);
	void setIdle(bool idle);
	bool isAlive();
	bool isIdle();
	void FireBullet();
	
private:
	bool m_bisAlive;
	bool m_bisIdle;
};

