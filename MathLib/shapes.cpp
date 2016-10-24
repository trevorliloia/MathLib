#include "shapes.h"

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
	return false;
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
