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
	Item();
	Item(string, string, int, long double);

	void setItemName(string);
	void setItemCode(string);
	void setQuantity(int);
	void setPrice(long double);
	void setTotalPrice();

	string getItemName() const;
	string getItemCode() const;
	int getQuantity() const;
	long double getPrice() const;
	long double getTotalPrice() const;
};

#endif // !ITEM_H
