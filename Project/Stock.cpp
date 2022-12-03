#include <string>
//#include "Item.h"
#include "Stock.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

HANDLE s = GetStdHandle(STD_OUTPUT_HANDLE);

Stock::Stock(int capacity)
{
	items = new Item[capacity];
	size = 0;
	this->capacity = capacity;
}

Stock::Stock(const Stock& stock)
{
	this->items = new Item[stock.capacity];
	this->size = stock.size;
	this->capacity = stock.capacity;

	for (int i = 0; i < capacity; i++)
	{
		if (i != capacity - 1)
			this->items[i] = stock.items[i];
	}
}

void Stock::resize()
{
	capacity++;
	Item* temp = new Item[capacity];
	for (int i = 0; i < capacity; i++)
	{
		if (i != capacity - 1)
			temp[i] = items[i];
		else
			temp[i] = Item();
	}
	delete[] items;
	items = temp;
}

Stock::~Stock()
{
	if (items != nullptr)
	{
		delete[] items;
		items = nullptr;
	}
}

Item* Stock::getItems() const
{
	return items;
}

Item Stock::getItem(int index) const
{
	return items[index];
}

int Stock::getSize() const
{
	return size;
}

int Stock::getCapacity() const
{
	return capacity;
}

void Stock::setItem(Item item, int index)
{
	items[index] = item;
}

void Stock::setItems(Item* items)
{
	this->items = items;
}

void Stock::setSize(int size)
{
	this->size = size;
}

void Stock::setCapacity(int capacity)
{
	this->capacity = capacity;
}

Stock Stock::operator=(const Stock& rhs)
{
	if (this != &rhs)
	{
		//delete previous memory if any allocated
		if (items != nullptr)
		{
			delete[] items;
			items = nullptr;
		}
		this->items = new Item[rhs.capacity];
		this->size = rhs.size;
		this->capacity = rhs.capacity;

		for (int i = 0; i < capacity; i++)
		{
			if (i != capacity - 1)
				this->items[i] = rhs.items[i];
		}
	}
	return *this;
}

void Stock::saveStock()
{
	ofstream fout;
	fout.open("stock.txt");
	for (int i = 0; i < size; i++)
	{
		fout << "____________________________________________________\n";
		fout << "                   ITEM #" << i + 1 << endl;
		fout << "____________________________________________________\n";
		fout << "NAME: " << items[i].getItemName() << "\n";
		fout << "CODE: " << items[i].getItemCode() << "\n";
		fout << "QUANTITY: " << items[i].getQuantity() << "\n";
		fout << "PRICE: " << items[i].getPrice() << "\n";
	}
	fout.close();
}

// fnction to load data from file
void Stock::loadStock()
{
	ifstream fin;
	fin.open("stock.txt");
	if (fin.is_open())
	{
		string line, line1, line2, line3, line4, line5, line6, line7, name, code;
		while (getline(fin, line))
		{
			getline(fin, line1);
			getline(fin, line2);
			getline(fin, line3);
			name = line3.substr(6, line3.length() - 1);
			getline(fin, line4);
			code = line4.substr(6, line4.length() - 1);
			getline(fin, line5);
			int quantity = stoi(line5.substr(10, line5.length() - 1));
			getline(fin, line6);
			long double price = stold(line6.substr(7, line6.length() - 1));

			Item item(name, code, quantity, price);
			addItem(item);
		}
	}

	else
	{
		cout << "\n\n\n\tTHERE ARE NO RECORDS ON THE DATABASE!!!\n\n\n";

	}

	fin.close();
}

void Stock::addItem(Item item)
{
	if (size == capacity)
	{
		resize();
	}
	//check if iteam already present in stock then don't add it
	for (int i = 0; i < size; i++)
	{
		if (items[i].getItemCode() == item.getItemCode() || items[i].getItemName() == item.getItemName())
		{
			cout << "\n\n\n\tITEM ALREADY PRESENT IN STOCK!!!\n\n\n";
			return;
		}
	}
	items[size] = item;
	size++;
}

void Stock::removeItem(string itemCode)
{
	//cin.ignore();
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (items[i].getItemCode() == itemCode)
		{
			index = i;
			break;
		}
	}
	//cin.ignore();
	while (index == -1)
	{
		cout << "\n\n\n\t\t\u001b[31mItem not found\u001b[0m. \n\t\tPlease enter a valid item code: ";
		getline(cin, itemCode);
		for (int i = 0; i < size; i++)
		{
			if (items[i].getItemCode() == itemCode)
			{
				index = i;
				break;
			}
		}
	}
	for (int i = index; i < size - 1; i++)
	{
		items[i] = items[i + 1];
	}
	size--;
}

