#include "vec2.h"
#include <math.h>
#include "flops.h"
#include "Test.h"

vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	return{ lhs.x + rhs.x, lhs.y + rhs.y };
}
vec2 operator-(const vec2 &lhs, const vec2 &rhs)
{
	return{ lhs.x - rhs.x, lhs.y - rhs.y };
}
vec2 operator*(const vec2 &lhs, float rhs)
{
	return{lhs.x * rhs, lhs.y * rhs};
}
vec2 operator*(float lhs, const vec2 &rhs)
{
	return rhs*lhs;
}
vec2 operator*(vec2 &lhs, vec2 &rhs)
{
	return{ lhs.x * rhs.x, lhs.y * rhs.y };
}
vec2 operator/(const vec2 &lhs, float rhs)
{
	return{ lhs.x / rhs, lhs.y / rhs };
}
vec2 operator-(const vec2 &v)
{
	return v*-1;
}
vec2 &operator+=(vec2 &lhs, const vec2 &rhs)
{
	return lhs = lhs + rhs;
}
vec2 &operator-=(vec2 &lhs, const vec2 &rhs)
{
	return lhs = lhs - rhs;
}
vec2 &operator/=(vec2 &lhs, float rhs)
{
	return lhs = lhs / rhs;
}
vec2 &operator*=(vec2 &lhs, vec2 &rhs)
{
	return lhs = lhs * rhs;
}
bool operator== (const vec2 &lhs, const vec2 &rhs)
{
	return fequals(lhs.x,rhs.x) && fequals(lhs.y, rhs.y);
}
bool operator!= (const vec2 &lhs, const vec2 &rhs)
{
	return !fequals(lhs.x, rhs.x) || !fequals(lhs.y, rhs.y);
}
float magnitude(const vec2 &v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}
vec2 normal(const vec2 & v)
{
	return (v/(magnitude(v)));
}

float dot(const vec2 & rhs, const vec2 & lhs)
{
	return (rhs.x * lhs.x + rhs.y * lhs.y);
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	return acos(dot(normal(rhs),normal(lhs)));
}

vec2 lerp(const vec2 &start, const vec2 &end, float alpha)
{
	return alpha*(end - start) + start;
}


vec2 quadBezier(const vec2 &a, const vec2 &b, const vec2 &c, float t)
{
	vec2 mid1 = lerp(a, b, t);
	vec2 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}

vec2 hermiteSpline(const vec2 &x, const vec2 &y, const vec2 &p, const vec2 &q, float t)
{
	float ts = t*t;
	float tc = ts*t;

	float h0 = 2 * tc - 3 * ts + 1;
	float h1 = -2 * tc + 3 * ts;
	float h2 = tc - 2 * ts + t;
	float h3 = tc - ts;

	vec2 point = h0 * x + h2 * p + h1 * y + h3 * q;
	return point;
}

vec2 cardinalSpline(const vec2 &point0, const vec2 &point1, const vec2 &point2, float a, float t)
{
	vec2 tan0 = (point1 - point0) * a;
	vec2 tan1 = (point2 - point1) *a;

	float tsq = t*t;
	float tcub = tsq*t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	vec2 point = h00 * point0 + h10 * tan0 + h01 * point1 + h11 * tan1;

	return point;
}

vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);

}
vec2 perp(const vec2 & v)
{
	return vec2{v.y,-v.x};
}

float angle(const vec2 & v)
{
	return atan2f(v.y, v.x);
}

vec2 fromAngle(float a)
{
	return vec2{cosf(a),sinf(a)};
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}
float &vec2::operator[](unsigned idx)
{
	return v[idx];
}
