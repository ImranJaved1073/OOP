#include <iostream>
#include <string>
#include <fstream>
#include "Purchase.h"
#define NOMINMAX
#include <Windows.h>

using namespace std;

void Purchase::pauseAndClear()
{
	cout << "\n\n\t";
	system("pause");
	system("cls");
}

void Purchase::resize()
{
	purchaseSize++;
	Item* temp = new Item[purchaseSize];
	for (int i = 0; i < purchaseSize; i++)
	{
		if (i != purchaseSize - 1)
			temp[i] = PurchaseItem[i];
		else
			temp[i] = Item();
	}
	delete[] PurchaseItem;
	PurchaseItem = temp;
}

Purchase::Purchase()
{
	PurchaseItem = new Item[1];
	purchaseSize = 1;
	currentSize = 0;
}

int Purchase::getPurchaseSize() const
{
	return purchaseSize;
}

int Purchase::getCurrentSize() const
{
	return currentSize;
}

//copy constructor
Purchase::Purchase(const Purchase& purchase)
{
	this->PurchaseItem = new Item[purchase.purchaseSize];
	this->purchaseSize = purchase.purchaseSize;
	this->currentSize = purchase.currentSize;

	for (int i = 0; i < purchaseSize; i++)
	{
		this->PurchaseItem[i] = purchase.PurchaseItem[i];
	}
}

//overloaded assignment operator
const Purchase& Purchase::operator=(const Purchase& purchase)
{
	if (this != &purchase)
	{
		if (PurchaseItem != nullptr)
		{
			delete[] PurchaseItem;
			PurchaseItem = nullptr;
		}
		this->PurchaseItem = new Item[purchase.purchaseSize];
		this->purchaseSize = purchase.purchaseSize;
		this->currentSize = purchase.currentSize;
		for (int i = 0; i < purchaseSize; i++)
		{
			this->PurchaseItem[i] = purchase.PurchaseItem[i];
		}
	}
	return *this;
}

Purchase::Purchase(Item* a, int s)
{
	PurchaseItem = new Item[s];
	purchaseSize = s;
	currentSize = 0;
	for (int i = 0; i < s; i++)
	{
		PurchaseItem[i] = a[i];
	}
}

Item* Purchase::getPurchaseItemArray() const
{
	return PurchaseItem;
}

//int Purchase::getNumberOfPurchasedItems()
//{
//	return purchaseSize;
//}

void Purchase::setIndex(int i)
{
	currentSize = i;
}

//int Purchase::getIndex() const
//{
//	return currentSize;
//}

Purchase::~Purchase()
{
	if (PurchaseItem != nullptr)
	{
		delete[] PurchaseItem;
		PurchaseItem = nullptr;
	}
}
void Purchase::setItemPurshased(Item* arr, int s)
{
	PurchaseItem = new Item[s];
	purchaseSize = s;
	currentSize = 0;
	for (int i = 0; i < s; i++)
	{
		PurchaseItem[i] = arr[i];
	}
}

