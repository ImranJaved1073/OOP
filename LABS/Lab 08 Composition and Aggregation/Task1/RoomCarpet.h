#ifndef ROOMCARPET_H
#define ROOMCARPET_H


#include <iostream>
#include <string>
#include "FeetInches.h"
#include "RoomDimension.h"
using namespace std;
class RoomCarpet
{
	RoomDimension length;
	float cost_per_square_foot;
public:
	RoomCarpet();
	RoomCarpet(int lf, int li, int wf, int wi, float c);
	~RoomCarpet();
	void setLength(int lf, int li, int wf, int wi);
	void setCost(float c);
	float calculateTotalCost();
	float getCost() const;
};

#endif // ROOMCARPET_H
