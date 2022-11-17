#include <iostream>
#include <string>
#include "Ship.h"
using namespace std;

#ifndef CARGOSHIP_H
#define CARGOSHIP_H


class CargoShip : public Ship
{
private:
	int capacity;
public:
	CargoShip();
	CargoShip(int, string, string);
	int getCapacity();
	void setCapacity(int);
	void print();
	~CargoShip();
};

#endif
