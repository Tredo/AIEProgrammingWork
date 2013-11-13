#pragma once
class Sprite
{
public:
	Sprite();
	Sprite(float x, float y);
	~Sprite() {};
		
	float getX();
	float getY();

	int getSpeedX();
	int getSpeedY();

	int getWidth();
	int getHeight();

	int getSprite();

	void setX(float xs);
	void setY(float ys);

	void setSpeedX(float xk);
	void setSpeedY(float yk);

	void setWidth(int Width);
	void setHeight(int Height);

	void setSprite(int k);

	void setAlive(bool alive);
	bool isAlive();

private:
	float x, y;
	int xc, yc;
	int width, height;
	int sprite;
	bool m_bisalive;
};

