#include <string>
//#include "Item.h"
#include "Stock.h"
#include <iostream>
#include <fstream>
#include <sstream>
#define NOMINMAX
#include <Windows.h>
#include <limits>
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
	if (size >= capacity)
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
		int quantity = -1; int choice1;
		cout << "\n\n\t\tDo you want to Update the quantity of the item? (y/n): ";
		char choice = getValidChoice();
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
			cin.ignore(1000, '\n');
			cout << "\n\n\t\tDo you want to add or remove quantity of " << items[index].getItemName() << "?\n\n\t\t1. Add\n\t\t2. Remove\n\n\t\tEnter your choice: ";
			while (!(cin >> choice1) || choice1 < 1 || choice1 > 2)
			{
				cout << "\033[A\33[2K\r";
				cout << "\t\t\u001b[31mInvalid input.\u001b[0m Please enter a valid choice(1/2): ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (choice1 == 1)
			{
				items[index].setQuantity(items[index].getQuantity() + quantity);
				cout << "\u001b[34m\n\n\t\tThe Quantity of " << getItem(index).getItemName() << " against " << itemCode << " code has been added successfully.\u001b[0m" << endl << endl;
			}
			else
			{
				if (items[index].getQuantity() > quantity)
				{
					items[index].setQuantity(items[index].getQuantity() - quantity);
					cout << "\u001b[34m\n\n\t\tThe Quantity of " << getItem(index).getItemName() << " against " << itemCode << " code has been removed successfully.\u001b[0m" << endl << endl;
				}
				else
					cout << "\n\n\t\t\u001b[31mNot enough quantity in stock.\u001b[0m\n\n";
			}

		}

		//update price of the item
		cout << "\n\n\t\tDo you want to update the price of " << items[index].getItemName() << "? (y/n): ";
		char choice2 = getValidChoice();
		if (choice2 == 'y' || choice2 == 'Y')
		{
			long double cost;
			cout << "\n\n\t\tEnter the new price of " << items[index].getItemName() << ": ";
			while (!(cin >> cost) || cost < 0)
			{
				cout << "\033[A\33[2K\r";
				cout << "\t\t\u001b[31mInvalid input\u001b[0m. Please enter a valid price: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			items[index].setPrice(cost);
			items[index].setTotalPrice();
			cout << "\u001b[34m\n\n\t\tThe Price of " << getItem(index).getItemName() << " against " << itemCode << " code has been updated successfully.\u001b[0m" << endl << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	COORD coord{};
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
		gotoXY(25, 5);
		cout << "\u001b[43m------------------------------------------------------------------------------------------------------------\u001b[0m" << endl;
		gotoXY(25, 6);
		cout << "|\u001b[32m	ITEM #\u001b[0m";
		gotoXY(47, 6);
		cout << "      \u001b[32mITEM NAME\u001b[0m";
		gotoXY(69, 6);
		cout << "      \u001b[32mITEM CODE\u001b[0m";
		gotoXY(91, 6);
		cout << "	 \u001b[32mQUANTITY\u001b[0m";
		gotoXY(113, 6);
		cout << "        \u001b[32mPRICE\u001b[0m      |";
		gotoXY(25, 7);
		cout << "\u001b[43m------------------------------------------------------------------------------------------------------------\u001b[0m" << endl;
		for (int i = 0; i < size; i++)
		{
			gotoXY(25, 8 + i);
			cout << "|     " << "\u001b[33m" << i + 1 << "\u001b[0m";
			gotoXY(47, 8 + i);
			cout << "| " << items[i].getItemName();
			gotoXY(69, 8 + i);
			cout << "| " << items[i].getItemCode();
			gotoXY(91, 8 + i);
			cout << "| " << items[i].getQuantity();
			gotoXY(113, 8 + i);
			cout << "| " << items[i].getPrice() << "/= Rs.";
			gotoXY(132, 8 + i);
			cout << "|";
		}
		gotoXY(25, 8 + size);
		cout << "\u001b[43m------------------------------------------------------------------------------------------------------------\u001b[0m" << endl;
		SetConsoleTextAttribute(s, 7);
	}

}

char Stock::getValidChoice()
{
	char choice;
	cin >> choice;
	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
	{
		cout << "\033[A\33[2K\r";
		cout << "\t\t\u001b[31mInvalid input.\u001b[0m Please enter a valid choice(y/n): ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> choice;
	}
	return choice;
}