#ifndef STOCK_H
#define STOCK_H

#include <string>
#include "Item.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

class Stock
{
	Item* items;
	int size;
	int capacity;
	void resize()
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

public:
	Stock(int capacity = 1)
	{
		items = new Item[capacity];
		size = 0;
		this->capacity = capacity;
	}
	Stock(const Stock& stock)
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
	~Stock()
	{
		if (items != nullptr)
		{
			delete[] items;
			items = nullptr;
		}
	}
	Item* getItems() const
	{
		return items;
	}
	Item getItem(int index) const
	{
		return items[index];
	}
	int getSize() const
	{
		return size;
	}
	int getCapacity() const
	{
		return capacity;
	}
	void setItems(Item* items)
	{
		this->items = items;
	}
	void setSize(int size)
	{
		this->size = size;
	}
	void setCapacity(int capacity)
	{
		this->capacity = capacity;
	}
	void saveStock()
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
			fout << "TOTAL PRICE: " << items[i].getTotalPrice() << "\n";
		}
		fout.close();
	}
	// fnction to load data from file
	void loadStock()
	{
		ifstream fin;
		fin.open("stock.txt");
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
			getline(fin, line7);
			long double totalPrice = stold(line7.substr(13, line7.length() - 1));

			Item item(name, code, quantity, price);
			addItem(item);
		}

		fin.close();
	}
	void addItem(Item item)
	{
		if (size == capacity)
		{
			resize();
		}
		items[size] = item;
		size++;
	}
	void removeItem(string itemCode)
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
		while (index == -1)
		{
			cout << "Item not found. Please enter a valid item code: ";
			cin >> itemCode;
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
	int updateItem(string itemCode, int quantity)
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
		if (index != -1)
			return index;
		else
		{
			//add quantity to the quantity of the item already in the stock
			cout << "Do you want to add or remove quantity? (1/2): ";
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				items[index].setQuantity(items[index].getQuantity() + quantity);
			}
			else if (choice == 2)
			{
				items[index].setQuantity(items[index].getQuantity() - quantity);
			}
			long double cost;
			cout << "Enter New item price: ";
			cin >> cost;
			items[index].setPrice(cost);
			items[index].setTotalPrice();
		}

	}


	void updateItem(int quantity, string itemName)
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


	int searchItem(string itemCode)
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

	bool CheckItemAvailabillity(string itemName, string& itemCode, int& quantity, long double& price)
	{
		int index = -1;
		int flag = 1;
		bool status;
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
			cout << "Item not found" << endl;
			cout << "Please enter correct item Name\n";
			status = false;
		}
		else
		{
			itemCode = items[index].getItemCode();
			price = items[index].getPrice();
			quantity = items[index].getQuantity();
			status = true;
		}
		return status;
	}
	void gotoXY(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	void printStock()
	{
		if (size == 0)
		{
			cout << "Stock is empty" << endl;
		}
		else
		{

			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 15);
			gotoXY(0, 5);
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			gotoXY(0, 6);
			cout << "ITEM #";
			gotoXY(18, 6);
			cout << "| ITEM NAME";
			gotoXY(36, 6);
			cout << "| ITEM CODE";
			gotoXY(54, 6);
			cout << "| QUANTITY";
			gotoXY(72, 6);
			cout << "| PRICE";
			gotoXY(90, 6);
			cout << "| TOTAL PRICE";
			gotoXY(0, 7);
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < size; i++)
			{
				gotoXY(0, 8 + i);
				cout << i + 1;
				gotoXY(18, 8 + i);
				cout << "| " << items[i].getItemName();
				gotoXY(36, 8 + i);
				cout << "| " << items[i].getItemCode();
				gotoXY(54, 8 + i);
				cout << "| " << items[i].getQuantity();
				gotoXY(72, 8 + i);
				cout << "| " << items[i].getPrice();
				gotoXY(90, 8 + i);
				cout << "| " << items[i].getTotalPrice();
			}
			gotoXY(0, 8 + size);
			cout << "-------------------------------------------------------------------------------------------------------" << endl;
			SetConsoleTextAttribute(h, 7);
		}

	}

};


#endif // !STOCK_H


