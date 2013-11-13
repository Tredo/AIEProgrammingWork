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

bool Bullet::isAlive()
{
	return m_bisAlive;
}

void Bullet::FireBullet()
{
		setSpeedX(1);
		setAlive(true);
}