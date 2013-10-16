#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

class Vector2D
{

public:
	Vector2D();
	Vector2D(float x, float y);
	~Vector2D() {};

	float getX() {return x;}



	float getY() {return y;}

	void setX(float xs) { x = xs;}
	void setY(float ys) { y = ys;}
	
private:
	float x, y;
};

class Sprite
{

public:
	Sprite();
	Sprite(float x, float y);
	~Sprite() {};
		
	float getX() {return x;}
	float getY() {return y;}

	int getSpeedX() {return xc;}
	int getSpeedY() {return yc;}

	int getWidth() {return width;}
	int getHeight() {return height;}

	int getSprite() {return sprite;}

	void setX(float xs) { x = xs;}
	void setY(float ys) { y = ys;}

	void setSpeedX(int xk) {xc = xk;}
	void setSpeedY(int yk) {yc = yk;}

	void setWidth(int Width) {width = Width;}
	void setHeight(int Height) {height = Height;}

	void setSprite(int k) {sprite = k;}

private:
	float x, y;
	int xc, yc;
	int width, height;
	int sprite;

};



#endif