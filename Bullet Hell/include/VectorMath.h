#ifndef _VECTORMATH_H_
#define _VECTORMATH_H_

struct movableObject;
Vector2D vectorSubtract(Vector2D &v, float s);
Vector2D vectorAdd(Vector2D &v, float s);
Vector2D multiplyScalar(Vector2D &v, float s);
Vector2D vectorSubtract(Vector2D &v, Vector2D &v2);
Vector2D vectorAdd(Vector2D &v, Vector2D &v2);
Vector2D getNormal(Vector2D &v);
float getMagnitude(Vector2D &v);

#endif