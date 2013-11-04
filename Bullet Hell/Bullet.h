#pragma once
#include "vector2d.h"
class Bullet :
	public Sprite
{
public:
	Bullet(void);
	~Bullet(void);

	void SetAlive(bool );
private:
	bool m_bisAlive;
};

