#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;


void main()
{
	std::fstream file;

	file.open("ept.bin"); // try and open the file
	if (!file.is_open())   // if it fails to open, make it
	{
		file.close();	   // close the failed opening
		file.open("ept.bin", std::ios_base::out); // make file
	}
	
	file.close(); // close the made file

	system("pause");
}

