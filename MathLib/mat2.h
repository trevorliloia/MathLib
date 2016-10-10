#pragma once
#include "vec2.h"

union mat2
{
	float m[4];
	float mm[2][2];
	vec2 c[2];
	vec2 operator[](unsigned idx) const;
	vec2 &operator[](unsigned idx);
};



bool operator==(const mat2 &lhs, const mat2 &rhs);
mat2 operator+(const mat2 &lhs, const mat2 &rhs);
mat2 operator-(const mat2 &lhs, const mat2 &rhs);
mat2 operator-(const mat2 &lhs);
mat2 transpose(const mat2 &lhs);

mat2 operator*(const mat2 &lhs, float rhs);
mat2 operator*(float lhs, const mat2 &rhs);
mat2 operator*(const mat2 &lhs, const mat2 &rhs);
mat2 operator*(const mat2 &lhs, const vec2 &rhs);

float determinant(const mat2 &lhs);
mat2 inverse(const mat2 &lhs);
mat2 mat2Identity();