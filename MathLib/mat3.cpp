#include "mat3.h"
#include "flops.h"
#include "vec3.h"
#include <math.h>

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

bool operator==(const mat3 &lhs, const mat3 &rhs)
{
	return fequals(lhs.m[0], rhs.m[0]) &&
		fequals(lhs.m[1], rhs.m[1]) &&
		fequals(lhs.m[2], rhs.m[2]) &&
		fequals(lhs.m[3], rhs.m[3]) &&
		fequals(lhs.m[4], rhs.m[4]) &&
		fequals(lhs.m[5], rhs.m[5]) &&
		fequals(lhs.m[6], rhs.m[6]) &&
		fequals(lhs.m[7], rhs.m[7]) &&
		fequals(lhs.m[8], rhs.m[8]);
}

mat3 operator+(const mat3 &lhs, const mat3 &rhs)
{
	return mat3{ lhs.m[0] + rhs.m[0], lhs.m[1] + rhs.m[1],
		lhs.m[2] + rhs.m[2], lhs.m[3] + rhs.m[3], lhs.m[4] + rhs.m[4],
		lhs.m[5] + rhs.m[5], lhs.m[6] + rhs.m[6], lhs.m[7] + rhs.m[7], lhs.m[8] + rhs.m[8]};
}
mat3 operator-(const mat3 &lhs, const mat3 &rhs)
{
	return mat3{ lhs.m[0] - rhs.m[0], lhs.m[1] - rhs.m[1],
		lhs.m[2] - rhs.m[2], lhs.m[3] - rhs.m[3], lhs.m[4] - rhs.m[4],
		lhs.m[5] - rhs.m[5], lhs.m[6] - rhs.m[6], lhs.m[7] - rhs.m[7], lhs.m[8] - rhs.m[8] };
}
mat3 operator-(const mat3 &lhs)
{
	return mat3{ -lhs.m[0], -lhs.m[1], -lhs.m[2], -lhs.m[3],-lhs.m[4], -lhs.m[5], -lhs.m[6], -lhs.m[7],-lhs.m[8]};
}
mat3 transpose(const mat3 &lhs)
{
	return mat3{ lhs.m[0], lhs.m[3], lhs.m[6], lhs.m[1], lhs.m[4], lhs.m[7], lhs.m[2], lhs.m[5], lhs.m[8] };
}
mat3 operator*(const mat3 &lhs, float rhs)
{
	return mat3{ lhs.m[0] *rhs,lhs.m[1] * rhs, lhs.m[2] * rhs, lhs.m[3] * rhs,lhs.m[4] * rhs, lhs.m[5] * rhs, lhs.m[6] * rhs, lhs.m[7] * rhs,lhs.m[8] * rhs };
}
mat3 operator*(float lhs, const mat3 &rhs)
{
	return rhs * lhs;
}
mat3 operator*(const mat3 &lhs, const mat3 &rhs)
{
	return mat3{ ((lhs.m[0] * rhs.m[0]) + (lhs.m[3] * rhs.m[1]) + (lhs.m[6] * rhs.m[2])),
				((lhs.m[1] * rhs.m[0]) + (lhs.m[4] * rhs.m[1]) + (lhs.m[7] * rhs.m[2])),
				((lhs.m[2] * rhs.m[0]) + (lhs.m[5] * rhs.m[1]) + (lhs.m[8] * rhs.m[2])),

				((lhs.m[0] * rhs.m[3]) + (lhs.m[3] * rhs.m[4]) + (lhs.m[6] * rhs.m[5])),
				((lhs.m[1] * rhs.m[3]) + (lhs.m[4] * rhs.m[4]) + (lhs.m[7] * rhs.m[5])),
				((lhs.m[2] * rhs.m[3]) + (lhs.m[5] * rhs.m[4]) + (lhs.m[8] * rhs.m[5])),

				((lhs.m[0] * rhs.m[6]) + (lhs.m[3] * rhs.m[7]) + (lhs.m[6] * rhs.m[8])),
				((lhs.m[1] * rhs.m[6]) + (lhs.m[4] * rhs.m[7]) + (lhs.m[7] * rhs.m[8])),
				((lhs.m[2] * rhs.m[6]) + (lhs.m[5] * rhs.m[7]) + (lhs.m[8] * rhs.m[8])) };
}

// 3x[3 * 3]x1 = 3x1
vec3 operator*(const mat3 &lhs, const vec3 &rhs)
{
	return vec3{ lhs.m[0] * rhs.x + lhs.m[1] * rhs.y + lhs.m[2] * rhs.z,
				 lhs.m[3] * rhs.x + lhs.m[4] * rhs.y + lhs.m[5] * rhs.z,
				 lhs.m[6] * rhs.x + lhs.m[7] * rhs.y + lhs.m[8] * rhs.z };
}

float determinant(const mat3 & lhs)
{
	return (lhs.m[0] * lhs.m[4] * lhs.m[8] +
		lhs.m[3] * lhs.m[7] * lhs.m[2] +
		lhs.m[6] * lhs.m[1] * lhs.m[5] -
		lhs.m[6] * lhs.m[4] * lhs.m[2] -
		lhs.m[3] * lhs.m[1] * lhs.m[8] -
		lhs.m[0] * lhs.m[5] * lhs.m[7]);
}

mat3 inverse(const mat3 & lhs)
{
	return (1 / determinant(lhs)) * transpose(lhs);
}

mat3 mat3Identity()
{
	return mat3{ 1,0,0,0,1,0,0,0,1 };
}

mat3 scale(float w, float h)
{
	return mat3{ w,0,0,
			 	 0,h,0,
				 0,0,1 };
}

mat3 translate(float x, float y)
{
	return mat3{ 1,0,x,
				 0,1,y,
				 0,0,1 };
}

mat3 rotate(float a)
{
	return mat3{ cosf(a),-sinf(a),0,
				 sinf(a),cosf(a),0,
				 0,0,1 };
}
