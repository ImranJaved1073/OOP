#include <iostream>
#include <string>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
#include "BattleShip.h"
using namespace std;


int main()
{
	Ship* ships[4];
	cout << "Which ship do you want to create?\n1.Cruise Ship\n2.Cargo Ship\n3.Battle Ship\n4.Simple Ship" << endl;
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 4)
	{
		cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		string name;
		string year;
		int maxPassengers;
		cout << "Enter the name of the ship: ";
		cin >> name;
		cout << "Enter the year the ship was built: ";
		cin >> year;
		cout << "Enter the maximum number of passengers: ";
		cin >> maxPassengers;
		ships[0] = new CruiseShip(maxPassengers, name, year);
		ships[0]->print();
		delete ships[0];
		ships[0] = nullptr;
	}
	else if (choice == 2)
	{
		string name;
		string year;
		int capacity;
		cout << "Enter the name of the ship: ";
		cin >> name;
		cout << "Enter the year the ship was built: ";
		cin >> year;
		cout << "Enter the capacity of the ship: ";
		cin >> capacity;
		ships[1] = new CargoShip(capacity, name, year);
		ships[1]->print();
		delete ships[1];
		ships[1] = nullptr;
	}

	else if (choice == 3)
	{
		string name;
		string year;
		int totalNumOfMissiles;
		cout << "Enter the name of the ship: ";
		cin >> name;
		cout << "Enter the year the ship was built: ";
		cin >> year;
		cout << "Enter the total number of missiles: ";
		cin >> totalNumOfMissiles;
		ships[2] = new BattleShip(totalNumOfMissiles, name, year);
		ships[2]->print();
		delete ships[2];
		ships[2] = nullptr;
	}

	else if (choice == 4)
	{
		string name;
		string year;
		cout << "Enter the name of the ship: ";
		cin >> name;
		cout << "Enter the year the ship was built: ";
		cin >> year;
		ships[3] = new Ship(name, year);
		ships[3]->print();
		delete ships[3];
		ships[3] = nullptr;
	}

	return 0;
}