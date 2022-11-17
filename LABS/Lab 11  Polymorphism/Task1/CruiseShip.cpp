#include "CruiseShip.h"
#include <iostream>
#include <string>
using namespace std;

CruiseShip::CruiseShip(int max, string n, string y) : Ship(n, y)
{
	maxPassengers = max;
}

int CruiseShip::getMaxPassengers() 
{
	return maxPassengers;
}

void CruiseShip::setMaxPassengers(int max) 
{
	maxPassengers = max;
}

void CruiseShip::print()
{
	cout << "Name of Ship: " << getName() << endl;
	cout << "Year Ship was made: " << getYear() << endl;
	cout << "Max Passengers ship Contains: " << maxPassengers << endl;
}

CruiseShip::~CruiseShip()
{
	cout << "\nCruiseShip destructor" << endl;
}
