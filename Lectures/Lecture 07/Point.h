#ifndef POINT_H
#define POINT_H

// Class specification OR Class definition
class Point
{

private:

	int x;
	int y;

public:

	// Default Constructor // Constructor name is same as class name
	Point(); 
	// Parameterized / Overloaded constructor
	Point(int, int);
	void setX(int);
	void setY(int);
	void setCoordinates(int, int);
	int getX() const;
	int getY() const;
	void displayPoint() const;

};

#endif //!POINT_H

