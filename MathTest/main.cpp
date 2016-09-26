#include <cassert>
#include <cstdio>
#include "Test.h"

int main()
{
	printf("Hello World! %d", doNothing(40));
	assert(doNothing(0) == 5);
	assert(test_quad(0) == -7);
	assert(quad(4, 1, -5).roots == 2);
	assert(lerp(0, 6, 1) == 6);
	assert(distance(1, 0, 2, 0) == 1);
	Point a, b;
	a.x = 1, a.y = 0, b.x = 1, b.y = 0;
	float d = distance(a, b);
	assert(distance(a, b) == 1);
	getchar();
	return 0;
}