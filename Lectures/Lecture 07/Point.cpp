#include <iostream>
#include "Point.h"
using namespace std;

// Class Implementation

// Default Constructor
Point::Point() :x(0), y(0) //we don't call constructor by ownself
{
	cout << "Default Constructor called.\n";
	//x = 0;
	//y = 0;
}

// Overloaded Constructor
Point::Point(int a, int b) :x(a), y(b)
{
	cout << "Overloaded Constructor called.\n";
	//x = a; y = b;
}

void Point::setX(int val)
{
	x = val;
}

void Point::setY(int val)
{
	y = val;
}

void Point::setCoordinates(int v1, int v2)
{
	setX(v1); // OR    //x = v1;
	setY(v2); // OR  //y = v2;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

// A constant member function can NOT call any member function which is not constant
void Point::displayPoint() const
{
	cout << "(" << getX() << "," << getY() << ")\n";
}
