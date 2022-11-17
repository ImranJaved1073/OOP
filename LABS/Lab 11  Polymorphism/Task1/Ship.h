#include <iostream>
#include <string>
using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship 
{
private:
	string name;
	string year;

public:
	Ship();
	Ship(string, string);
	string getName() const;
	string getYear() const;
	void setName(string);
	void setYear(string);
	virtual void print();
	virtual ~Ship();
};

#endif // !SHIP_H

