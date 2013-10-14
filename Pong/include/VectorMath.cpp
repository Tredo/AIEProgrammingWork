#include "VectorMath.h"
#include "vector2d.h"
#include <cmath>


struct movableObject
{
	Vector2D position;
	Vector2D speed;
	int sprite;
	int width;
	int height;
};


// subtract a scalar from a vector, return the result as a new vector
Vector2D vectorSubtract(Vector2D &v, float s)
{
	Vector2D result = {v.getX() - s, v.getY() - s};
	
	return result;
}

// adds a scalar to a vector, return the result as a new vector
Vector2D vectorAdd(Vector2D &v, float s)
{
	Vector2D result = {v.getX() + s, v.getX() + s};
	return result;
}

// multiplies a vector by a scalar, returns the result as a new vector
Vector2D multiplyScalar(Vector2D &v, float s)
{
	Vector2D result = {v.getX() * s, v.getX() * s};
	return result;
}

// subtract one vector from another, returns the result as a new vector
Vector2D vectorSubtract(Vector2D &v, Vector2D &v2)
{
	Vector2D result = {v.getX() - v2.getX(), v.getX() - v2.getX()};
	return result;
}

// add one vector to another, returns the result as a new vector
Vector2D vectorAdd(Vector2D &v, Vector2D &v2)
{
	Vector2D result = {v.getX() + v2.getX(), v.getY() + v2.getY()};
	return result;
}

// get the normal of a vector, returns the result as a new vector
Vector2D getNormal(Vector2D &v)
{
	float mag = sqrt(v.getX()*v.getX() + v.getY()*v.getY());
	Vector2D result = {v.getX()/mag, v.getX()/mag};
	return result;
}

// get the magnitude of a vector
float getMagnitude(Vector2D &v)
{
	return sqrt(v.getX()*v.getX() + v.getY()*v.getY());
}