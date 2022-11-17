#include "CargoShip.h"
#include <iostream>
#include <string>
using namespace std;

CargoShip::CargoShip()
{
	capacity = 0;
}

CargoShip::CargoShip(int cap, string n, string y) : Ship(n, y)
{
	capacity = cap;
}

int CargoShip::getCapacity() 
{
	return capacity;
}

void CargoShip::setCapacity(int cap) 
{
	capacity = cap;
}

void CargoShip::print()
{
	cout << "Name of Ship: " << getName() << endl;
	cout << "Year Ship was made: " << getYear() << endl;
	cout << "Capacity Of it: " << capacity << endl;
}

CargoShip::~CargoShip()
{
	cout << "\nCargoShip destructor" << endl;
}