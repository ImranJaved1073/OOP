#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void displayIntro();
void displayExit();
void displayMainMenu();

int getChoice();
int whoIsUser();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class User
{
private:
	string name;
	string userid;
	string contact;
public:

	User();
	void setUser(string, string, string);
	void print();
	string getName();
	string getPhone();
	string getUserid();
};

User::User()
{
	name = " ";
	userid = " ";
	contact = " ";
}

void User::setUser(string n, string id, string p)
{
	name = n;
	userid = id;
	contact = p;
}

void User::print()
{
	cout << "Name : " << name << endl;
	cout << "User Id : " << userid << endl;
	cout << "Phone Number : " << contact << endl;
}

string User::getName()
{
	return name;
}

string User::getPhone()
{
	return contact;
}

string User::getUserid()
{
	return userid;
}

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

Item::Item()
{
	itemName = "";
	itemCode = "";
	quantity = 0;
	price = 0;
	totalPrice = 0;
}

Item::Item(string itemName, string itemCode, int quantity, long double price)
{
	this->itemName = itemName;
	this->itemCode = itemCode;
	this->quantity = quantity;
	this->price = price;
	this->totalPrice = quantity * price;
}

void Item::setItemName(string itemName)
{
	this->itemName = itemName;
}

void Item::setItemCode(string itemCode)
{
	this->itemCode = itemCode;
}

void Item::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Item::setPrice(long double price)
{
	this->price = price;
}

void Item::setTotalPrice()
{
	this->totalPrice = quantity * price;
}

string Item::getItemName() const
{
	return itemName;
}

string Item::getItemCode() const
{
	return itemCode;
}

int Item::getQuantity() const
{
	return quantity;
}

long double Item::getPrice() const
{
	return price;
}

long double Item::getTotalPrice() const
{
	return totalPrice;
}

class Stock
{

private:
	Item* items;
	int size;
	int capacity;
	void resize();

public:
	Stock(int capacity = 1);
	Stock(const Stock& stock);
	~Stock();

	const Item* getItems() const;
	Item getItem(int) const;
	int getSize() const;
	int getCapacity() const;

	void setItems(Item*);
	void setSize(int);
	void setCapacity(int);
	void setItem(Item, int);

	void saveStock();
	void loadStock();

	void addItem(Item);
	void removeItem(string);
	int updateItem(string);
	void updateItem(int, string);
	int searchItem(string);
	int searchItemName(string);
	void printStock();

	void gotoXY(int, int);
	char getValidChoice();

	Stock operator=(const Stock& stock);

};

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

const Item* Stock::getItems() const
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
		SetConsoleTextAttribute(h, 15);
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
		SetConsoleTextAttribute(h, 7);
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
	Purchase(const Item*, int);
	int getPurchaseSize() const;
	int getCurrentSize() const;
	void setIndex(int);
	const Item* getPurchaseItemArray() const;
	~Purchase();

	void setItemPurshased(const Item*, int);
	void addPurshase(Stock&);
	bool updatePurchasedItem(string, Stock&);
	bool deletePurchasedItem(string, Stock&);
	int searchPurchasedItem(string name);
	void displayReceipt();

	void gotoXY(int, int);

	void pauseAndClear();

};

void Purchase::pauseAndClear()
{
	cout << "\n\n\t";
	system("pause");
	system("cls");
}

void Purchase::resize()
{
	purchaseSize++;
	Item* temp = new Item[purchaseSize];
	for (int i = 0; i < purchaseSize; i++)
	{
		if (i != purchaseSize - 1)
			temp[i] = PurchaseItem[i];
		else
			temp[i] = Item();
	}
	delete[] PurchaseItem;
	PurchaseItem = temp;
}

Purchase::Purchase()
{
	PurchaseItem = new Item[1];
	purchaseSize = 1;
	currentSize = 0;
}

int Purchase::getPurchaseSize() const
{
	return purchaseSize;
}

int Purchase::getCurrentSize() const
{
	return currentSize;
}

//copy constructor
Purchase::Purchase(const Purchase& purchase)
{
	this->PurchaseItem = new Item[purchase.purchaseSize];
	this->purchaseSize = purchase.purchaseSize;
	this->currentSize = purchase.currentSize;

	for (int i = 0; i < purchaseSize; i++)
	{
		this->PurchaseItem[i] = purchase.PurchaseItem[i];
	}
}

//overloaded assignment operator
const Purchase& Purchase::operator=(const Purchase& purchase)
{
	if (this != &purchase)
	{
		if (PurchaseItem != nullptr)
		{
			delete[] PurchaseItem;
			PurchaseItem = nullptr;
		}
		this->PurchaseItem = new Item[purchase.purchaseSize];
		this->purchaseSize = purchase.purchaseSize;
		this->currentSize = purchase.currentSize;
		for (int i = 0; i < purchaseSize; i++)
		{
			this->PurchaseItem[i] = purchase.PurchaseItem[i];
		}
	}
	return *this;
}

Purchase::Purchase(const Item* a, int s)
{
	PurchaseItem = new Item[s];
	purchaseSize = s;
	currentSize = 0;
	for (int i = 0; i < s; i++)
	{
		PurchaseItem[i] = a[i];
	}
}

const Item* Purchase::getPurchaseItemArray() const
{
	return PurchaseItem;
}

void Purchase::setIndex(int i)
{
	currentSize = i;
}

Purchase::~Purchase()
{
	if (PurchaseItem != nullptr)
	{
		delete[] PurchaseItem;
		PurchaseItem = nullptr;
	}
}
void Purchase::setItemPurshased(const Item* arr, int s)
{
	PurchaseItem = new Item[s];
	purchaseSize = s;
	currentSize = 0;
	for (int i = 0; i < s; i++)
	{
		PurchaseItem[i] = arr[i];
	}
}

