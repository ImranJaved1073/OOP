//ship class
#include <iostream>
#include <string>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
#include "BattleShip.h"
using namespace std;


int main()
{
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
		Ship* s;
		string name;
		string year;
		int maxPassengers;
		cout << "______________________CRUISE SHIP________________" << endl;
		cout << "                ENTER CRUISE SHIP DATA " << endl;
		cout << "_________________________________________________" << endl;
		cout << "Enter the name of the Cruise Ship: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the year the Cruise Ship was made: ";
		getline(cin, year);
		cout << "Enter the maximum number of passengers the Cruise Ship can hold: ";
		while (!(cin >> maxPassengers) || maxPassengers <= 0)
		{
			cout << "Invalid number of passengers. Please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		s = new CruiseShip(maxPassengers, name, year);
		cout << "_________________________________________________" << endl;
		cout << "                CRUISE SHIP DATA " << endl;
		cout << "_________________________________________________" << endl;
		s->print();
		delete s;
		s = nullptr;
	}


	else if (choice == 2)
	{
		Ship* s;
		string name;
		string year;
		int capacity;
		cout << "______________________CARGO SHIP_________________" << endl;
		cout << "                ENTER CARGO SHIP DATA " << endl;
		cout << "_________________________________________________" << endl;
		cout << "Enter the name of the Cargo Ship: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the year the Cargo Ship was made: ";
		getline(cin, year);
		cout << "Enter the capacity of the Cargo Ship: ";
		while (!(cin >> capacity) || capacity <= 0)
		{
			cout << "Invalid capacity. Please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		s = new CargoShip(capacity, name, year);
		cout << "________________________________________________" << endl;
		cout << "                CARGO SHIP DATA " << endl;
		cout << "_________________________________________________" << endl;
		s->print();
		delete s;
		s = nullptr;

	}

	else if (choice == 3)
	{
		Ship* s;
		string name;
		string year;
		int totalNumOfMissiles;
		cout << "______________________BATTLE SHIP_________________" << endl;
		cout << "                ENTER BATTLE SHIP DATA " << endl;
		cout << "__________________________________________________" << endl;
		cout << "Enter the name of the Battle Ship: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the year the Battle Ship was made: ";
		getline(cin, year);
		cout << "Enter the total number of missiles the Battle Ship can hold: ";
		while (!(cin >> totalNumOfMissiles) || totalNumOfMissiles <= 0)
		{
			cout << "Invalid number of missiles. Please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		s = new BattleShip(totalNumOfMissiles, name, year);
		cout << "__________________________________________________" << endl;
		cout << "                BATTLE SHIP DATA " << endl;
		cout << "__________________________________________________" << endl;
		s->print();
		delete s;
		s = nullptr;
	}

	else if (choice == 4)
	{
		Ship* s;
		s = new Ship;
		string name;
		string year;
		cout << "______________________SIMPLE SHIP_________________" << endl;
		cout << "                ENTER SIMPLE SHIP DATA " << endl;
		cout << "__________________________________________________" << endl;
		cout << "Enter the name of the ship: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the year the ship was built: ";
		getline(cin, year);
		s->setName(name);
		s->setYear(year);
		cout << "__________________________________________________" << endl;
		cout << "                SIMPLE SHIP DATA " << endl;
		cout << "__________________________________________________" << endl;
		s->print();
		delete s;
		s = nullptr;
	}

}