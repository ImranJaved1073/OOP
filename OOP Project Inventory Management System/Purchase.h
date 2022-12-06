#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
#include "Stock.h"
#include <iostream>
#include <fstream>
using namespace std;

class Purchase
{
	Item* PurchaseItem;
	int purchaseSize;
	int currentSize;
	void resize();
public:
	Purchase();
	Purchase(const Purchase&);
	const Purchase& operator=(const Purchase&);
	Purchase(Item*, int);
	int getPurchaseSize() const;
	int getCurrentSize() const;
	void setIndex(int);
	Item* getPurchaseItemArray() const;
	~Purchase();

	void setItemPurshased(Item*, int);
	void addPurshase(Stock&);
	bool updatePurchasedItem(string, Stock&);
	bool deletePurchasedItem(string, Stock&);
	int searchPurchasedItem(string name);
	void displayReceipt();

	void gotoXY(int, int);

	void pauseAndClear();

};

#endif // !PURCHASE_H
