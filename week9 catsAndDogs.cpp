/*
austin kao
week 9
3/12/2018
*/
#include <iostream>
#include <string>
#include <time.h> 
#include <stdlib.h>
using namespace std;

class Animal
{
protected:

	string name;

public:
	Animal(std::string name)	// Protected to prevent creation of Animals
		: name(name)
	{
		counter++;
	}
	Animal()
	{
		counter++;
	}
	static int counter;
	string getName() { return name; }
	const char* communicate() { return "???"; }
};
int Animal::counter = 0;
class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)				// Initializer list
	{		}

	const char* communicate() { return "Meow"; }
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)				// Initializer list
	{		}

	const char* communicate() { return "Woof"; }
};

void printName(Animal * animal)	// Works for all animal types
{
	cout << "The name is " << animal->getName() << endl;
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Animal *ptr[10];
	for (int i = 0; i < 10; i++)
	{
		int r = rand() % 2;
		if (r == 0)
		{
			ptr[i] = new Cat("cat-" + to_string(Animal::counter));
		}
		if (r == 1)
		{
			ptr[i] = new Dog("dog-" + to_string(Animal::counter));
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << ptr[i]->getName() << endl;
		delete ptr[i];
	}
	cin.ignore();
	cin.get();
	return 0;
}