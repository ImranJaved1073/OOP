#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	//Setter Functions(MODIFY)
	//Getter Functions(READ)

	//void setX(int val);  //Member Function
	void setX(int val)
	{
		x = val;
	}

	//void setY(int val);  //Member Function
	void setY(int val)
	{
		y = val;
	}

	void setCoordinates(int v1, int v2)
	{
		x = v1;
		y = v2;
	}

	//Constant member function
	int getX() const
	{
		return x;
	}

	//Constant member function
	int getY() const
	{
		return y;
	}

	//Constant member function
	void displayPoint() const
	{
		cout << "(" << x << "," << y << ")\n";
	}

};

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
}


 //member varibles of an object can be duplicated --> when you create an object of class..
 //..seperate memory is allocated for its member variables
 //member variables may be duplicated but code can't be duplicated that is, ..
 //..code of member functions is at one place, you may create as many objects as you can but..
 //..objects use shared code(member functions) --> member functions will be called on the base/..
 //..perspective of an object