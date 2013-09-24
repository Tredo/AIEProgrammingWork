#ifndef _VECTORMATH_H_
#define _VECTORMATH_H_

struct vector2;
vector2 vectorSubtract(vector2 &v, float s);
vector2 vectorAdd(vector2 &v, float s);
vector2 multiplyScalar(vector2 &v, float s);
vector2 vectorSubtract(vector2 &v, vector2 &v2);
vector2 vectorAdd(vector2 &v, vector2 &v2);
vector2 getNormal(vector2 &v);
float getMagnitude(vector2 &v);

#endif