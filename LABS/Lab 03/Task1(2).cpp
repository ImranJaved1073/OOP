#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct InventoryItem
{
	int itemCode=0;
	string itemName={};
	double cost=0;
	double sellingPrice=0;
};

InventoryItem insertItem( );
void displayStock(const InventoryItem*);
string toUpperCase(string);
int main()
{
	unsigned seed = time(0);
	srand(seed);
	int random=(rand() % 300)+400;
	const int N = 4;
	InventoryItem totalItems[N];
	for (int i = 0; i < N; i++)
	{
		cout << "Enter the details of item " << i + 1;
		totalItems[i] = insertItem();
		totalItems[i].itemCode = random + (i+1);
		totalItems[i].sellingPrice = ((totalItems[i].cost) * 0.40) + totalItems[i].cost;
	}
	cout << "____________________________________________________________________________________________\n";
	cout << setw(15)<< "Item Name " << setw(23) << "Item Cost" << setw(22)
		<< "Item Code" << setw(31) << "Item Selling Price\n";
	cout << "____________________________________________________________________________________________\n";
	displayStock(totalItems);
}
void displayStock(const InventoryItem* items)
{
	for (int i = 0; i < 4; i++)
	{
		cout << endl;
		cout << setw(10)<<items[i].itemName << setw(22);
		cout << items[i].cost << setw(24);

		string b = items[i].itemName.substr(0, 3);
		b += '_';
		string c = toUpperCase(b);
		c += to_string(items[i].itemCode);
		cout << c << setw(22);

		cout << items[i].sellingPrice;
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

string toUpperCase(string convert)
{
	string roll = convert;
	for (int i = 0;i < 3;i++)
	{
		if (roll[i] >= 97 && roll[i] <= 122)
			roll[i] -= 32;
	}
	return roll;
}