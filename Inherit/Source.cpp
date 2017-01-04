#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
using namespace std;

class Base
{
public:
	Base() { std::cout << "Base Construct Called" << std::endl; }
	~Base() { std::cout << "Base Destruct Called" << std::endl; }

};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived Construct Called" << std::endl; }
	~Derived() { std::cout << "Derived Destruct Called" << std::endl; }

};

class Derived2 : public Derived
{
public:
	Derived2() { std::cout << "Derived2 Construct Called" << std::endl; }
	~Derived2() { std::cout << "Derived2 Destruct Called" << std::endl; }

};

class Animal
{
protected:
	string noise;
public:
	virtual void doNoise() { cout << noise << endl; }
};

class Cat : public Animal
{
public:
	
	Cat() { noise = "miao"; }
};

class Human : public Animal
{
public:
	Human() { noise = "fuck"; }
};

class Tuba : public Animal
{
public:
	Tuba() { noise = "a tuba is not an animal you idiot"; }
};

class Tiger : public Animal
{
public:
	void doNoise() override
	{
		cout << "MIAO" << endl;
	}
};

//void Animal::doNoise()
//{
//	cout << noise << endl;
//}



void main()
{
	std::fstream file;

	file.open("guns.txt"); // try and open the file
	if (!file.is_open())   // if it fails to open, make it
	{
		file.close();	   // close the failed opening
		file.open("guns.txt", std::ios_base::out); // make file
	}
	file.close(); // close the made file


	int option;
	do
	{
		std::cout << "1 - Append\n2 - In\n3 - Clear\n4 - Exit\n- ";
		std::cin >> option;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		switch (option)
		{
		case 1: // appending from console to file			
			file.open("guns.txt", std::ios_base::app);
			if (file.is_open())
			{
				std::cout << "- ";
				std::string temp;
				std::getline(std::cin, temp);
				file << temp << std::endl;
			}
			else std::cout << "File failed to open for writing.- ";
			file.close();
			break;

		case 2: // displaying the file
			file.open("guns.txt", std::ios_base::in);
			if (file.is_open())
			{
				std::cout << "File Contents: " << std::endl;
				std::string temp;
				while (std::getline(file, temp))
					std::cout << temp << std::endl;
			}
			else std::cout << "File failed to open for reading.- ";
			file.close();
			break;

		case 3: // clearing the file
			file.open("guns.txt", std::ios_base::out);
			std::cout << "Clearing file contents.\n- ";
			file.close();
			break;

		default:
			std::cout << "Please pick a valid option.- ";
			break;
		case 4:
			std::cout << "Goodbye!- ";
			system("pause");
			break;
		}
		std::cout << std::endl;
	} while (option != 4);
}

