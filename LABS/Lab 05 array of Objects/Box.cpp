#include "Box.h"
#include <iostream>
using namespace std;

Box::Box()
{
	cout << "Default constructor called.\n";
}

void Box::setLength(int l)
{
	length = l;
}

void Box::setWidth(int w)
{
	width = w;
}

void Box::setHeight(int h)
{
	height = h;
}

int Box::getLength() const
{
	return length;
}

int Box::getWidth() const
{
	return width;
}

int Box::getHeight() const
{
	return height;
}

Box::~Box()
{
	cout << "Destructor Called.\n";
}

int Box::getVloume()
{
	return length * width * height;
}