#include <iostream>
#include <string>
#include "FeetInches.h"
using namespace std;
#ifndef ROOMDIMENSION_H
#define ROOMDIMENSION_H
class RoomDimension
{
	FeetInches length;
	FeetInches width;

public:
	RoomDimension();
	RoomDimension(int lf, int li, int wf, int wi);
	~RoomDimension();
	void setLength(int f, int i);
	void setWidth(int f, int i);
	FeetInches getLength();
	FeetInches getWidth();
	FeetInches calculateArea();
};

#endif // ROOMDIMENSION_H
