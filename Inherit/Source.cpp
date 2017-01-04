#include <iostream>
#include <string>
#include <list>
#include <fstream>
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
	fstream file;
	file.open("guns.txt");
	if (!file.is_open())
	{
		file.close();
		file.open("guns.txt", std::ios_base::out);
	}
	file.close();

	file.open("guns.txt", std::ios_base::in);
	if (file.is_open())
	{
		string temp;
		while (temp != "")
		{
			getline(file, temp);
			cout << temp << endl;
		}
	}
	file.close();

	file.open("guns.txt", std::ios_base::app);
	if (file.is_open())
	{
		file << "Bang!" << endl;
	}
	file.close();

	system("pause");
}


