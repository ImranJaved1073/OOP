#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
	string itemName;
	string itemCode;
	int quantity;
	long double price;
	long double totalPrice;

public:
	Item()
	{
		itemName = "";
		itemCode = "";
		quantity = 0;
		price = 0;
		totalPrice = 0;
	}

	Item(string itemName, string itemCode, int quantity, long double price)
	{
		this->itemName = itemName;
		this->itemCode = itemCode;
		this->quantity = quantity;
		this->price = price;
		this->totalPrice = quantity * price;
	}

	void setItemName(string itemName)
	{
		this->itemName = itemName;
	}

	void setItemCode(string itemCode)
	{
		this->itemCode = itemCode;
	}

	void setQuantity(int quantity)
	{
		this->quantity = quantity;
	}

	void setPrice(long double price)
	{
		this->price = price;
	}

	void setTotalPrice()
	{
		this->totalPrice = quantity * price;
	}
	string getItemName() const
	{
		return itemName;
	}

	string getItemCode() const
	{
		return itemCode;
	}

	int getQuantity() const
	{
		return quantity;
	}

	long double getPrice() const
	{
		return price;
	}

	long double getTotalPrice() const
	{
		return totalPrice;
	}
};




#endif // !ITEM_H



