#pragma once

union vec2 
{ 
	float v[2];
	struct
	{
		float x, y;
	};
	float operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

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
bool operator!= (const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);
vec2 normal(const vec2 &v);

float dot(const vec2 &rhs, const vec2 &lhs);
float angleBetween(const vec2 &rhs, const vec2 &lhs);

vec2 lerp(const vec2 &start, const vec2 &end, float alpha);
vec2 quadBezier(const vec2 &a, const vec2 &b, const vec2 &c, float t);
vec2 hermiteSpline(const vec2 &x, const vec2 &y, const vec2 &p, const vec2 &q, float t);
vec2 cardinalSpline(const vec2 &point0, const vec2 & point1, const vec2 &point2, float a, float t);
vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);


//3d cross prod 

//2d only
//RH
vec2 perp(const vec2 &v);
//arctan
float angle(const vec2 &v);

vec2 fromAngle(float a);