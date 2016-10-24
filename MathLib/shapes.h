#pragma once
#pragma once
#include "mat2.h"
#include "mat3.h"
#include "vec2.h"
#include "vec3.h"

struct Circle
{
	vec2 pos;
	float rad;
	//(x-h)^2 + (y-k)^2 = r^2
};
struct AABB
{

};
struct Plane
{

};
struct Ray
{

};
struct Hull
{

};


Circle operator*(const mat3 &T, const Circle    &C);
bool   operator==(const Circle &A, const Circle &B);
AABB   operator*(const mat3 &T, const AABB      &C);
Plane  operator*(const mat3 &T, const Plane     &C);
Ray    operator*(const mat3 &T, const Ray       &C);
Hull   operator*(const mat3 &T, const Hull      &C);