void Purchase::addPurshase(Stock& obj)
{
	//obj.loadStock();
	//char choice;
	//string name;
	//int quantity; bool flag = 1;
	//int indexOfPurchase = -1;

	//do {
	//	cout << index;
	//	cout << "\n\n\tEnter the name of the item you want to purchase: ";
	//	getline(cin, name);
	//	cout << name;
	//	//if item already exists in the purchase list then do not add it again
	//	for (int i = 0; i < index; i++)
	//	{
	//		if (PurchaseItem[i].getItemName() == name)
	//		{
	//			cout << "\n\n\tItem already exists in the purchase list";
	//			flag = 0;
	//			indexOfPurchase = i;
	//			break;
	//		}
	//	}
	//	indexOfPurchase = obj.searchItemName(name);
	//	if (indexOfPurchase == -1)
	//	{
	//		cout << "\n\n\tSorry, we don't have the item you want to purchase!";
	//	}
	//	else
	//	{
	//		cout << "\n\n\tEnter the quantity of the item you want to purchase: ";
	//		cin >> quantity;
	//		if (obj.getItem(indexOfPurchase).getQuantity() >= quantity)
	//		{
	//			PurchaseItem[index] = obj.getItem(index);
	//			PurchaseItem[index].setQuantity(quantity);
	//			PurchaseItem[index].setTotalPrice();
	//			//obj.getItem(indexOfPurchase).setQuantity(obj.getItem(indexOfPurchase).getQuantity() - quantity);
	//			obj.updateItem(quantity, name);
	//			index++;
	//			if (index >= purchaseSize)
	//				resize();
	//			cout << "\n\n\tItem purchased successfully!";
	//		}
	//		else
	//		{
	//			cout << "\n\n\tSorry, we don't have enough quantity of the item you want to purchase!";
	//		}
	//	}

	//	pauseAndClear();
	//	cout << "Do you want to purchase another item? (y/n): ";
	//	cin >> choice;
	//	cin.ignore();
	//} while (choice == 'y' || choice == 'Y');
	//pauseAndClear();
	
	if (obj.getSize() != 0)
	{
		char choice;
		int  CustomerQuantity = -1;
		int indextemp=-1;
		string itemName;


		do {
			//cin.ignore();
			//string itemCode; int quantity;
			obj.printStock();
			cout << "\n\n\t\tEnter item Name: ";

			getline(cin, itemName);

			indextemp = obj.searchItemName(itemName);

			while (indextemp == -1)
			{
				cout << "\033[A\33[2K\r";
				cout << "\u001b[31m\t\tItem not found!!\u001b[0mEnter valid item name: ";
				getline(cin, itemName);
				indextemp = obj.searchItemName(itemName);
			}

			//search for the item in the purchase list and if it exists then do not add it again
			if (searchPurchasedItem(itemName) != -1)
			{
				cout << "\n\n\t\tItem already exists in the purchase list";
			}

			else
			{
				cout << "\n\t\tHow much quantity of \u001b[33m" << itemName << "\u001b[0m do you want to purchase? ";
				cin >> CustomerQuantity;

				while (obj.getItem(indextemp).getQuantity() < CustomerQuantity)
				{
					cout << "\n\n\t\t\u001b[33mSorry, we don't have enough quantity of \u001b[34m" << itemName << "\u001b[33m. We only have \u001b[34m";
					cout << obj.getItem(indextemp).getQuantity() << "\u001b[33m " << itemName << endl;

					cout << "\u001b[0m\n\t\tPlease enter quantity less than or equal to " << obj.getItem(indextemp).getQuantity() << endl;

					cout << "\n\t\tHow many \u001b[33m" << itemName << "\u001b[0m do you want to purchase? ";
					cin >> CustomerQuantity;
				}
				//cout << currentSize;
				PurchaseItem[currentSize] = obj.getItem(indextemp);
				PurchaseItem[currentSize].setQuantity(CustomerQuantity);
				PurchaseItem[currentSize].setTotalPrice();
				obj.updateItem(CustomerQuantity, itemName);
				currentSize++;
				if (currentSize >= purchaseSize)
					resize();
			}

			pauseAndClear();
			cout << "Do you want to purchase another item? (y/n): ";
			cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (choice == 'y' || choice == 'Y');
		pauseAndClear();
	}

}

bool Purchase::updatePurchasedItem(string name, Stock& obj)
{
	int indexStockItem;
	int flag = searchPurchasedItem(name);
	int q = 0;
	if (flag != -1)
	{
		indexStockItem = obj.searchItem(PurchaseItem[flag].getItemCode());
		int quantity;
		do
		{
			cout << "Enter quantity of \u001b[33m" << PurchaseItem[flag].getItemName() << "\u001b[0m you want to buy: ";
			cin >> quantity;

		} while (quantity > obj.getItem(indexStockItem).getQuantity());

		q = PurchaseItem[flag].getQuantity();
		PurchaseItem[flag].setQuantity(quantity);
		PurchaseItem[flag].setTotalPrice();
		quantity -= q;

		obj.updateItem(quantity, PurchaseItem[flag].getItemName());
		return true;
	}
	else
	{
		return false;
	}
	//pauseAndClear();
}


bool Purchase::deletePurchasedItem(string name, Stock& obj)
{
	//int indexStockItem;
	if (currentSize != 0)
	{
		int flag = searchPurchasedItem(name);
		int q = 1;
		if (flag != -1)
		{
			string name = PurchaseItem[flag].getItemName();
			q *= -(PurchaseItem[flag].getQuantity());
			for (int i = flag; i < purchaseSize - 1; i++)
			{
				PurchaseItem[i] = PurchaseItem[i + 1];
			}
			currentSize--;
			obj.updateItem(q, name);
			cout << "\n\n\t\t\u001b[33m" << name << " \u001b[32mhas been succesfully deleted from purchased list!!\u001b[0m\n";
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "\n\n\t\t\u001b[31mNo items in the purchased list!!\u001b[0m\n";
		return false;
	}
	
	pauseAndClear();
	
}

int Purchase::searchPurchasedItem(string name)
{
	int index = -1;
	bool flag = false;
	for (int i = 0; i < purchaseSize && flag == false; i++)
	{
		if (name == PurchaseItem[i].getItemName())
		{
			index = i;
			flag = true;
		}
	}
	return index;
}

void Purchase::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Purchase::displayReceipt()
{
	long double totalBill = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);
	/*cout << "-------------------------------------------------------------------------------------------";
	cout << "\n\t\t\t\tRECEIPT\n";*/
	gotoXY(0, 5);
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	gotoXY(0, 6);
	cout << "ITEM #";
	gotoXY(22, 6);
	cout << "|ITEM NAME";
	gotoXY(44, 6);
	cout << "|SINGLE ITEM PRICE";
	gotoXY(66, 6);
	cout << "|QUANTITY";
	gotoXY(88, 6);
	cout << "|TOTAL PRICE";
	gotoXY(0, 7);
	cout << "------------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < currentSize; i++)
	{
		gotoXY(0, 8 + i);
		cout << i + 1;
		gotoXY(22, 8 + i);
		cout << "|" << PurchaseItem[i].getItemName();
		gotoXY(44, 8 + i);
		cout << "|" << PurchaseItem[i].getPrice();
		gotoXY(66, 8 + i);
		cout << "|" << PurchaseItem[i].getQuantity();
		gotoXY(88, 8 + i);
		cout << "|" << PurchaseItem[i].getTotalPrice();
		totalBill += PurchaseItem[i].getTotalPrice();
	}
	gotoXY(0, 8 + currentSize);
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "TOTAL BILL : " << totalBill << "$\n";
	cout << "------------------------------------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(h, 14);
}