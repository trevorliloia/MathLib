#include "flops.h"
#define _USE_MATH_DEFINES
#include <cmath>


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