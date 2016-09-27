#pragma once

struct vec2 { float x, y; };

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator-(const vec2 &v);
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator/=(vec2 &lhs, float rhs);
vec2 &operator*=(vec2 &lhs, const vec2 &rhs);
bool operator== (const vec2 &lhs, const vec2 &rhs);
float magnitude(const vec2 &v);
vec2 normal(const vec2 &v);

float dot(const vec2 &rhs, const vec2 &lhs);
float angleBetween(const vec2 &rhs, const vec2 &lhs);

//3d cross prod 

//2d only
//RH
vec2 perp(const vec2 &v);
//arctan
float angle(const vec2 &v);