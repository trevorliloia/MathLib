#pragma once
//#include "mat2.h"
#include "mat3.h"
//#include "vec2.h"
//#include "vec3.h"

struct Circle
{
	vec2 pos;
	float rad;
	//(x-h)^2 + (y-k)^2 = r^2

	//Circle();
	Circle(vec2 pos, float rad);
	Circle(float x = 0, float y = 0, float rad = 1);
};



struct AABB
{
	vec2 pos, he;

	vec2 min() const; // return pos - he;
	vec2 max() const; // return pos + he;
	//min = vec2{pos.x - he.x, pos.y - he.y}
	//max = vec2{pos.x + he.x, pos.y + he.y}
};

AABB boxScale(const float angle, const AABB &A);

//AABB();
struct Plane
{

};
//Plane();
struct Ray
{

};
struct Hull
{

};


Circle operator*(const mat3 &T, const Circle    &C);
bool   operator==(const Circle &A, const Circle &B);
AABB   operator*(const mat3 &T, const AABB      &A);
Plane  operator*(const mat3 &T, const Plane     &C);
Ray    operator*(const mat3 &T, const Ray       &C);
Hull   operator*(const mat3 &T, const Hull      &C);