#include "FeetInches.h"

FeetInches::FeetInches(int f , int i )
{
	feet = f;
	inches = i;
}
void FeetInches::setFeet(int val)
{
	feet = val;
}
void FeetInches::setInches(int val)
{
	inches = val;
}
int FeetInches::getFeet() const
{
	return feet;
}
int FeetInches::getInches() const
{
	return inches;
}