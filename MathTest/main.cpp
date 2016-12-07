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
#include <iostream>
#include "Test.h"

int fib(int n);
int fibR(int n);
int fibC(int n);
void clearCache(size_t size);
using namespace std;
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
	//assert((scale(2, 1) * c == Circle( 4,0,10)));
	//assert((scale(2, 2) * c == Circle(4,0,10 )));
	//assert((scale(1, 2) * c == Circle(4,0,10 )));

	//assert((scale(-1, 1) * c == Circle{ 0,0,5 }));
	//assert((rotate(45) * c == Circle{ 0,0,5 }));

	cout << "Largest Int Tests\n";
	cout << "1234 - " << largest_digit(1234) << "\n";
	cout << "3253 - " << largest_digit(3253) << "\n";
	cout << "9800 - " << largest_digit(9800) << "\n";

	cout << "\nDescending Int Tests\n";
	cout << "1234 - " << desc_digits(1234) << "\n";
	cout << "9800 - " << desc_digits(9800) << "\n";
	cout << "3333 - " << desc_digits(3333) << "\n";

	extern int fibCount;
	
	cout << "\nFib Nonrecursive\n";
	fibCount = 0;
	cout << "6 | " << fib(6) << " | " << fibCount << "\n";
	cout << "Called:" << fibCount << " times \n";
	fibCount = 0;
	cout << "3 | " << fib(3) << " | " << fibCount << "\n";
	cout << "Called:" << fibCount << " times \n";
	fibCount = 0;
	cout << "2 | " << fib(2) << " | " << fibCount << "\n";
	cout << "Called:" << fibCount << " times \n";

	cout << "\nFib Recursive\n";
	fibCount = 0;
	cout << "6 | " << fibR(6) << "\n";
	cout << "Called:" << fibCount << " times \n";
	fibCount = 0;
	cout << "3 | " << fibR(3) << "\n";
	cout << "Called:" << fibCount << " times \n";
	fibCount = 0;
	cout << "7 | " << fibR(7) << "\n";
	cout << "Called:" << fibCount << " times \n";

	cout << "\nFib Cached\n";
	fibCount = 0;
	int menuitem = 0;
	cin >> menuitem;
	clearCache(menuitem);
	cout << "6 | " << fibC(6) << "\n";
	cout << "Called:" << fibCount << " times \n";
	fibCount = 0;
	cin >> menuitem;
	clearCache(menuitem);
	cout << "3 | " << fibC(3) << "\n";
	cout << "Called:" << fibCount << " times \n";
	fibCount = 0;
	cin >> menuitem;
	clearCache(menuitem);
	cout << "7 | " << fibC(7) << "\n";
	cout << "Called:" << fibCount << " times \n";
	
		// Test the unit testing framework
		//testp(true, true, "Test the Test");
		//testp(false, false, "Test the Test");
		//testp(false, test(true, false), "Test the Test");

		//// Largest Digit
		//testp(4, largest_digit(1234), "LARGEST DIGIT");
		//testp(5, largest_digit(3253), "LARGEST DIGIT");
		//testp(9, largest_digit(9800), "LARGEST DIGIT");

		//// Descending Digit
		//testp(9800, desc_digits(9800), "DESC DIGIT");
		//testp(4321, desc_digits(1234), "DESC DIGIT");
		//testp(3333, desc_digits(3333), "DESC DIGIT");

		//// Ascending Digit
		//testp(89, asce_digits(9800), "ASCE DIGIT");
		//testp(1234, asce_digits(4321), "ASCE DIGIT");
		//testp(3333, asce_digits(3333), "ASCE DIGIT");

		//// Kaprekar's Routine
		//testp(2, kaprekar(6589), "KAPREKAR");
		//testp(5, kaprekar(5455), "KAPREKAR");
		//testp(0, kaprekar(6174), "KAPREKAR");

		//// IsLetter
		//testp(true, isLetter('Q'), "ISLETTER");
		//testp(true, isLetter('a'), "ISLETTER");
		//testp(false, isLetter('1'), "ISLETTER");
		//testp(false, isLetter('.'), "ISLETTER");

		//// isPunctuationButNotSpace
		//testp(true, isPunctuationButNotSpace('.'), "ISPUNCBUTNOTSPACE");
		//testp(true, isPunctuationButNotSpace('?'), "ISPUNCBUTNOTSPACE");
		//testp(false, isPunctuationButNotSpace('a'), "ISPUNCBUTNOTSPACE");
		//testp(false, isPunctuationButNotSpace('A'), "ISPUNCBUTNOTSPACE");
		//testp(false, isPunctuationButNotSpace(' '), "ISPUNCBUTNOTSPACE");

		//const char * lorem = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer porttitor ligula in sollicitudin congue. Integer ac vehicula dolor, a lobortis dui. In hac habitasse platea dictumst. Pellentesque vitae arcu in arcu gravida accumsan eu in ex. Nunc id erat at ligula pellentesque hendrerit eget at sapien. Donec vitae  tortor feugiat, dignissim eros sit amet, rhoncus nisi. In ac ullamcorper mauris, vel consectetur neque. Vivamus ultrices faucibus lectus eget consectetur. Donec bibendum nisi id elit ultrices lobortis. Integer sollicitudin pretium varius. Maecenas volutpat sapien a est molestie, sed fringilla nisl ornare. Nulla id lectus sit amet ligula congue pellentesque. Phasellus egestas sapien turpis, eu porta sem lobortis eget. Vestibulum feugiat finibus lacinia.";

		//// EOS
		//testp(5, getEndOfSegment(lorem, strlen(lorem), 0), "EOS");

		//// Insert Array
		//char name[10] = "Terry  ";
		//insertArray(name, 10, 'N', 6);
		//testp(true, strcmp("Terry N ", name) == 0 ? true : false, "INSERT ARRAY");

		//// Text Wrap
		//printReflow(lorem, strlen(lorem), 40);

	clearCache(0);
	system("pause");
	return 0;
}

