#include "Bullet.h"


Bullet::Bullet(void)
{
	setX(-100);
	setY(-100);
	
}


Bullet::~Bullet(void)
{
}

void Bullet::SetAlive(bool a_bisAlive)
{

	m_bisAlive = a_bisAlive;
}
