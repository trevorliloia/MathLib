#pragma once
#include "vec2.h"
union vec3
{
	float v[3];
	struct { float x, y, z; }; // anonymous struct
	vec2 xy;
};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float lhs, const vec3 &rhs);
vec3 operator/(const vec3 &lhs, float rhs);
vec3 operator-(const vec3 &v);
vec3 &operator+=(vec3 &lhs, const vec3 &rhs);
vec3 &operator-=(vec3 &lhs, const vec3 &rhs);
vec3 &operator/=(vec3 &lhs, float rhs);
vec3 &operator*=(vec3 &lhs, const vec3 &rhs);
bool operator== (const vec3 &lhs, const vec3 &rhs);
float magnitude(const vec3 &v);
vec3 normal(const vec3 & v);

float dot(const vec3 &rhs, const vec3 &lhs);
float angleBetween(const vec3 &rhs, const vec3 &lhs);

vec3 cross(const vec3 &lhs, const vec3 rhs);