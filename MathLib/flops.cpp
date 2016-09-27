#include "flops.h"

bool fequals(float lhs, float rhs)
{
	return ((lhs - rhs) < 0.00001 && (lhs - rhs) > -0.00001);
}
