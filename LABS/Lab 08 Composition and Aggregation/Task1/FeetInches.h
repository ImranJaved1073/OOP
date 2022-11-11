#ifndef FEETINCHES_H
#define FEETINCHES_H

class FeetInches
{
	int feet;
	int inches;
public:
	FeetInches(int f = 0, int i = 0);
	void setFeet(int val);
	void setInches(int val);
	int getFeet() const;
	int getInches() const;
};

#endif


