#include "RoomCarpet.h"

RoomCarpet::RoomCarpet()
{
	cost_per_square_foot = 0;
}
RoomCarpet::RoomCarpet(int lf, int li, int wf, int wi, float c) :length(lf, li, wf, wi)
{
	cost_per_square_foot = c;
}
RoomCarpet::~RoomCarpet()
{
	//cout << "Room Carpet's destructor was called..." << endl;
}
void RoomCarpet::setLength(int lf, int li, int wf, int wi)
{
	length.setLength(lf, li);
	length.setWidth(wf, wi);
}
void RoomCarpet::setCost(float c)
{
	cost_per_square_foot = c;
}
float RoomCarpet::calculateTotalCost()
{
	return (length.calculateArea().getFeet() + length.calculateArea().getInches()) * cost_per_square_foot;
}
float RoomCarpet::getCost() const
{
	return cost_per_square_foot;
}