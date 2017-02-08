#pragma once
#include <random>
inline float rand01() { return (float)rand() / RAND_MAX; }

inline float lerp(float s, float e, float t)
{
	return s*(1-t) + e*t;
}

#define DEG2RAD 0.0174533

struct vec2 { float x, y; };

inline vec2 operator+(const vec2 &A, const vec2 &B)
{
	return vec2{ A.x + B.x, A.y + B.y };
}

inline vec2 operator*(const vec2 &A, float b)
{
	return vec2{ A.x * b, A.y * b };
}

inline vec2 lerp(const vec2 &A, const vec2 &B, float t)
{
	return A*(1-t) + B*t;
}

inline vec2 randRange(const vec2 &A, const vec2 &B)
{
	return vec2{lerp(A.x, B.x, rand01()), lerp(A.y, B.y, rand01())};
}

inline vec2 randDir(float min_deg, float max_deg)
{
	float deg = lerp(min_deg, max_deg, rand01());
	float rad = DEG2RAD * deg;

	return vec2{ cos(rad), sin(rad) };
}

union color
{
	unsigned ui_color;
	struct { unsigned char r, g, b, a; };
};

inline color lerp(const color &S, const color &E, float t)
{
	color ret;
	ret.r = ((float)S.r*(1-t) + (float)E.r*t) * 255 / 255;
	ret.g = ((float)S.g*(1-t) + (float)E.g*t) * 255 / 255;
	ret.b = ((float)S.b*(1-t) + (float)E.b*t) * 255 / 255;
	ret.a = ((float)S.a*(1-t) + (float)E.a*t) * 255 / 255;
	return ret;
}