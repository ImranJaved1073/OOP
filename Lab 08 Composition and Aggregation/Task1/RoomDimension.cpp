#include "RoomDimension.h"
RoomDimension::RoomDimension()
{
	//cout << "RoomDimension's constructor was called..." << endl;
}
RoomDimension::RoomDimension(int lf, int li, int wf, int wi) : length(lf, li), width(wf, wi)
{
	//cout << "RoomDimension's constructor was called..." << endl;
}
RoomDimension::~RoomDimension()
{
	//cout << "RoomDimension's destructor was called..." << endl;
}
void RoomDimension::setLength(int f, int i)
{
	length.setFeet(f);
	length.setInches(i);
}
void RoomDimension::setWidth(int f, int i)
{
	width.setFeet(f);
	width.setInches(i);
}
FeetInches RoomDimension::getLength()
{
	return length;
}
FeetInches RoomDimension::getWidth()
{
	return width;
}
FeetInches RoomDimension::calculateArea()
{
	FeetInches area;
	area.setFeet((length.getFeet() + length.getInches() / 12) * (width.getFeet() + width.getInches() / 12));
	area.setInches(0);
	return area;
}