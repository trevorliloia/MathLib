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
	
	assert(distance({ 1,0 }, {2,0}) == 1);
	assert(inner(2, 2, 2, 2, 2, 2) == 12);
	assert(inner(3, 5, -2, 4, 4, 4) == 24);
	
	assert(inner({ 3,5,-2 }, { 4,4,4 }) == 24);

	getchar();
	return 0;
}