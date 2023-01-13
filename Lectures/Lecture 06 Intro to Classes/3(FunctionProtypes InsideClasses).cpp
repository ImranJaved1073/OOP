#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	//Setter Functions(MODIFY)   Mutators
	//Getter Functions(READ)     Accessors

	//Member Functions
	void setX(int);  
	void setY(int);  
	void setCoordinates(int, int);

	//Constant member functions
	int getX() const;
	int getY() const;
	void displayPoint() const;
	
};

// :: ---> Scope Resolution Operator

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

void Point::displayPoint() const
{
	cout << "(" << getX() << "," << getY() << ")\n";
}

int main()
{
	const int N = 4;
	//Point pts[N];

	int n;
	cout << "How many points you want to create? ";
	cin >> n;
	Point* pts = new Point[n];

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cout << "Enter coordinates of point " << i + 1 << " : ";
		cin >> a >> b;
		//pts[i].setX(a);
		//pts[i].setY(b);
		pts[i].setCoordinates(a, b);
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Point " << i + 1 << ": ";
		pts[i].displayPoint();
	}

	delete[] pts;
	pts = nullptr;

	return 0;
}