#include "Sprite.h"


Sprite::Sprite(void)
{
	x = y = 0;
};
Sprite::Sprite(float xs, float ys)
{
	x = xs;
	y = ys;
}

float Sprite::getX()
{
	return x;
}

float Sprite::getY()
{
	return y;
}

int Sprite::getSpeedX()
{
	return xc;
}

int Sprite::getSpeedY()
{
	return yc;
}

int Sprite::getWidth()
{
	return width;
}

int Sprite::getHeight()
{
	return height;
}

int Sprite::getSprite()
{
	return sprite;
}

void Sprite::setX(float xs)
{
	x = xs;
}

void Sprite::setY(float ys)
{
	y = ys;
}

void Sprite::setSpeedX(float xk)
{
	xc = xk;
}

void Sprite::setSpeedY(float yk)
{
	yc = yk;
}

void Sprite::setWidth(int Width)
{
	width = Width;
}

void Sprite::setHeight(int Height)
{
	height = Height;
}

void Sprite::setSprite(int k)
{
	sprite = k;
}