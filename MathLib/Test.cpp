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
	d = b*b - 4 * a*c;
	q.left_root = (-b - sqrt(d)) / (2 * a);
	q.right_root = (-b + sqrt(d)) / (2 * a);
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

float point_plane_distance(const Plane3D & pl, const Point3D & pt)
{
	return (inner(pl.abc, pt) + pl.d) /
		sqrt(pl.abc.x * pl.abc.x
			+ pl.abc.y * pl.abc.y
			+ pl.abc.z * pl.abc.z);
}

Point3D bezier(float t, const Point3D & p1, const Point3D & p2, const Point3D & p3, const Point3D & p4)
{
	float ot = 1 - t;
	Point3D r;
	r.x = ot*ot*ot*p1.x + 3 * ot*ot*t*p2.x + 3 * ot*t*t*p3.x + t*t*t*p4.x;
	r.y = ot*ot*ot*p1.y + 3 * ot*ot*t*p2.y + 3 * ot*t*t*p3.y + t*t*t*p4.y;
	r.z = ot*ot*ot*p1.z + 3 * ot*ot*t*p2.z + 3 * ot*t*t*p3.z + t*t*t*p4.z;
	return r;
}

int largest_digit(int digits)
{
	if (digits > 0)
	{
		int tmpA, tmpB, tmpC, tmpD;
		tmpA = (digits % 10);
		tmpB = ((digits % 100) - tmpA) / 10;
		tmpC = ((digits % 1000) - (tmpA + (tmpB * 10))) / 100;
		tmpD = ((digits)-(tmpA + (tmpB * 10) + (tmpC * 100))) / 1000;
		int AB = (tmpA > tmpB) ? tmpA : tmpB;
		int CD = (tmpC > tmpD) ? tmpC : tmpD;
		int retval = (AB > CD) ? AB : CD;
		return retval;
	}
	else
		return 0;
}

int desc_digits(int digits)
{
	int set[4];

	set[0] = digits % 10;
	set[1] = digits / 10 % 10;
	set[2] = digits / 100 % 10;
	set[3] = digits / 1000 % 10;

	for (int i = 0; i < 3;)
	{
		if (set[i] > set[i + 1])
		{
			int tmp = set[i];
			set[i] = set[i + 1];
			set[i + 1] = tmp;
		}

	}
	return set[0] + set[1] * 10 + set[2] * 100 + set[3] * 1000;
}


