#include <cassert>
#include <cstdio>
#include <math.h>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"

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

	assert((vec2{ 0,1 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } * 3) == (vec2{ 3,3 }));
	assert(magnitude(vec2{ 2,0 }) == 2);
	assert(fequals(1.000001, 1));
	// cubic bezier
	//assert(bezier(0, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, {3,0,0}).x == 0);
	getchar();
	return 0;
}