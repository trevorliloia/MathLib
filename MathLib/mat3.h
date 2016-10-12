#pragma once
#include "vec3.h"

union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];
	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};



bool operator==(const mat3 &lhs, const mat3 &rhs);
mat3 operator+(const mat3 &lhs, const mat3 &rhs);
mat3 operator-(const mat3 &lhs, const mat3 &rhs);
mat3 operator-(const mat3 &lhs);
mat3 transpose(const mat3 &lhs);

mat3 operator*(const mat3 &lhs, float rhs);
mat3 operator*(float lhs, const mat3 &rhs);
mat3 operator*(const mat3 &lhs, const mat3 &rhs);
vec3 operator*(const mat3 &lhs, const vec3 &rhs);

float determinant(const mat3 &lhs);
mat3 inverse(const mat3 &lhs);
mat3 mat3Identity();

mat3 scale(float w, float h);
mat3 translate(float x, float y);
mat3 rotate(float a);