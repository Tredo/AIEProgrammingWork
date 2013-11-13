#include "Bullet.h"


Bullet::Bullet(void)
{		
}


Bullet::~Bullet(void)
{
}

void Bullet::setAlive(bool alive)
{
	m_bisAlive = alive;
}

void Bullet::setIdle(bool idle)
{
	m_bisIdle = idle;
}

bool Bullet::isAlive()
{
	return m_bisAlive;
}

bool Bullet::isIdle()
{
	return m_bisIdle;
}

void Bullet::FireBullet()
{
		setSpeedY(-1);
		setSpeedX(0);
		setIdle(false);
}