#include "VectorMath.h"
#include <cmath>

struct vector2
{
	float x;
	float y;
};

struct movableObject
{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};


// subtract a scalar from a vector, return the result as a new vector
vector2 vectorSubtract(vector2 &v, float s)
{
	vector2 result = {v.x - s, v.y - s};
	
	return result;
}

// adds a scalar to a vector, return the result as a new vector
vector2 vectorAdd(vector2 &v, float s)
{
	vector2 result = {v.x + s, v.y + s};
	return result;
}

// multiplies a vector by a scalar, returns the result as a new vector
vector2 multiplyScalar(vector2 &v, float s)
{
	vector2 result = {v.x * s, v.y * s};
	return result;
}

// subtract one vector from another, returns the result as a new vector
vector2 vectorSubtract(vector2 &v, vector2 &v2)
{
	vector2 result = {v.x - v2.x, v.y - v2.y};
	return result;
}

// add one vector to another, returns the result as a new vector
vector2 vectorAdd(vector2 &v, vector2 &v2)
{
	vector2 result = {v.x + v2.x, v.y + v2.y};
	return result;
}

// get the normal of a vector, returns the result as a new vector
vector2 getNormal(vector2 &v)
{
	float mag = sqrt(v.x*v.x + v.y*v.y);
	vector2 result = {v.x/mag, v.y/mag};
	return result;
}

// get the magnitude of a vector
float getMagnitude(vector2 &v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}