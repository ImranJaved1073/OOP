#include <iostream>
#include "Point.h"
using namespace std;

// Multi-file Project

int main()
{
	const int N = 4;
	Point points[N]={{1,2},{3,4},{5,6}};
	for (int i = 0; i < N; i++)
	{
		points[i].displayPoint();
	}

	// The constructor
	Point pt1;
	// Default constructor is automatically called when an
	// object of type Point is created

	Point pt2(4, 15);
	pt2.displayPoint();

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