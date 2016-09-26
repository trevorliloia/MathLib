#include "Test.h"
#include <math.h>

int doNothing(int x)
{
	return x*x + 2 * x + 5;
	//dev branch
	
}

float test_quad(float x)
{
	return x*x + 2*x - 7;
}

quad_results quad(float a, float b, float c)
{
	float d;
	quad_results q;
	d = sqrt(b*b - 4 * a*c);
	q.left_root = (-1*b + d) / (2 * a);
	q.right_root = (-1*b - d) / (2 * a);
	if (d < 0)
	{
		q.roots = 0;

	}
	else if (d == 0.0f)
	{
		q.roots = 1;

	}
	else
	{
		q.roots = 2;

	}
	
	return q;
}
//c
float lerp(float start, float end, float t)
{
	return start + t * (end - start);
}
//d
float distance(Point P1, Point P2)
{
	return sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y));
}

float distance(float x1, float y1, float x2, float y2)
{
	float d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
//e
float inner(Point3D P1, Point3D P2)
{
	return P1.x * P2.x + P1.y * P2.y + P1.z * P2.z;
}

float inner(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return x1 * x2 + y1 * y2 + z1 * z2;
}
