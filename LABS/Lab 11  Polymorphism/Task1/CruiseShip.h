#include <iostream>
#include <string>
#include "Ship.h"
using namespace std;

#ifndef CRUISESHIP_H
#define CRUISESHIP_H

class CruiseShip : public Ship
{
private:
	int maxPassengers;
public:
	CruiseShip(int, string, string);
	int getMaxPassengers();
	void setMaxPassengers(int);
	void print();
	~CruiseShip();
};

#endif // !CRUISESHIP_H