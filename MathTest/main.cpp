#include <cassert>
#include <cstdio>
#include <cmath>
#include "test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
#include "shapes.h"
int main()
{
	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);


	assert(test_quad(0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);


	assert(quad(1, 0, 0).roots == 1);
	assert(quad(1, -2, 0).roots == 2);
	assert(quad(1, 0, 4).roots == 0);


	assert(quad(1, -2, 0).left_root == 0);
	assert(quad(1, -2, 0).right_root == 2);
	assert(quad(1, 0, 0).left_root == quad(1, 0, 0).right_root);
	

	assert(lerp(0, 1, 0) == 0);
	assert(lerp(0, 1, 1) == 1);
	assert(lerp(0, 1, -1) == -1);
	assert(lerp(1, -1, .5f) == 0);


	assert(distance({ 0, 0 }, { 0,0 }) == 0);
	assert(distance({ 0, 0 }, { 5,0 }) == 5);
	assert(distance({ 0,-5 }, { 0,0 }) == 5);
	assert(distance({ 3,0 }, { 0,4 }) == 5);


	assert(inner({ 1,1,0 }, { -1,1,0 }) == 0);
	assert(inner({ 1,1,1 }, { 1,1,1 }) == 3);


	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,0 }) == 0);
	assert(point_plane_distance({ 0,0,1,0 }, { 0,0,1 }) == 1);


	assert(bezier(0, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 0);
	assert(bezier(1, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 3);
	assert(bezier(0.5f, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, { 3,0,0 }).x == 1.5);

	assert((vec2{ 1,1 } +vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } -vec2{ 0,0 } == vec2{ 1,1 }));
	assert(((vec2{ 1,1 } / 1.f) == vec2{ 1, 1 }));
	assert(((vec2{ 1,1 } *1.f) == vec2{ 1, 1 }));
	assert(((1.f * vec2{ 1,1 }) == vec2{ 1, 1 }));
	assert(((vec2{ 10 , -10 }*-1) == vec2{ -10 , 10 }));

	assert((vec2{ 10,10 }) == (vec2{ 5,5 } +(vec2{ 5,5 })));
	assert((vec2{ 5,5 }) == (vec2{ 10,10 } -(vec2{ 5,5 })));
	assert((vec2{ 10,10 }) == (vec2{ 5,5 } *2.0f));
	assert((vec2{ 5,5 }) == (vec2{ 10,10 } / 2.0f));

	assert(normal(vec2{ 0,1 }) == (vec2{ 0,1 }));
	assert(fequals(1, .9999999f));
	vec2 N = normal(vec2{ 1,1 });

	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,3 } != vec2{ 2,3 }));


	assert(fequals(magnitude(N), 1));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));
	assert(fequals(angleBetween(vec2{ 1,0 }, vec2{ 0,1 }),
		deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
		deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }),
		angle(vec2{ 1,1 })));

	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 })
		== vec3{ 0,0,-1 }));

	assert(fequals(lerp2(.23, 124, 0), .23));
	assert(fequals(lerp2(.23, 124, 1), 124));
	assert(fequals(lerp2(0, 1, .5f), .5f));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,2,1 };

	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI * -1 == -mI);
	assert(mI * mI == mI);
	assert((mat2{ 1,2,3,4 }) * mI == (mat2{ 1,2,3,4 }));
	assert(transpose(mI) == mI);
	assert(inverse(mI) == mI);

	assert(t0 * inverse(t0) == mI);
	mat2 ex = inverse(mI);
	ex = t0 * inverse(t0);
	mI;

	assert(fequals(deg2rad(90), 1.5708f));
	vec3 j = { 2,5,1 };
	assert((scale(5, 1) * j == vec3{ 10,5,1 }));
	assert((rotate(deg2rad(90)) * j == vec3{ -5,2,1 }));
	assert((translate(0, 3) * j == vec3{ 2,8,1 }));

	Circle c = { vec2{0,0},5 };



	assert((translate(4, 0) * c == Circle{ vec2{4,0},5 }));
	assert((scale(2, 1) * c == Circle( 4,0,10)));
	assert((scale(2, 2) * c == Circle(4,0,10 )));
	assert((scale(1, 2) * c == Circle(4,0,10 )));

	assert((scale(-1, 1) * c == Circle{ 0,0,5 }));
	assert((rotate(45) * c == Circle{ 0,0,5 }));

	

	system("pause");
	return 0;
}