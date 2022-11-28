#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
#include "Item.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class Purchase
{
	Item* PurchaseItemArray;
	int size;
public:
	Purchase()
	{
		PurchaseItemArray = nullptr;
		size = 0;
	}
	Purchase(Item* a, int s)
	{
		size = s;
		PurchaseItemArray = new Item[size];
		for (int i = 0; i < s; i++)
		{
			PurchaseItemArray[i] = a[i];
		}
	}
	~Purchase()
	{
		if (PurchaseItemArray != nullptr)
		{
			delete[] PurchaseItemArray;
			PurchaseItemArray = nullptr;
		}
	}
	void setItemPurshased(Item* arr, int s)
	{
		size = s;
		PurchaseItemArray = new Item[size];
		for (int i = 0; i < size; i++)
		{
			PurchaseItemArray[i] = arr[i];
		}
	}
	void displayReceipt()
	{
		long double totalBill = 0;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 10);
		cout << "-------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t\tRECEIPT\n";
		cout << "-------------------------------------------------------------------------------------------";
		cout << "\nITEM NAME\t\tSINGLE ITEM PRICE\t\tITEM QUANTITY\t\tTOTAL PRICE\n";
		cout << "-------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < size; i++)
		{
			cout << PurchaseItemArray[i].getItemName() << "\t\t\t\t" << PurchaseItemArray[i].getPrice() << "\t\t\t\t" << PurchaseItemArray[i].getQuantity() << "\t\t   " << PurchaseItemArray[i].getTotalPrice() << endl;
			totalBill += PurchaseItemArray[i].getTotalPrice();
		}
		cout << "-------------------------------------------------------------------------------------------\n";
		cout << "TOTAL BILL : " << totalBill << "$\n";
		cout << "-------------------------------------------------------------------------------------------\n";
		SetConsoleTextAttribute(h, 14);
	}
};


#endif // !PURCHASE_H
