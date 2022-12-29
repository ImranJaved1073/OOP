#ifndef RFIDSHIPPINGCONTAINER_H
#define RFIDSHIPPINGCONTAINER_H

#include "ShippingContainer.h"
#include <string>
using namespace std;

class RFIDshippingcontainer : public ShippingContainer
{
	string* listOfRFID;
	int* quantity;
	int Size;
	int Capacity;
	void resize()
	{
		Capacity++;
		string* list = new string[Capacity];
		int* temp = new int[Capacity];
		for (int i = 0; i < Capacity - 1; i++)
		{
			list[i] = listOfRFID[i];
			temp[i] = quantity[i];
		}
		delete[] listOfRFID;
		delete[] quantity;
		listOfRFID = list;
		quantity = temp;
	}

public:
	RFIDshippingcontainer()
	{
		Size = 0;
		Capacity = 1;
		listOfRFID = new string[Capacity];
		quantity = new int[Capacity];
	}

	RFIDshippingcontainer(int id)
	{
		containerID = id;
		Size = 0;
		Capacity = 10;
		listOfRFID = new string[Capacity];
		quantity = new int[Capacity];
	}

	string getManifest() const
	{
		string m = "";
		for (int i = 0; i < Size; i++)
		{
			m += to_string(quantity[i]) + " " + listOfRFID[i] + ".\n";
		}
		return m;
	}

	void add(string rfid, int q = 1)
	{
		if (Size == Capacity)
		{
			resize();
		}
		
		for (int i = 0; i < Size; i++)
		{
			if (listOfRFID[i] == rfid)
			{
				quantity[i] += q;
				return;
			}
		}
		listOfRFID[Size] = rfid;
		quantity[Size] = q;
		Size++;
	}
};

#endif 