void Purchase::addPurshase(Stock& obj)
{
	if (obj.getSize() != 0)
	{
		char choice;
		int  CustomerQuantity = -1;
		int indextemp = -1;
		string itemName;


		do {
			//cin.ignore();
			//string itemCode; int quantity;
			obj.printStock();
			cout << "\n\n\t\tEnter item Name: ";

			getline(cin, itemName);

			indextemp = obj.searchItemName(itemName);

			while (indextemp == -1)
			{
				cout << "\033[A\33[2K\r";
				cout << "\u001b[31m\t\tItem not found!!\u001b[0mEnter valid item name: ";
				getline(cin, itemName);
				indextemp = obj.searchItemName(itemName);
			}

			//search for the item in the purchase list and if it exists then do not add it again
			if (searchPurchasedItem(itemName) != -1)
			{
				cout << "\n\n\t\tItem already exists in the purchase list";
			}

			else
			{
				cout << "\n\t\tHow much quantity of \u001b[33m" << itemName << "\u001b[0m do you want to purchase? ";
				cin >> CustomerQuantity;

				while (obj.getItem(indextemp).getQuantity() < CustomerQuantity)
				{
					cout << "\n\n\t\t\u001b[33mSorry, we don't have enough quantity of \u001b[34m" << itemName << "\u001b[33m. We only have \u001b[34m";
					cout << obj.getItem(indextemp).getQuantity() << "\u001b[33m " << itemName << endl;

					cout << "\u001b[0m\n\t\tPlease enter quantity less than or equal to " << obj.getItem(indextemp).getQuantity() << endl;

					cout << "\n\t\tHow many \u001b[33m" << itemName << "\u001b[0m do you want to purchase? ";
					cin >> CustomerQuantity;
				}
				PurchaseItem[currentSize] = obj.getItem(indextemp);
				PurchaseItem[currentSize].setQuantity(CustomerQuantity);
				PurchaseItem[currentSize].setTotalPrice();
				obj.updateItem(CustomerQuantity, itemName);
				currentSize++;
				if (currentSize >= purchaseSize)
					resize();
			}
			pauseAndClear();
			
			cout << "Do you want to purchase another item? (y/n): ";
			cin >> choice;
			cin.ignore(1000, '\n');
			
		} while (choice == 'y' || choice == 'Y');
		pauseAndClear();
	}

}

bool Purchase::updatePurchasedItem(string name, Stock& obj)
{
	int indexStockItem;
	int flag = searchPurchasedItem(name);
	int q = 0;

	if (flag != -1)
	{
		q = -PurchaseItem[flag].getQuantity();
		obj.updateItem(q, PurchaseItem[flag].getItemName());

		indexStockItem = obj.searchItem(PurchaseItem[flag].getItemCode());
		int quantity;
		do
		{
			cout << "Enter quantity of \u001b[33m" << PurchaseItem[flag].getItemName() << "\u001b[0m you want to buy: ";
			cin >> quantity;

		} while (quantity > obj.getItem(indexStockItem).getQuantity());
		
		PurchaseItem[flag].setQuantity(quantity);
		PurchaseItem[flag].setTotalPrice();
		obj.updateItem(quantity, PurchaseItem[flag].getItemName());
		
		return true;
	}
	else
	{
		return false;
	}
	//pauseAndClear();
}


bool Purchase::deletePurchasedItem(string name, Stock& obj)
{
	//int indexStockItem;
	if (currentSize != 0)
	{
		int flag = searchPurchasedItem(name);
		int q = 1;
		if (flag != -1)
		{
			obj.updateItem(-PurchaseItem[flag].getQuantity(), name);
		
			for (int i = flag; i < purchaseSize - 1; i++)
			{
				PurchaseItem[i] = PurchaseItem[i + 1];
			}
			currentSize--;
			cout << "\n\n\t\t\u001b[33m" << name << " \u001b[32mhas been succesfully deleted from purchased list!!\u001b[0m\n";
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "\n\n\t\t\u001b[31mNo items in the purchased list!!\u001b[0m\n";
		return false;
	}

	pauseAndClear();

}

int Purchase::searchPurchasedItem(string name)
{
	int index = -1;
	bool flag = false;
	for (int i = 0; i < purchaseSize && flag == false; i++)
	{
		if (name == PurchaseItem[i].getItemName())
		{
			index = i;
			flag = true;
		}
	}
	return index;
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

	for (int i = 0; i < currentSize; i++)
	{
		gotoXY(0, 8 + i);
		cout << i + 1;
		gotoXY(22, 8 + i);
		cout << "|" << PurchaseItem[i].getItemName();
		gotoXY(44, 8 + i);
		cout << "|" << PurchaseItem[i].getPrice();
		gotoXY(66, 8 + i);
		cout << "|" << PurchaseItem[i].getQuantity();
		gotoXY(88, 8 + i);
		cout << "|" << PurchaseItem[i].getTotalPrice();
		totalBill += PurchaseItem[i].getTotalPrice();
	}
	gotoXY(0, 8 + currentSize);
	cout << "------------------------------------------------------------------------------------------------------------" << endl;
	cout << "TOTAL BILL : " << totalBill << "$\n";
	cout << "------------------------------------------------------------------------------------------------------------\n";
	SetConsoleTextAttribute(h, 14);
}

class Admin :public User
{
private:
	string username;
	string password;
	Stock stock;
public:
	Admin();
	bool check();
	void changePassword();
	void displayAdminMenu();
	int getAdminChoice();
	void adminAccess();
	void pauseAndClear();

};

void Admin::pauseAndClear()
{
	cout << "\n\n\t";
	system("pause");
	system("cls");
}

HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);

