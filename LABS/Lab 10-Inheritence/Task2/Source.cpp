#include<iostream>
#include<string>
#include "ShippingContainer.h"
#include "ManualShippingContainer.h"
#include "RFIDshippingcontainer.h"
using namespace std;

int main()
{
	int id;
	string item;
	ManualShippingContainer manual[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter infomation for manual Shipping container " << i + 1 << endl;
		cout << "Enter id: ";
		cin >> id;
		manual[i].setContainerID(id);
		cout << "Enter item description: ";
		cin.ignore();
		getline(cin, item);

		manual[i].setManifest(item);
	}
	cout << endl;

	int q;
	RFIDshippingcontainer rfid[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter infomation for RFID container " << i + 1 << endl;
		cout << "Enter id: ";
		cin >> id;
		rfid[i].setContainerID(id);
		
		cout << "Add items now. Press q to quit..." << endl;
		item = "";
		while (item != "q")
		{
			cin.ignore();
			cout << "Enter item description: ";
			getline(cin, item);
			if (item == "q") break;
			cout << "Enter quantity: ";
			cin >> q;
			rfid[i].add(item,q);
		}
	}
	cout << endl;
	system("CLS");
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Information of manual container " << i + 1 << endl;
		cout << "ID: " << manual[i].getContainerID() << endl;
		cout << "ITEMS\n" << manual[i].getManifest() << endl;
	}
	cout << endl;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "Information of RFID Shipping container " << i + 1 << endl;
		cout << "ID: " << rfid[i].getContainerID() << endl;
		cout << "ITEMS\n" << rfid[i].getManifest() << endl;
	}
	cout << endl;
	
}