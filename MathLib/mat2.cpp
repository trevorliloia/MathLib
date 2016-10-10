#include "mat2.h"
#include "flops.h"
#include "vec2.h"

vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}

vec2 & mat2::operator[](unsigned idx)
{
	return c[idx];
}

bool operator==(const mat2 &lhs, const mat2 &rhs)
{
	return fequals(lhs.m[0], rhs.m[0]) &&
		fequals(lhs.m[1], rhs.m[1]) &&
		fequals(lhs.m[2], rhs.m[2]) &&
		fequals(lhs.m[3], rhs.m[3]);
}
mat2 operator+(const mat2 &lhs, const mat2 &rhs)
{
	return mat2{ lhs.m[0] + rhs.m[0], lhs.m[1] + rhs.m[1],
		lhs.m[2] + rhs.m[2], lhs.m[3] + rhs.m[3] };
}
mat2 operator-(const mat2 &lhs, const mat2 &rhs)
{
	return mat2{ lhs.m[0] - rhs.m[0], lhs.m[1] - rhs.m[1],
		lhs.m[2] - rhs.m[2], lhs.m[3] - rhs.m[3] };
}
mat2 operator-(const mat2 &lhs)
{
	return mat2{ -lhs.m[0], -lhs.m[1], -lhs.m[2], -lhs.m[3] };
}
mat2 transpose(const mat2 &lhs)
{
	return mat2{ lhs.m[0], lhs.m[2], lhs.m[1], lhs.m[3] };
}
mat2 operator*(const mat2 &lhs, float rhs)
{
	return mat2{ lhs.m[0] * rhs, lhs.m[1] * rhs, lhs.m[2] * rhs, lhs.m[3] * rhs };
}
mat2 operator*(float lhs, const mat2 &rhs)
{
	return mat2{ rhs.m[0] * lhs, rhs.m[1] * lhs, rhs.m[2] * lhs, rhs.m[3] * lhs };
}
mat2 operator*(const mat2 &lhs, const mat2 &rhs)
{
	return mat2{ rhs.m[0] * lhs.m[0], rhs.m[1] * lhs.m[1] , rhs.m[2] * lhs.m[2], rhs.m[3] * lhs.m[3] };
	  
}
mat2 operator*(const mat2 &lhs, const vec2 &rhs)
{
	return mat2{ lhs.m[0] * rhs.x, lhs.m[1] * rhs.y, lhs.m[2] * rhs.x, lhs.m[3] * rhs.y};
}

float determinant(const mat2 & lhs)
{
	return lhs.m[0]*lhs.m[3] + lhs.m[1] * lhs.m[2];
}

mat2 inverse(const mat2 & lhs)
{
	return (1 / determinant(lhs)) * mat2 { lhs.m[3], -lhs.m[1], -lhs.m[2], lhs.m[0] };
}

mat2 mat2Identity()
{
	return mat2{ 1,0,0,1 };
}
