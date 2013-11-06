#pragma once
#include "Sprite.h"
class Bullet :
	public Sprite
{
public:
	Bullet(void);
	~Bullet(void);

	void setAlive(bool alive) {m_bisAlive = alive;}
	bool isAlive() {return m_bisAlive;}

	void FireBullet()
	{
		setSpeedX(1);
		setAlive(true);
	}
private:
	bool m_bisAlive;
};