Admin::Admin()
{
	username = "admin";
	password = "admin";
}

bool Admin::check()
{
	int count = 3;
	string password, line;
	bool flag = true;

	ifstream fin;
	fin.open("password.txt");
	if (fin)
	{
		getline(fin, line);
		password = line;
	}
	fin.close();

	while (count != 0 && flag)
	{
		cout << "\n\t\tEnter password: ";
		char ch;
		ch = _getch();
		for (int i = 0; i < password.length(); i++)
		{
			password[i] = ch;
			cout << '*';
			ch = _getch();
			while (ch == '\b')
			{
				--i;
				cout << "\b \b";
				ch = _getch();
			}

			if (ch == 27)
			{
				return false;
			}
		}

		if (password == line)
		{
			return true;
		}

		else
		{
			system("cls");
			SetConsoleTextAttribute(a, 4);
			cout << "\n\n\t\tWRONG PASSWORD!!" << endl;
			SetConsoleTextAttribute(a, 15);
			cout << "\n\n\t\tYou have ";
			SetConsoleTextAttribute(a, 10);
			cout << count - 1;
			SetConsoleTextAttribute(a, 15);
			cout << " attempts left." << endl;
		}
		count--;
	}
	return false;
}

void Admin::changePassword()
{
	string empPassword;
	ifstream fin;
	fin.open("password.txt");
	if (fin)
	{
		string line;
		getline(fin, line);
		getline(fin, line);
		empPassword = line;
	}
	fin.close();


	string password, confirm;
	cout << "\n\n\n\t\tEnter new password: ";
	getline(cin, password);
	cout << "\n\t\tConfirm New Password: ";
	getline(cin, confirm);
	while (password != confirm)
	{
		system("cls");
		SetConsoleTextAttribute(a, 4);
		cout << "\n\t\tPasswords do not match. Please try again!" << endl;
		SetConsoleTextAttribute(a, 15);
		cout << "\n\n\n\t\tEnter new password: ";
		getline(cin, password);
		cout << "\n\t\tConfirm New Password: ";
		getline(cin, confirm);
	}
	ofstream fout;
	fout.open("password.txt");
	if (fout)
	{
		fout << password << "\n";
		fout << empPassword;
		cout << "\n\n\t\t\u001b[32mPassword changed successfully!!\u001b[0m" << endl;
		SetConsoleTextAttribute(a, 15);
	}
	else
		cout << "\n\n\t \u001b[31mFile not found!! \u001b[0m" << endl;
	fout.close();
}

void Admin::displayAdminMenu()
{
	SetConsoleTextAttribute(a, 14);
	cout << "\n\n\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\n\t\t\t\t\t\t\t           INVENTORY MANAGEMENT SYSTEM\n";
	//cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\t\t\t\t\t\t\t                  ADMIN MENU\n";
	cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\n\t\t\t\t\t\t 1 - ADD NEW ITEM(s) IN STOCK";
	cout << "\n\t\t\t\t\t\t 2 - UPDATE ITEM(s) IN STOCK";
	cout << "\n\t\t\t\t\t\t 3 - DISPLAY ITEMS CURRENTLY IN STOCK";
	cout << "\n\t\t\t\t\t\t 4 - SEARCH ITEM(s) FROM STOCK";
	cout << "\n\t\t\t\t\t\t 5 - DELETE ITEM(s) FROM STOCK";
	cout << "\n\t\t\t\t\t\t 6 - CHANGE PASSWORD";
	cout << "\n\t\t\t\t\t\t 7 - EXIT & RETURN TO MAIN MENU (ALL CHANGES WILL BE SAVED)\n";
	cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	SetConsoleTextAttribute(a, 15);
}

int Admin::getAdminChoice()
{
	int choice = -1;

	while (!((choice > 0) && (choice < 8)))
	{
		cout << "\n\n\n\t\tEnter your choice: ";
		cin >> choice;

		system("cls");

		if (!((choice > 0) && (choice < 8)))
		{
			cout << "\n\n\t\t\t\t\t\t\u001b[35mPlease choose a valid number from the following options of menu.\u001b[0m\n\n";
			displayAdminMenu();
		}

		cin.clear();
		cin.ignore(1000, '\n');
	}
	return choice;
}

