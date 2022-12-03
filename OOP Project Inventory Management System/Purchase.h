#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
#include "Stock.h"
#include <iostream>
#include <fstream>
//#include <Windows.h>
using namespace std;

class Purchase
{
	Item* PurchaseItemArray;
	int purchaseSize;
public:
	Purchase();
	Purchase(const Purchase&);
	const Purchase& operator=(const Purchase&);
	Purchase(Item*, int);
	int getPurchaseSize() const;
	int getNumberOfPurchasedItems();
	Item* getPurchaseItemArray() const;
	~Purchase();
	
	void setItemPurshased(Item*, int);
	void addPurshase(Stock&);
	bool updatePurchasedItem(string, Stock&);
	bool deletePurchasedItem(string, Stock&);
	void displayReceipt();
	
	void gotoXY(int, int);

	void pauseAndClear();

};

#endif // !PURCHASE_H
