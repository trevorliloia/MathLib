#include "shapes.h"
#include "flops.h"
#include <math.h>
#include <cmath>


AABB boxScale(const float angle, const AABB & A)
{
	mat3 T = { cosf(angle), sinf(angle), 0,
			 -sinf(angle), cosf(angle), 0,
			 0,		       0,		    0 };
	// determine the corners of the box.
	// transform each corner by the matrix.
	
	vec3 tC = T * vec3{ A.min().x, A.min().y, 1 };
	vec3 tB = T * vec3{ A.max().x, A.max().y, 1 };
	vec3 tA = T * vec3{ A.min().x, A.max().y, 1 };
	vec3 tD = T * vec3{ A.max().x, A.min().y, 1 };

	AABB retval;
	retval.he.x = fabsf(tC.x - tB.x) > fabsf(tA.x - tD.x) ? (tC.x > tB.x ? tC.x - tB.x : tB.x - tC.x) : (tA.x > tD.x ? tA.x - tD.x : tD.x - tA.x);

	retval.he.y = fabsf(tC.y - tB.y) > fabsf(tA.y - tD.y) ? (tC.y > tB.y ? tC.y - tB.y : tB.y - tC.y) : (tA.y > tD.y ? tA.y - tD.y : tD.y - tA.y);

	return retval;
}

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;

	retval.pos = (T*vec3{ C.pos.x, C.pos.y, 1 }).xy;

	float mX = magnitude(T*vec3{ 0, C.rad, 0 });
	float mY = magnitude(T*vec3{ C.rad, 0, 0 });
	retval.rad = mX > mY ? mX : mY;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return (A.pos == B.pos) && fequals(A.rad, B.rad) ;
}

AABB operator*(const mat3 & T, const AABB & A)
{
	AABB retval;
	vec3 tC = T * vec3{ A.min().x, A.min().y, 1 };
	vec3 tB = T * vec3{ A.max().x, A.max().y, 1 };
	vec3 tA = T * vec3{ A.min().x, A.max().y, 1 };
	vec3 tD = T * vec3{ A.max().x, A.min().y, 1 };
	/*retval.he.x = magnitude(T * vec3{ retval.he.x, 0,0 });
	retval.he.y = magnitude(T * vec3{ 0, retval.he.y,0 });*/
	
	retval.he.x = fabsf(tC.x - tB.x) > fabsf(tA.x - tD.x) ? (tC.x > tB.x ? tC.x - tB.x : tB.x - tC.x) : (tA.x > tD.x ? tA.x - tD.x : tD.x - tA.x);

	retval.he.y = fabsf(tC.y - tB.y) > fabsf(tA.y - tD.y) ? (tC.y > tB.y ? tC.y - tB.y : tB.y - tC.y) : (tA.y > tD.y ? tA.y - tD.y : tD.y - tA.y);

	
	retval.pos = (T * vec3{ A.pos.x, A.pos.y, 1 }).xy;

	//retval.he = A.he;
	
	
	return retval;
}

Plane operator*(const mat3 & T, const Plane & P)
{
	Plane retval;
	retval.pos = (T * vec3{ P.pos.x, P.pos.y, 1 }).xy;

	retval.dir = normal(T * vec3{ P.dir.x, P.dir.y, 0 }).xy;

	return retval;
}

bool operator==(const Plane & P, const Plane & Q)
{
	
	return (P.dir == Q.dir) && (P.pos == Q.pos);
}

Ray operator*(const mat3 & T, const Ray & C)
{
	return Ray();
}

Hull operator*(const mat3 & T, const Hull & C)
{
	return Hull();
}

Circle::Circle(vec2 a_pos, float a_rad)
{
	pos = a_pos;
	rad = a_rad;
}

Circle::Circle(float a_x, float a_y, float a_rad)
{
	pos.x = a_x;
	pos.y = a_y;
	rad = a_rad;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}
