#include <iostream>
#include <string>
#include <fstream>
#include "Purchase.h"
#include <Windows.h>

using namespace std;

void Purchase::pauseAndClear()
{
	cout << "\n\n\t";
	system("pause");
	system("cls");
}

Purchase::Purchase()
{
	PurchaseItemArray = nullptr;
	purchaseSize = 0;
}

int Purchase::getPurchaseSize() const
{
	return purchaseSize;
}


//copy constructor
Purchase::Purchase(const Purchase& purchase)
{
	this->PurchaseItemArray = new Item[purchase.purchaseSize];
	this->purchaseSize = purchase.purchaseSize;
	for (int i = 0; i < purchaseSize; i++)
	{
		this->PurchaseItemArray[i] = purchase.PurchaseItemArray[i];
	}
}

//overloaded assignment operator
const Purchase& Purchase::operator=(const Purchase& purchase)
{
	if (this != &purchase)
	{
		if (PurchaseItemArray != nullptr)
		{
			delete[] PurchaseItemArray;
			PurchaseItemArray = nullptr;
		}
		this->PurchaseItemArray = new Item[purchase.purchaseSize];
		this->purchaseSize = purchase.purchaseSize;
		for (int i = 0; i < purchaseSize; i++)
		{
			this->PurchaseItemArray[i] = purchase.PurchaseItemArray[i];
		}
	}
	return *this;
}

Purchase::Purchase(Item* a, int s)
{
	purchaseSize = s;
	PurchaseItemArray = new Item[purchaseSize];
	for (int i = 0; i < s; i++)
	{
		PurchaseItemArray[i] = a[i];
	}
}

Item* Purchase::getPurchaseItemArray() const
{
	return PurchaseItemArray;
}

int Purchase::getNumberOfPurchasedItems()
{
	return purchaseSize;
}


Purchase::~Purchase()
{
	if (PurchaseItemArray != nullptr)
	{
		delete[] PurchaseItemArray;
		PurchaseItemArray = nullptr;
	}
}
void Purchase::setItemPurshased(Item* arr, int s)
{
	purchaseSize = s;
	PurchaseItemArray = new Item[purchaseSize];
	for (int i = 0; i < purchaseSize; i++)
	{
		PurchaseItemArray[i] = arr[i];
	}
}

void Purchase::addPurshase(Stock& obj)
{
	//obj.loadStock();
	if (obj.getSize() != 0)
	{
		int numOfItems, CustomerQuantity = -1;
		int flag = 1;
		int index;
		string itemName;
		do
		{
			cout << "\n\n\n\t\tHow many items do you want to purchase? ";
			cin >> numOfItems;
		} while (numOfItems > obj.getCapacity() || numOfItems < 0);

		purchaseSize = numOfItems;
		PurchaseItemArray = new Item[numOfItems];

		for (int i = 0; i < purchaseSize; i++)
		{
			cin.ignore();
			//string itemCode; int quantity;
			do
			{
				pauseAndClear();
				cout << "\n\n\t\tEnter item Name: ";

				getline(cin, itemName);
				//this is a check if item with same name already purchased then do not allow to purchase it
				for (int j = 0; j < i && flag; j++)
				{
					if (itemName == PurchaseItemArray[j].getItemName())
					{
						cout << "\n\n\t\tItem already purchased" << endl;
						itemName = "";
						flag = 0;
					}
				}
				index = obj.searchItemName(itemName);

				if (index == -1)
				{
					cout << "\u001b[31m\n\n\t\tItem not found!!\nEnter valid item name\u001b[0m" << endl;
				}
				else
				{
					cout << "\n\t\tHow much quantity of \u001b[33m" << itemName << "\u001b[0m do you want to purchase? ";
					cin >> CustomerQuantity;

					while (obj.getItem(index).getQuantity() < CustomerQuantity)
					{
						cout << "\n\n\t\t\u001b[33mSorry, we don't have enough quantity of \u001b[34m" << itemName << "\u001b[33m. We only have \u001b[34m";
						cout << obj.getItem(index).getQuantity() << "\u001b[33m " << itemName << endl;

						cout << "\u001b[0m\n\t\tPlease enter quantity less than or equal to " << obj.getItem(index).getQuantity() << endl;

						cout << "\n\t\tHow many \u001b[33m" << itemName << "\u001b[0m do you want to purchase? ";
						cin >> CustomerQuantity;
					}

					PurchaseItemArray[i] = obj.getItem(index);
					PurchaseItemArray[i].setQuantity(CustomerQuantity);
					PurchaseItemArray[i].setTotalPrice();
					obj.updateItem(CustomerQuantity, itemName);
				}
				cout << endl;
			} while (index == -1);
		}
		pauseAndClear();
	}
}


bool Purchase::updatePurchasedItem(string name, Stock& obj)
{
	bool flag = false;
	int index, indexStockItem;
	for (int i = 0; i < purchaseSize && flag == false; i++)
	{
		if (name == PurchaseItemArray[i].getItemName())
		{
			index = i;
			flag = true;
		}
	}
	int q = 0;
	if (flag)
	{
		indexStockItem = obj.searchItem(PurchaseItemArray[index].getItemCode());
		int quantity;
		do
		{
			cout << "Enter quantity of \u001b[33m" << PurchaseItemArray[index].getItemName() << "\u001b[0m you want to buy: ";
			cin >> quantity;

		} while (quantity > obj.getItem(indexStockItem).getQuantity());
		q = PurchaseItemArray[index].getQuantity();
		PurchaseItemArray[index].setQuantity(quantity);
		PurchaseItemArray[index].setTotalPrice();
		quantity -= q;
		obj.updateItem(quantity, PurchaseItemArray[index].getItemName());
		return flag;
	}
	else
	{
		return flag;
	}
}


bool Purchase::deletePurchasedItem(string name, Stock& obj)
{
	bool flag = false;
	int index;
	int tempQuantity = 0;
	for (int i = 0; i < purchaseSize && flag == false; i++)
	{
		if (name == PurchaseItemArray[i].getItemName())
		{
			index = i;
			flag = true;
		}
	}

	if (flag)
	{
		string name = PurchaseItemArray[index].getItemName();
		tempQuantity = PurchaseItemArray[index].getQuantity();
		tempQuantity *= -1;
		Item* tempItems = new Item[purchaseSize - 1];
		for (int i = 0, j = -1; i < purchaseSize; i++)
		{
			if (index != i)
			{
				++j;
				tempItems[j] = PurchaseItemArray[i];
			}
		}
		setItemPurshased(tempItems, purchaseSize - 1);
		obj.updateItem(tempQuantity, name);
		cout << "\n\n\t\t\u001b[33m" << name << " \u001b[32mhas been succesfully deleted from purchased list!!\u001b[0m\n";

		return flag;
	}
	else
	{
		return flag;
	}
	pauseAndClear();
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

	for (int i = 0; i < purchaseSize; i++)
	{
		gotoXY(0, 8 + i);
		cout << "	" << i + 1;
		gotoXY(22, 8 + i);
		cout << "|	" << PurchaseItemArray[i].getItemName();
		gotoXY(44, 8 + i);
		cout << "|	" << PurchaseItemArray[i].getPrice();
		gotoXY(66, 8 + i);
		cout << "|	" << PurchaseItemArray[i].getQuantity();
		gotoXY(88, 8 + i);
		cout << "|	" << PurchaseItemArray[i].getTotalPrice();
		totalBill += PurchaseItemArray[i].getTotalPrice();
	}
	gotoXY(0, 8 + purchaseSize);
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "TOTAL BILL : " << totalBill << "$\n";
	cout << "------------------------------------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(h, 14);
}