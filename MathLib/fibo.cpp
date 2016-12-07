#include "fibo.h"
#include <iostream>
#include <cstring>
using namespace std;

int fibCount;
int nest;
char tab[2] = "\t";
const int c_size = 255;
static int *cache;

void clearCache(size_t size)
{
	if (cache != nullptr)
	{
		delete[] cache;
	}

	cache = new int[size];

	if (cache != nullptr)
	{
		memset(cache, 0, (size + 1) * sizeof(int));
	}
	
}

int fib(int n)
{
	fibCount++;
	int first = 1, second = 1;
	int next;
	for (int i = 0; i < n; ++i)
	{
		if (i <= 1)
		{
			next = i;
		}
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
	}
	return next;
}

int fibR(int n)
{
	fibCount++;
	if (n == 1 || n == 0)
	{
		return (n);
		nest = 0;
	}
	else
	{
		
		for (int i = 0; i < nest; ++i)
		{
			cout << tab;
		}
		cout << "fib(" << n - 1 << ")\n";
		for (int i = 0; i < nest; ++i)
		{
			cout << tab;
		}
		cout << "fib(" << n - 2 << ")\n\n";
		nest++;
		if (n == 2 || n == 1)
		{
			nest = 0;
		}
		return fibR(n - 1) + fibR(n - 2);
	}
}

int fibC(int n)
{
	fibCount++;
	if (n == 1 || n == 0)
	{
		return (n);
		nest = 0;
	}
	if (cache[n] == 0)
	{
		cache[n] = fibC(n - 1) + fibC(n - 2);
	}
	else
	{
		for (int i = 0; i < nest; ++i)
		{
			cout << tab;
		}
		cout << "C(" << n - 1 << ")\n";
		for (int i = 0; i < nest; ++i)
		{
			cout << tab;
		}
		cout << "C(" << n - 2 << ")\n\n";
		nest++;
		if (n == 2 || n == 1)
		{
			nest = 0;
		}
		return cache[n];
	}
}