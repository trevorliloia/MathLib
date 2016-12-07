#include "Test.h"
#include <math.h>
#include <iostream>

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
int max(int valA, int valB) { return valA > valB ? valA : valB; }
//
int largest_digit(int digits)
{
	int digit[4];

	// getting the individual digits
	digit[0] = digits % 10;
	digit[1] = digits / 10 % 10;
	digit[2] = digits / 100 % 10;
	digit[3] = digits / 1000 % 10;

	// getting the largest value
	int retVal = 0;

	for (int i = 0; i < 4; ++i)
	{
		retVal = max(retVal, digit[i]);
	}

	// TODO: support any number of digits

	return retVal;
}

int desc_digits(int digits)
{
	int digit[4];

	digit[0] = digits % 10;
	digit[1] = digits / 10 % 10;
	digit[2] = digits / 100 % 10;
	digit[3] = digits / 1000 % 10;

	// TODO: set a good failsafe condition

	// bubble sort
	for (int i = 0; i < 3; )
	{
		if (digit[i] > digit[i + 1])
		{
			// swap the values
			int temp = digit[i];

			digit[i] = digit[i + 1];
			digit[i + 1] = temp;

			i = 0;
			continue;
		}

		i++;
	}

	int recomb = digit[0] + digit[1] * 10 + digit[2] * 100 + digit[3] * 1000;
	return recomb;
}
//int asce_digits(int digits)
//{
//	int digit[4];
//
//	digit[0] = digits % 10;
//	digit[1] = digits / 10 % 10;
//	digit[2] = digits / 100 % 10;
//	digit[3] = digits / 1000 % 10;
//
//	// TODO: set a good failsafe condition
//	for (int i = 0; i < 3;)
//	{
//		if (digit[i] < digit[i + 1])
//		{
//			// swap the values
//			int temp = digit[i];
//
//			digit[i] = digit[i + 1];
//			digit[i + 1] = temp;
//
//			i = 0;
//			continue;
//		}
//
//		i++;
//	}
//
//	int recomb = digit[0] + digit[1] * 10 + digit[2] * 100 + digit[3] * 1000;
//	return recomb;
//}
//
//int kaprekar(int value)
//{
//	int iterations = 0;
//	int kappa = value;
//
//	while (true)
//	{
//		int dsc = desc_digits(kappa);
//		int asc = asce_digits(kappa);
//
//		int babyKappa = dsc - asc;
//
//		if (kappa != babyKappa)
//		{
//			kappa = babyKappa;
//			iterations++;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	return iterations;
//}
//
//void insertArray(char arr[], int size, char value, int position)
//{
//	char push = value;
//
//	for (int i = position; i < size; ++i)
//	{
//		// value to push later
//		char temp = arr[i];
//
//		// write the pushed value
//		arr[i] = push;
//
//		if (push == '\0')
//			break;
//
//		// store pushed value for next run
//		push = temp;
//	}
//}
//
//bool isLetter(char val)
//{
//	return (val > 64 && val < 91) || (val > 96 && val < 123);
//}
//bool isPunctuationButNotSpace(char val)
//{
//	// space check
//	if (val == 32)
//		return false;
//
//	// punct check
//	return (val > 33 && val < 48) || (val > 57 && val < 65);
//}
//
//// Returns the index of the first non alpha-numerical or non-space punct character
//int getEndOfSegment(const char * text, int textLen, int startInd)
//{
//	for (int i = startInd; i < textLen; ++i)
//	{
//		if (!isLetter(text[i]) && !isPunctuationButNotSpace(text[i]))
//			return i;
//	}
//
//	// Could not locate next whitespace or punctuation.
//	return -1;
//}
//void printReflow(const char * text, int textLen, int lineLimit)
//{
//	int seek = 0;
//
//	while (seek < textLen)
//	{
//		int accum = 0;
//
//		for (int i = 0; i < lineLimit;)
//		{
//			if (i == 0 && text[seek + i] == ' ')
//			{
//				i++;
//				accum++;
//				continue;
//			}
//
//			// delta to end of sentence
//			int endIndex = getEndOfSegment(text, textLen, seek + i);
//			int delta = endIndex - (seek + i);
//
//			if (i + delta > lineLimit &&
//				seek + i < textLen)
//				break;
//
//			printf("%c", text[seek + i]);
//
//			i++;
//			accum++;
//		}
//
//		seek += accum;
//		printf("\n");
//	}
//}
//
//template<typename T>
//bool test(T expected, T actual)
//{
//	return expected == actual;
//}
//
//template<typename T>
//bool testp(T expected, T actual, char * name)
//{
//	bool result = test(expected, actual);
//
//	char * label = result ? "PASS" : "FAIL";
//	printf("[%s] :: %s\n", label, name);
//
//	return result;
//}

