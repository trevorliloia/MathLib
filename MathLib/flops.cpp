#include "flops.h"

#define _USE_MATH_DEFINES
#include <valarray>

#include <cmath>

#include "vec2.h"


bool fequals(float lhs, float rhs)
{
	return ((lhs - rhs) < 0.00001 && (lhs - rhs) > -0.00001);
}

float deg2rad(float deg)
{
	return deg * M_PI / 180;
}
float rad2deg(float rad)
{
	return rad * (180 / M_PI);
}

float min(float a, float b)
{
	return (a < b ? a : b);
}

float max(float a, float b)
{
	return (a > b ? a : b);
}

float dotProd(vec2 a, vec2 b)
{
	std::valarray<double> xs = { a.x,a.y };
	std::valarray<double> ys = { b.x,b.y};

	double result = (xs * ys).sum();

	return result;
}

float linearHalf(float x)
{
	return 0.5f * x;
}

float fastCurve(float x)
{
	return x*x;
}

float slowCurve(float x)
{
	return 1 - fastCurve(1 - x);
}

float ridgeFlip(float x)
{
	return (x > .5 ? 2-(2*x) : 2 * x);
}

float bounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}

float revBounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}

float parab(float x)
{
	return -4*(x - .5) * (x-.5)+1;
}

float lerp2(float start, float end, float alpha)
{
	return alpha*(end-start) + start;
}

float quadBezier(float a, float b, float c, float t)
{
	float mid1 = lerp2(a, b, t);
	float mid2 = lerp2(b, c, t);

	return lerp2(mid1, mid2, t);
}

float hermiteSpline(float x, float y, float p, float q, float t)
{
	float ts = t*t;
	float tc = ts*t;

	float h0 = 2 * tc - 3 * ts + 1;
	float h1 = -2 * tc + 3 * ts;
	float h2 = tc - 2 * ts + t;
	float h3 = tc - ts;

	float point = h0 * x + h2 * p + h1 * y + h3 * q;
	return point;
}

float cardinalSpline(float point0, float point1, float point2, float a, float t)
{
	float tan0 = (point1 - point0) * a;
	float tan1 = (point2 - point1) *a;

	float tsq = t*t;
	float tcub = tsq*t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	float point = h00 * point0 + h10 * tan0 + h01 * point1 + h11 * tan1;

	return point;
}

float catRomSpline(float start, float mid, float end, float alpha)
{
return cardinalSpline(start, mid, end, 0.5f, alpha);

}


