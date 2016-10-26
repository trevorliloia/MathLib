#include "vec3.h"
#include "flops.h"
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
	return fequals(lhs.x, rhs.x) && fequals(lhs.y,rhs.y) && fequals(lhs.z, rhs.z);
}
float magnitude(const vec3 &v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}
vec3 normal(const vec3 & v)
{
	return (v / (magnitude(v)));
}

float dot(const vec3 & rhs, const vec3 & lhs)
{
	return (rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * lhs.z);
}

float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dot(rhs, lhs));
}

vec3 cross(const vec3 & lhs, const vec3 rhs)
{
	return{ lhs.y * rhs.z - lhs.z * rhs.y,
		    lhs.z * rhs.x - lhs.x * rhs.z,
		    lhs.x * rhs.y - lhs.y * rhs.x };
}
