#include <iostream>
#include <string>
#include "FeetInches.h"
#include "RoomCarpet.h"
#include "RoomDimension.h"
using namespace std;
int main()
{
	int choice;
	int feetLength, inchLength, feetWidth, inchWidth, n;
	float c;
	cout << "Do you want to calculate cost for a room or a house?" << endl;
	cout << "Enter 1 for room and 2 for house: ";
	cin >> choice;
	while (choice != 1 || choice != 2)
	{
		cout << "Invalid Choice!Enter Again.";
		cin >> choice;
	}
	
	if (choice == 1)
	{
		cout << "Enter length of room in feet: ";
		cin >> feetLength;
		cout << "Enter length of room inn inches: ";
		cin >> inchLength;
		cout << "Enter width of room in feet: ";
		cin >> feetWidth;
		cout << "Enter width of room inn inches: ";
		cin >> inchWidth;
		cout << "Enter cost per square foot: ";
		cin >> c;
		RoomCarpet r(feetLength, inchLength, feetWidth, inchWidth, c);
		cout << "Cost for room:" << r.calculateTotalCost() << endl;
	}
	else if (choice == 2)
	{
		cout << "How many rooms does the house have? ";
		cin >> n;
		float cost = 0;
		for (int i = 0; i < n; i++)
		{
			cout << "Enter information for room " << i + 1 << ":" << endl;
			cout << "Enter length of room in feet: ";
			cin >> feetLength;
			cout << "Enter length of room inn inches: ";
			cin >> inchLength;
			cout << "Enter width of room in feet: ";
			cin >> feetWidth;
			cout << "Enter width of room inn inches: ";
			cin >> inchWidth;
			cout << "Enter cost per square foot: ";
			cin >> c;
			RoomCarpet r(feetLength, inchLength, feetWidth, inchWidth, c);
			cost += r.calculateTotalCost();
		}
		cout << "Cost for house: " << cost << endl;
		
	}


}