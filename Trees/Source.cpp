#include "Header.h"
#include "Tree.h"
#include <iostream>
#include <cassert>

using namespace std;

void main()
{
	Tree A;

	std::cout << "yo";

	A.insert(5);
	A.insert(6);
	A.insert(2);
	A.insert(9);
	A.insert(1);
	assert(A.find(5) == true);
	assert(A.find(6) == true);
	assert(A.find(2) == true);
	assert(A.find(9) == true);
	assert(A.find(1) == true);
	assert(A.find(12) == false);
	system("pause");
}