void Admin::adminAccess()
{
	stock.loadStock();
	int adminChoice;
	do
	{
		displayAdminMenu();
		adminChoice = getAdminChoice();
		switch (adminChoice)
		{
		case 1: //adding items to inventory
		{
			int count = 0;
			char choice = 'y';

			while (choice == 'y' || choice == 'Y')
			{
				count++;
				stock.printStock();
				pauseAndClear();
				string itemName, itemCode;

				int quantity = -1;
				long double price = -1;

				cout << "\n\n\n\t\tEnter item name: ";
				getline(cin, itemName);
				cout << "\n\t\tEnter item code: ";
				getline(cin, itemCode);

				//QUANTITY
				cout << "\n\t\tEnter quantity of\u001b[33m " << itemName << "\u001b[0m :";
				while (quantity < 1)
				{
					cin >> quantity;
					if (quantity < 1)
					{
						cout << "\033[A\33[2K\r";
						cout << "\t\t\u001b[31mInvalid Quantity.\u001b[0mEnter Valid Quantity of\u001b[33m " << itemName << "\u001b[0m ,must be greater than 0: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}

				//PRICE
				cout << "\n\t\tEnter price of\u001b[33m " << itemName << "\u001b[0m :";
				while (price < 1)
				{
					cin >> price;
					if (price < 1)
					{
						cout << "\033[A\33[2K\r";
						cout << "\u001b[31m\t\tValid Price of " << itemName << " must be more than 0. Please Enter again: \u001b[0m";
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}

				//calling ADD ITEM Member function
				Item item(itemName, itemCode, quantity, price);
				stock.addItem(item);

				cout << "\u001b[34m\n\n\t\t" << itemName << " against " << itemCode << " code added successfully!\u001b[0m" << endl << endl;

				pauseAndClear();
				cout << "\n\n\t\tDo you want to add another item to stock? (press y for yes and any other key for no): ";
				cin >> choice;
				cin.ignore();
			}
			cout << "\n\n\t\t\u001b[32m" << count << " Item(s) added successfully.\u001b[0m" << endl;

			cin.ignore(1000, '\n');
			pauseAndClear();
			break;

		}//end of case 1

		case 2://update the existing stock
		{
			if (stock.getSize() == 0)
			{
				cout << "\n\n\n\t\t\u001b[34mSTOCK IS EMPTY!!\u001b[0m" << endl;
			}
			else
			{
				string itemCode;
				int quantity = -1, index;

				char choice = 'y';

				while (choice == 'y' || choice == 'Y')
				{
					stock.printStock();
					pauseAndClear();

					cout << "\n\t\tEnter item code: ";
					getline(cin, itemCode);
					index = stock.updateItem(itemCode);

					if (index == -1)
						cout << "\u001b[31m\n\n\n\t\tThere is no Item with this Item Code.Add it to Stock.\u001b[0m\n";

					pauseAndClear();
					cout << "\n\n\n\t\tDo you want to update another item to stock? (press y for yes and any other key for no): ";
					cin >> choice;
					cin.ignore(10000, '\n');
				}
				pauseAndClear();

			}
			break;
		}//end of case 2

		case 3:// display the current stock
		{
			stock.printStock();
			pauseAndClear();

			break;
		}


		case 4://search for items if not found then admin has facility to add the item with same code
		{
			if (stock.getSize() == 0)
			{
				cout << "\n\n\n\t\t\u001b[34mSTOCK IS EMPTY!!\u001b[0m" << endl;
			}
			else
			{
				char choice = 'y';
				while (choice == 'y' || choice == 'Y')
				{

					string itemCode;
					int index;

					cout << "\n\n\tEnter item code: ";
					getline(cin, itemCode);

					index = stock.searchItem(itemCode);
					if (index == -1)
					{
						cout << "\u001b[31m\n\n\tThere is no Item with this Item Code.You can add it to inventory if you want\u001b[0m\n";

					}
					else
					{
						stock.gotoXY(50, 6);
						cout << "\u001b[32mITEM NAME:     \u001b[0m " << stock.getItem(index).getItemName() << endl;
						stock.gotoXY(50, 7);
						cout << "\u001b[32mITEM CODE:     \u001b[0m " << stock.getItem(index).getItemCode() << endl;
						stock.gotoXY(50, 8);
						cout << "\u001b[32mITEM QUANTITY: \u001b[0m " << stock.getItem(index).getQuantity() << endl;
						stock.gotoXY(50, 9);
						cout << "\u001b[32mITEM PRICE:    \u001b[0m " << stock.getItem(index).getPrice() << "/=\u001b[35m Rs.\u001b[0m" << endl;
					}

					pauseAndClear();

					cout << "\n\n\tDo you want to search another item? (press y for yes and any other key for no): ";
					cin >> choice;
					cin.ignore(1000, '\n');
				}
				pauseAndClear();

			}
			break;
		}//end of case 4


		case 5://remove
		{
			if (stock.getSize() == 0)
			{
				cout << "\n\n\n\t\t\u001b[34mSTOCK IS EMPTY!!\u001b[0m" << endl;
			}
			else
			{
				int count = 0;
				char choice = 'y';
				//cin.ignore();

				while (choice == 'y' || choice == 'Y')
				{
					stock.printStock();
					pauseAndClear();

					if (stock.getSize() != 0)
					{
						count++;
						string itemCode;
						cout << "\n\n\tEnter item code: ";
						getline(cin, itemCode);
						stock.removeItem(itemCode);
						cout << "\n\n\t\u001b[32mStock of Item removed successfully against\u001b[0m" << " \u001b[33mcode " << itemCode << ".\u001b[0m" << endl;
						cout << endl;
					}

					else
					{
						cout << "\n\n\t\t\u001b[34mNo more items can be removed because now Stock is empty.\u001b[0m" << endl;
						break;
					}

					pauseAndClear();
					cout << "\n\n\tDo you want to remove another item? (press y for yes and any other key for no): ";
					cin >> choice;
					cin.ignore(1000, '\n');
				}
				cout << "\n\n\t\t\u001b[32m" << count << " item(s) removed successfully.\u001b[0m" << endl;

				pauseAndClear();
			}
			break;
		}

		case 6:// change password if admin wants
		{
			changePassword();
			pauseAndClear();
			break;
		}

		case 7:// save all the changes made by admin to file
		{
			stock.saveStock();
			break;
		}

		default:
			cout << "\n\n\n\t\t\u001b[31mInvalid choice!!\u001b[0m" << endl;
			break;
		}

	} while (adminChoice != 7);
}

class Employee :public User
{
private:
	string password;
	Stock object;
public:
	Employee();
	bool check();

	void changePasswordEmployee();
	void displayEmployeeMenu();
	int getEmployeeChoice();
	void employeeAccess();
	void pauseAndClear();

};

void Employee::pauseAndClear()
{
	cout << "\n\n\t";
	system("pause");
	system("cls");
}

Employee::Employee()
{
	password = "";
}

bool Employee::check() // checks for validity of passwords thrice if passwaords match with database then return true
{
	int count = 3;
	bool status = true;
	string password, line;
	ifstream fin;
	fin.open("password.txt");
	if (fin)
	{
		getline(fin, line);
		getline(fin, line);
		password = line;
	}
	fin.close();

	while (count != 0 && status)
	{
		cout << "\n\t\tEnter password: ";
		char ch;
		ch = _getch();
		for (int i = 0; i < password.length(); i++)
		{
			password[i] = ch;
			cout << '*';
			ch = _getch();
			while (ch == '\b')
			{
				--i;
				cout << "\b \b";
				ch = _getch();
			}

			if (ch == 27)
			{
				status = false;
			}
		}

		if (password == line)
		{
			return true;
		}

		else
		{
			system("cls");
			SetConsoleTextAttribute(h, 4);
			cout << "\n\n\t\tWRONG PASSWORD!!" << endl;
			SetConsoleTextAttribute(h, 15);
			cout << "\n\n\t\tYou have ";
			SetConsoleTextAttribute(h, 10);
			cout << count - 1;
			SetConsoleTextAttribute(h, 15);
			cout << " attempts left." << endl;
		}
		count--;
	}

	return false;

}//end of check()

void Employee::changePasswordEmployee()//change password for employee
{
	ifstream fin;
	string line;
	string adminPassword;
	fin.open("password.txt");
	if (fin)
	{
		getline(fin, line);
		adminPassword = line;
	}

	string password, confirm;

	cout << "\n\n\n\t\tEnter new password: ";
	getline(cin, password);

	cout << "\n\t\tConfirm Password: ";
	getline(cin, confirm);

	while (password != confirm)
	{
		system("cls");
		SetConsoleTextAttribute(h, 4);
		cout << "\n\t\tPasswords do not match. Please try again!" << endl;
		SetConsoleTextAttribute(h, 15);
		cout << "\n\n\t\tEnter new password: ";
		getline(cin, password);
		cout << "\n\t\tConfirm Password: ";
		getline(cin, confirm);
	}
	ofstream fout;
	fout.open("password.txt");
	if (fout)
	{
		fout << line << "\n";
		fout << password;
		cout << "\n\n\t\t\u001b[32mPassword changed successfully!!\u001b[0m" << endl;
	}
	else
		cout << "\n\n\t \u001b[31mFile not found!! \u001b[0m" << endl;
	fout.close();

}


void Employee::displayEmployeeMenu()
{
	SetConsoleTextAttribute(h, 14);
	cout << "\n\n\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\n\t\t\t\t\t\t\t           INVENTORY MANAGEMENT SYSTEM\n";
	//cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\t\t\t\t\t\t\t                  EMPLOYEE MENU\n";
	cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\n\t\t\t\t\t\t 1 - UPDATE ITEM(s) IN STOCK";
	cout << "\n\t\t\t\t\t\t 2 - DISPLAY ITEMS CURRENTLY IN STOCK";
	cout << "\n\t\t\t\t\t\t 3 - SEARCH ITEM(s) FROM STOCK";
	cout << "\n\t\t\t\t\t\t 4 - CHANGE PASSWORD";
	cout << "\n\t\t\t\t\t\t 5 - EXIT & RETURN TO MAIN MENU (ALL CHANGES WILL BE SAVED)\n";
	cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	SetConsoleTextAttribute(h, 15);
}

int Employee::getEmployeeChoice()//return a valid choice
{
	int choice = -1;

	while (!((choice > 0) && (choice < 6)))
	{
		cout << "\n\n\n\t\tEnter your choice: ";
		cin >> choice;
		system("cls");
		if (!((choice > 0) && (choice < 6)))
		{
			cout << "\n\n\t\t\t\t\t\t\u001b[35mPlease choose a valid number from the following options of menu.\u001b[0m\n\n";
			displayEmployeeMenu();
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return choice;
}


void Employee::employeeAccess()
{
	object.loadStock();
	int employeeChoice;
	do
	{
		displayEmployeeMenu();
		employeeChoice = getEmployeeChoice();
		switch (employeeChoice)
		{
		case 1://update the item
		{
			if (object.getSize() == 0)
			{
				cout << "\n\n\n\t\t\u001b[34mSTOCK IS EMPTY!!\u001b[0m" << endl;
			}
			else
			{
				string itemCode; int quantity = -1; int index;
				char choice = 'y';

				while (choice == 'y' || choice == 'Y')
				{
					//cin.ignore();
					object.printStock();
					pauseAndClear();
					cout << "\n\n\n\t\tEnter item code: ";
					getline(cin, itemCode);

					index = object.updateItem(itemCode);
					if (index == -1)
						cout << "\u001b[31m\n\n\t\tItem not found!!\u001b[0m" << endl
						<< "\n\n\t\tKindly Inform the Admin that item is not in the stock" << endl
						<< "\t\tand also tell the Admin to add the item in the stock with this code." << endl;

					pauseAndClear();
					cout << "\n\n\t\tDo you want to update another item from stock? (press y for yes and any other key for no): ";
					cin >> choice;
					cin.ignore(1000, '\n');
				}
				pauseAndClear();
				//cin.clear();

			}

			break;
		}

		case 2:// display the current stock
		{
			object.printStock();
			pauseAndClear();
			break;
		}

		case 3:
		{
			if (object.getSize() == 0)
			{
				cout << "\n\n\n\t\t\u001b[34mSTOCK IS EMPTY!!\u001b[0m" << endl;
			}
			else
			{
				char choice = 'y';
				//cin.ignore();
				while (choice == 'y' || choice == 'Y')
				{
					string itemCode; int index;
					cout << "\n\t\t" << "Enter item code: ";
					getline(cin, itemCode);
					index = object.searchItem(itemCode);
					if (index == -1)
					{
						cout << "\u001b[31m\n\n\t\tItem not found!!\u001b[0m" << endl;
						cout << "\n\n\t\tKindly inform the Admin that item is not in the stock whick you are searching" << endl;
						cout << "\t\tso that he can add the item in the stock " << endl;
					}
					else
					{
						object.gotoXY(50, 6);
						cout << "\u001b[32mITEM NAME:     \u001b[0m " << object.getItem(index).getItemName() << endl;
						object.gotoXY(50, 7);
						cout << "\u001b[32mITEM CODE:     \u001b[0m " << object.getItem(index).getItemCode() << endl;
						object.gotoXY(50, 8);
						cout << "\u001b[32mITEM QUANTITY: \u001b[0m " << object.getItem(index).getQuantity() << endl;
						object.gotoXY(50, 9);
						cout << "\u001b[32mITEM PRICE:    \u001b[0m " << object.getItem(index).getPrice() << "/=\u001b[35m Rs.\u001b[0m" << endl;
					}
					pauseAndClear();
					cout << "\n\n\tDo you want to search another item? (press y for yes and any other key for no): ";
					cin >> choice;
					//cin.clear();
					cin.ignore(1000, '\n');
				}
				pauseAndClear();

			}
			break;
		}

		case 4:
		{
			changePasswordEmployee();
			pauseAndClear();
			break;
		}

		case 5:
		{
			object.saveStock();
			break;
		}

		default:
			cout << "\n\n\n\t\t\u001b[31mInvalid choice!!\u001b[0m" << endl;
			break;

		}
	} while (employeeChoice != 5);

}

class Customer : public User
{
private:
	string address;
	string email;
	string CNIC;
	Stock obj;
	Purchase purchaseItem;
public:
	Customer();
	void setCustomer(string, string, string, string, string, string);

	void print();
	string getAddress();
	string getEmail();
	string getCNIC();

	void displayCustomerMenu();

	int getCustomerChoice();

	void gotoXY(int, int);

	void saveReceipt();
	void customerAccess();
	void pauseAndClear();
};

void Customer::pauseAndClear()
{
	cout << "\n\n\t";
	system("pause");
	system("cls");
}

Customer::Customer()
{
	address = "";
	email = "";
}

void Customer::setCustomer(string name, string id, string contact, string address, string email, string CNIC)
{
	User::setUser(name, id, contact);
	this->address = address;
	this->email = email;
	this->CNIC = CNIC;
}

void Customer::print()
{
	User::print();
	cout << "Address : " << address << endl;
	cout << "Email : " << email << endl;
}

string Customer::getAddress()
{
	return address;
}

string Customer::getEmail()
{
	return email;
}

string Customer::getCNIC()
{
	return CNIC;
}

void Customer::displayCustomerMenu()
{
	SetConsoleTextAttribute(h, 14);
	cout << "\n\n\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\n\t\t\t\t\t\t\t           INVENTORY MANAGEMENT SYSTEM\n";
	cout << "\t\t\t\t\t\t\t                  CUSTOMER MENU\n";
	cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	cout << "\n\t\t\t\t\t\t 1 - PURCHASE ITEM(s) FROM STOCK";
	cout << "\n\t\t\t\t\t\t 2 - DISPLAY ITEMS CURRENTLY IN STOCK";
	cout << "\n\t\t\t\t\t\t 3 - SEARCH ITEM(s) FROM STOCK";
	cout << "\n\t\t\t\t\t\t 4 - UPDATE PURCHASE";
	cout << "\n\t\t\t\t\t\t 5 - GENERATE RECEIPT";
	cout << "\n\t\t\t\t\t\t 6 - DELETE A PURCHASED ITEM";
	cout << "\n\t\t\t\t\t\t 7 - EXIT & RETURN TO MAIN MENU (ALL CHANGES WILL BE SAVED)\n";
	cout << "\t\t\t\t\t\t_________________________________________________________________\n";
	SetConsoleTextAttribute(h, 15);
}

int Customer::getCustomerChoice()
{
	int choice = -1;
	while (!((choice > 0) && (choice < 8)))
	{
		cout << "\n\n\n\t\tEnter your choice: ";
		cin >> choice;
		system("cls");
		if (!((choice > 0) && (choice < 8)))
		{
			cout << "\n\n\t\t\t\t\t\t\u001b[35mPlease choose a valid number from the following options of menu.\u001b[0m\n\n";
			displayCustomerMenu();
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return choice;
}

void Customer::gotoXY(int x, int y)// to set position of cursor
{
	COORD coord{};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//funtion to Save Receipt to file against customer details
void Customer::saveReceipt()
{
	long double totalBill = 0;
	ofstream fout;
	fout.open(getName() + ".txt");
	fout << "Customer Name: " << getName() << endl;
	fout << "Customer CNIC: " << getCNIC() << endl;
	fout << "Customer Phone Number: " << getPhone() << endl;
	fout << "Customer Address: " << getAddress() << endl;
	fout << "Customer Email: " << getEmail() << endl;

	fout << "-------------------------------------------------------------------------------------------";
	fout << "\n\t\t\t\t\t\tRECEIPT\n";
	fout << "-------------------------------------------------------------------------------------------";
	fout << "\nITEM NAME\t\tSINGLE ITEM PRICE\t\tITEM QUANTITY\t\tTOTAL PRICE\n";
	fout << "-------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < purchaseItem.getCurrentSize(); i++)
	{
		fout << purchaseItem.getPurchaseItemArray()[i].getItemName() << "\t\t\t\t" << purchaseItem.getPurchaseItemArray()[i].getPrice() << "\t\t\t\t" << purchaseItem.getPurchaseItemArray()[i].getQuantity() << "\t\t   " << purchaseItem.getPurchaseItemArray()[i].getTotalPrice() << endl;
		totalBill += purchaseItem.getPurchaseItemArray()[i].getTotalPrice();
	}
	fout << "-------------------------------------------------------------------------------------------\n";
	fout << "TOTAL BILL : " << totalBill << "$\n";
	fout << "-------------------------------------------------------------------------------------------\n";
}

void Customer::customerAccess()
{
	string itemName;
	string itemCode;
	bool receiptStatus = false;
	int count = 0;
	obj.loadStock();
	int customerChoice;
	string name, cnic, phone, address, email;
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your CNIC: ";
	getline(cin, CNIC);
	cout << "Enter your phone number: ";
	getline(cin, phone);
	cout << "Enter your address: ";
	getline(cin, address);
	cout << "Enter your email: ";
	getline(cin, email);
	setCustomer(name, "0", CNIC, phone, address, email);
	pauseAndClear();
	do
	{
		displayCustomerMenu();
		customerChoice = getCustomerChoice();
		switch (customerChoice)
		{
		case 1:
		{
			obj.printStock();
			receiptStatus = false;
			purchaseItem.addPurshase(obj);

			break;
		}

		case 2:
		{
			obj.printStock();
			pauseAndClear();
			break;
		}

		case 3:
		{
			if (obj.getSize() != 0)
			{
				int indexOfItem = -1;

				char choice = 'y';
				//cin.ignore();
				while (choice == 'y' || choice == 'Y')
				{
					do {
						string itemname;
						cout << "\n\n\n\t\tEnter item name: ";
						getline(cin, itemname);
						indexOfItem = obj.searchItemName(itemname);
						if (indexOfItem == -1)
							cout << "\u001b[31m\n\n\t\tItem not found" << endl << "Please enter correct item Name.\u001b[0m\n";
						else
						{
							obj.gotoXY(50, 7);
							cout << "\u001b[32mITEM NAME:     \u001b[0m " << obj.getItem(indexOfItem).getItemName() << endl;
							obj.gotoXY(50, 8);											  
							cout << "\u001b[32mITEM QUANTITY: \u001b[0m " << obj.getItem(indexOfItem).getQuantity() << endl;
							obj.gotoXY(50, 9);											 
							cout << "\u001b[32mITEM PRICE:    \u001b[0m " << obj.getItem(indexOfItem).getPrice() << "/=\u001b[35m Rs.\u001b[0m" << endl;
						}
					} while (indexOfItem == -1);
					pauseAndClear();
					cout << endl << "\n\n\tDo you want to search another item? (press y for yes and any other key for no): ";
					cin >> choice;
					cin.ignore();
				}
			}
			pauseAndClear();
			cin.ignore(1000, '\n');

			break;
		}

		case 4://update purchased item list 
		{
			if (obj.getSize() != 0)
			{
				if (receiptStatus == true)
				{
					cout << "\n\n\n\t\t\u001b[34mReceipt has already been generated.\u001b[0m" << endl;
				}
				else if (purchaseItem.getCurrentSize() > 0)
				{

					string name;

					bool flag = true;
					char choice = 'y';
					while (choice == 'y' || choice == 'Y')
					{
						do
						{
							if (flag == false)
							{
								cout << "\n\n\t\t\u001b[31mThe Item name you entered did not match to any item!!\u001b[0m\n";
								cout << "\n\t\tPlease enter correct Item name.\n";
							}
							purchaseItem.displayReceipt();
							//pauseAndClear();
							cout << "\n\t\tEnter the name of item: ";
							getline(cin, name);
							flag = purchaseItem.updatePurchasedItem(name, obj);

						} while (flag == false);
						pauseAndClear();
						cout << endl << "\n\n\tDo you want to update another item? (press y for yes and any other key for no): ";
						cin >> choice;
						cin.ignore();
					}
				}
				else
				{
					cout << "\n\n\t\t\t\t\t\t\u001b[35mNO ITEMS PURCHASED YET!!.\u001b[0m\n\n";
				}
			}

			pauseAndClear();
			break;
		}


		case 5:
		{
			if (purchaseItem.getCurrentSize() > 0)
			{
				SetConsoleTextAttribute(h, 10);
				gotoXY(0, 2);
				cout << "------------------------------------------------------------------------------------------------------------";
				gotoXY(0, 3);
				cout << "\n\t\t\t\t\t\tRECEIPT\n";
				purchaseItem.displayReceipt();
				SetConsoleTextAttribute(h, 15);
				receiptStatus = true;
			}
			else
			{
				cout << "\n\n\t\t\t\t\t\t\u001b[35mNO ITEMS PURCHASED YET!!.\u001b[0m\n\n";
			}
			//saveReceipt();
			pauseAndClear();
			break;
		}

		case 6:
		{
			if (receiptStatus == true)
			{
				cout << "\n\n\t\t\u001b[34mReceipt is already generated.\u001b[0m" << endl;
			}
			else if (purchaseItem.getCurrentSize() > 0 && receiptStatus == false)
			{
				purchaseItem.displayReceipt();
				string name;
				char choice = 'y';

				bool flag = true;
				while (choice == 'y' || choice == 'Y')
				{
					if (purchaseItem.getCurrentSize() != 0)
					{
						do
						{
							if (flag == false)
							{
								cout << "\n\n\t\t\u001b[31mThe Item name you entered did not match to any item\u001b[0m\n";
								cout << "\n\n\t\tPlease enter correct Item name .\n";
							}
							cout << "\n\t\tEnter the name of item: ";
							getline(cin, name);
							flag = purchaseItem.deletePurchasedItem(name, obj);

						} while (flag == false);
					}
					else
					{
						cout << "\n\t\tNo more items can be removed because now Shoping cart is empty." << endl;
						pauseAndClear();
						break;
					}
					cout << "\n\t\tDo you want to remove another item? (press y for yes and any other key for no): ";
					cin >> choice;
					cin.ignore(1000, '\n');
				}
			}
			else
			{
				cout << "\n\n\t\t\t\t\t\t\u001b[35mNO ITEMS PURCHASED YET!!.\u001b[0m\n\n";
			}
			pauseAndClear();
			break;
		}

		case 7:
		{
			obj.saveStock();
			saveReceipt();
			break;
		}

		}//switch
	} while (customerChoice != 7);
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	Stock stock;
	displayIntro();

	//stock.loadStock();
	int choice;
	string username, password;
	do
	{
		choice = whoIsUser();
		switch (choice)
		{
		case 1:
		{
			Admin admin;
			cout << "\n\n\n\t\tUser Name : ";
			cin.ignore();
			getline(cin, username);
			if (admin.check())
			{
				cout << "\n\n\n\t\t------------------------------------";
				SetConsoleTextAttribute(h, 10);
				cout << "\n\t\t         LOGIN SUCCESSFUL\n";
				SetConsoleTextAttribute(h, 15);
				cout << "\t\t------------------------------------\n";

				admin.pauseAndClear();
				admin.adminAccess();
			}
			else
			{
				system("cls");

				cout << "\n\n\t----------------------------------------------\n";
				SetConsoleTextAttribute(h, 4);
				cout << "\n\t       YOU HAVE ENTERED WRONG PASSWORD\n";
				cout << "\t    WE CANNOT GIVE YOU ACCESS TO ADMIN PAGE\n";
				SetConsoleTextAttribute(h, 15);
				cout << "\n\t----------------------------------------------\n";
				admin.pauseAndClear();
			}

			break;
		}

		case 2:
		{
			Employee employee;
			cout << "\n\n\n\t\tUser Name : ";
			cin.ignore();
			getline(cin, username);

			if (employee.check() == true)
			{
				cout << "\n\n\n\t\t------------------------------------";
				SetConsoleTextAttribute(h, 10);
				cout << "\n\t\t         LOGIN SUCCESSFUL\n";
				SetConsoleTextAttribute(h, 15);
				cout << "\t\t------------------------------------\n";
				employee.pauseAndClear();
				employee.employeeAccess();
			}
			else
			{
				system("cls");
				cout << "\n\n\t------------------------------------";
				SetConsoleTextAttribute(h, 4);
				cout << "\n\tYOU HAVE ENTERED THE WRONG PASSWORD\n";
				SetConsoleTextAttribute(h, 15);
				cout << "\t------------------------------------\n";
				employee.pauseAndClear();
			}

			break;

		}

		case 3:
		{
			Customer customer;
			customer.customerAccess();

			break;
		}


		case 4:
		{
			displayExit();
			cout << "\n\n\t";
			system("pause");
			break;

		}

		default:
			cout << "Invalid choice" << endl;
			break;
		}

	} while (choice != 4);

	return 0;
}

void displayMainMenu()
{
	SetConsoleTextAttribute(h, 15);
	cout << "\n\n\t\t\t\t\t\t\t__________________________________________________\n";
	cout << "\n\t\t\t\t\t\t\t|\t \u001b[43m   INVENTORY MANAGEMENT SYSTEM  \u001b[0m        |\n";
	//cout << "\t\t\t\t\t\t\t__________________________________________________
	cout << "\t\t\t\t\t\t\t|\t \u001b[32m            MAIN MENU           \u001b[0m        |\n";
	cout << "\t\t\t\t\t\t\t__________________________________________________\n";
	cout << "\n\t\t\t\t\t\t\t| 1 - LOGIN AS ADMIN                             |";
	cout << "\n\t\t\t\t\t\t\t| 2 - LOGIN AS EMPLOYEE                          |";
	cout << "\n\t\t\t\t\t\t\t| 3 - ENTER TO PURCHASE AS CUSTOMER              |";
	cout << "\n\t\t\t\t\t\t\t| 4 - EXIT (ALL CHANGES WILL BE SAVED)           |";
	cout << "\n\t\t\t\t\t\t\t__________________________________________________\n";
	SetConsoleTextAttribute(h, 15);
}

int getChoice()
{
	int choice = -1;
	while (!((choice > 0) && (choice < 5)))
	{
		cout << "\n\n\n\t\tEnter your choice: ";
		cin >> choice;
		system("cls");
		if (!((choice > 0) && (choice < 5)))
		{
			cout << "\n\n\t\t\t\t\t\t\u001b[35mPlease choose a valid number from the following options of menu.\u001b[0m\n\n";
			displayMainMenu();
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return choice;
}



int whoIsUser()
{
	displayMainMenu();
	int choice = getChoice();
	return choice;
}


void displayIntro()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t  \u001b[33m*************************************************\u001b[0m" << endl;
	cout << "\t\t\t\t\t\t\t \u001b[33m *        WELCOME TO INVENTORY MANAGEMENT        *\u001b[0m" << endl;
	cout << "\t\t\t\t\t\t\t  \u001b[33m*************************************************\u001b[0m" << endl;
	cout << "\n\n\n\n\n\n\t\t\t\t\t";
	system("pause");
	system("cls");
}

void displayExit()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  \u001b[33m********************************************************\u001b[0m" << endl;
	cout << "\t\t\t\t\t\t \u001b[33m *     THANK YOU FOR USING THE INVENTORY MANGEMENT      *\u001b[0m" << endl;
	cout << "\t\t\t\t\t\t  \u001b[33m********************************************************\u001b[0m" << endl;
	cout << "\n\n\n\n\n\n\t\t\t\t\t";
	system("pause");
	system("cls");
}