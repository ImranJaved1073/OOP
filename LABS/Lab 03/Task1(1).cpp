#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;
int size = 2;
struct InventoryItem
{
	int itemCode=0;
	string itemName={};
	double cost=0;
	double sellingPrice=0;
};

InventoryItem insertItem( );
void displayStock(const InventoryItem*);
int main()
{
	unsigned seed = time(0);
	srand(seed);
	int random = (rand() % 300) + 400;
	InventoryItem totalItems[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the details of item " << i + 1;
		totalItems[i] = insertItem();
		totalItems[i].itemCode = random + (i + 1);
		totalItems[i].sellingPrice = ((totalItems[i].cost) * 0.40) + totalItems[i].cost;
	}

	cout << "Item Name " << setw(20) << "Item Cost" << setw(20) 
		<< "Item Code" << setw(20) << "Item Selling Price";
	displayStock(totalItems);
}
void displayStock(const InventoryItem* items)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl << setw(2);
		cout << items[i].itemName << setw(22);
		cout << items[i].cost << setw(22);
		cout << items[i].itemCode << setw(22);
		cout << items[i].sellingPrice << setw(22);
	}
}
InventoryItem insertItem()
{
	InventoryItem totalItems;
		cout << "\nEnter Name of item: ";
		cin >> totalItems.itemName;
		cout << "Enter cost of item: ";
		cin >> totalItems.cost;
	return totalItems;
}