int Stock::updateItem(string itemCode)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (items[i].getItemCode() == itemCode)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
		return index;
	else
	{
		//add quantity to the quantity of the item already in the stock
		int quantity=-1; int choice1;
		cout << "\n\n\t\tDo you want to Update the quantity of the item? (y/n): ";
		char choice;
		cin >> choice;
		//cin.ignore();
		
		if (choice == 'y' || choice == 'Y')
		{
			cout << "\n\t\tEnter the quantity: ";
			while (!(cin >> quantity) || quantity < 0)
			{
				cout << "\033[A\33[2K\r";
				cout << "\t\t\u001b[31mInvalid input.\u001b[0m Please enter a valid quantity: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cout << "\n\n\t\tDo you want to add or remove quantity of " << items[index].getItemName() << "?\n\n\t\t1. Add\n\t\t2. Remove\n\n\t\tEnter your choice: ";
			cin >> choice1;
			do {
				if (choice1 == 1)
					items[index].setQuantity(items[index].getQuantity() + quantity);
				else if (choice1 == 2)
					items[index].setQuantity(items[index].getQuantity() - quantity);
			}while (choice1 != 1 && choice1 != 2);
			cout << "\u001b[34m\n\n\t\tThe Quantity of " << getItem(index).getItemName() << " against " << itemCode << " code has been updated successfully.\u001b[0m" << endl << endl;
		}
		//update price of the item
		cout << "\n\n\t\tDo you want to update the price of " << items[index].getItemName() << "? (y/n): ";
		char choice2;
		cin.clear();
		cin.ignore(1000,'\n');
		cin >> choice2;
		if (choice2 == 'y' || choice2 == 'Y')
		{
			long double cost;
			cout << "\n\n\t\tEnter the new price of " << items[index].getItemName() << ": ";
			while (!(cin >> cost) || cost < 0)
			{
				cout << "\033[A\33[2K\r";
				cout << "\t\t\u001b[31mInvalid input\u001b[0m. Please enter a valid price: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			items[index].setPrice(cost);
			items[index].setTotalPrice();
			cout << "\u001b[34m\n\n\t\tThe Price of " << getItem(index).getItemName() << " against " << itemCode << " code has been updated successfully.\u001b[0m" << endl << endl;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		
		return index;
	}
}


void Stock::updateItem(int quantity, string itemName)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (items[i].getItemName() == itemName)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		items[index].setQuantity(items[index].getQuantity() - quantity);
		items[index].setTotalPrice();
	}

}


int Stock::searchItem(string itemCode)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (items[i].getItemCode() == itemCode)
		{
			index = i;
			break;
		}
	}
	return index;
}

int Stock::searchItemName(string itemName)
{
	int index = -1;
	int flag = 1;
	for (int i = 0; i < size && flag; i++)
	{
		if (items[i].getItemName() == itemName)
		{
			index = i;
			flag = 0;
		}
	}
	if (flag)
	{
		index = -1;
	}
	return index;
}

void Stock::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Stock::printStock()
{
	if (size == 0)
	{
		cout << "\n\n\n\t\t\u001b[34mSTOCK IS EMPTY!!\u001b[0m" << endl;
	}
	else
	{
		SetConsoleTextAttribute(s, 15);
		gotoXY(0, 5);
		cout << "------------------------------------------------------------------------------------------------------------" << endl;
		gotoXY(0, 6);
		cout << "	ITEM #";
		gotoXY(22, 6);
		cout << "|	    ITEM NAME";
		gotoXY(44, 6);
		cout << "|	   ITEM CODE";
		gotoXY(66, 6);
		cout << "|	  QUANTITY";
		gotoXY(88, 6);
		cout << "|	PRICE	   |";
		gotoXY(0, 7);
		cout << "------------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			gotoXY(0, 8 + i);
			cout << "	  " << i + 1;
			gotoXY(22, 8 + i);
			cout << "|	      " << items[i].getItemName();
			gotoXY(44, 8 + i);
			cout << "|	    " << items[i].getItemCode();
			gotoXY(66, 8 + i);
			cout << "|	   " << items[i].getQuantity();
			gotoXY(88, 8 + i);
			cout << "|	" << items[i].getPrice();
		}
		gotoXY(0, 8 + size);
		cout << "------------------------------------------------------------------------------------------------------------" << endl;
		SetConsoleTextAttribute(s, 7);
	}


}