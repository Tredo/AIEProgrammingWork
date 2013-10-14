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

	void setX(float xf) { x = xf;}
	void setY(float yf) { y = yf;}
	
private:
	float x, y;
};



#endif