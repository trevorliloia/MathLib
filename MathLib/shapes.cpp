#include "shapes.h"
#include "flops.h"


Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;

	retval.pos = (T*vec3{ C.pos.x, C.pos.y, 1 }).xy;

	float mX = magnitude(T*vec3{ 0, C.rad, 0 });
	float mY = magnitude(T*vec3{ C.rad, 0, 0 });
	retval.rad = mX > mY ? mX : mY;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return (A.pos == B.pos) && fequals(A.rad, B.rad) ;
}

AABB operator*(const mat3 & T, const AABB & C)
{
	return AABB();
}

Plane operator*(const mat3 & T, const Plane & C)
{
	return Plane();
}

Ray operator*(const mat3 & T, const Ray & C)
{
	return Ray();
}

Hull operator*(const mat3 & T, const Hull & C)
{
	return Hull();
}

Circle::Circle(vec2 a_pos, float a_rad)
{
	pos = a_pos;
	rad = a_rad;
}

Circle::Circle(float a_x, float a_y, float a_rad)
{
	pos.x = a_x;
	pos.y = a_y;
	rad = a_rad;
}

vec2 AABB::min()
{
	return pos - he;
}

vec2 AABB::max()
{
	return pos + he;
}
