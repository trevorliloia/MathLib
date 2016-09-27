#include "vec3.h"
#include <math.h>

vec3 operator+(const vec3 &lhs, const vec3 &rhs)
{
	return{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}
vec3 operator-(const vec3 &lhs, const vec3 &rhs)
{
	return{ lhs.x - rhs.x, lhs.y - rhs.y,lhs.z - rhs.z };
}
vec3 operator*(const vec3 &lhs, float rhs)
{
	return{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}
vec3 operator*(float lhs, const vec3 &rhs)
{
	return rhs*lhs;
}
vec3 operator*(vec3 &lhs, vec3 &rhs)
{
	return{ lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}
vec3 operator/(const vec3 &lhs, float rhs)
{
	return{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}
vec3 operator-(const vec3 &v)
{
	return v*-1;
}
vec3 &operator+=(vec3 &lhs, const vec3 &rhs)
{
	return lhs = lhs + rhs;
}
vec3 &operator-=(vec3 &lhs, const vec3 &rhs)
{
	return lhs = lhs - rhs;
}
vec3 &operator/=(vec3 &lhs, float rhs)
{
	return lhs = lhs / rhs;
}
vec3 &operator*=(vec3 &lhs, vec3 &rhs)
{
	return lhs = lhs * rhs;
}
bool operator== (const vec3 &lhs, const vec3 &rhs)
{
	return  lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}
float magnitude(const vec3 &v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}
