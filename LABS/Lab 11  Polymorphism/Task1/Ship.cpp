#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

Ship::Ship()
{
	name = "";
	year = "";
}

Ship::Ship(string n, string y) 
{
	name = n;
	year = y;
}

string Ship::getName() const 
{
	return name;
}

string Ship::getYear() const
{
	return year;
}

void Ship::setName(string n)
{
	name = n;
}

void Ship::setYear(string y) 
{
	year = y;
}

void Ship::print() 
{
	cout << "Name of Ship: " << name << endl;
	cout << "Year Ship was made: " << year << endl;
}

Ship::~Ship()
{
	cout << "\nShip destructor called" << endl;
}
