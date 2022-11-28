#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void displayMainMenu();

int getChoice();
int whoIsUser();

class User
{
private:
	string name;
	string userid;
	string contact;
public:

	User()
	{
		name = " ";
		userid = " ";
		contact = " ";
	}
	void setUser(string n, string id, string p)
	{
		name = n;
		userid = id;
		contact = p;
	}
	void print()
	{
		cout << "Name : " << name << endl;
		cout << "User Id : " << userid << endl;
		cout << "Phone Number : " << contact << endl;
	}
	string getName()
	{
		return name;
	}
	string getPhone()
	{
		return contact;
	}
	string getUserid()
	{
		return userid;
	}                                                     													   //admin class :public user

};

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
		else
			return index;

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

class Admin :public User
{
private:
	string username;
	string password;
public:
	Admin()
	{
		username = "admin";
		password = "admin";
	}
	bool check()
	{
		int count = 3;
		string password; string line;
		ifstream fin;
		fin.open("password.txt");
		if (fin)
		{
			getline(fin, line);
			password = line;
		}
		else
			cout << "File not found" << endl;
		fin.close();

		while (count--)
		{
			cout << "Enter password: ";
			char ch;
			ch = _getch();
			for (int i = 0; i < password.length(); i++)
			{
				password[i] = ch;
				cout << '*';
				ch = _getch();
			}

			if (password == line)
				return true;
			cout << "\nYou have entered Wrong password!!! Try Again\n";
		}

		return false;
	}

	void changePassword()
	{
		string password;
		string confirm;
		cout << "Enter new password: ";
		cin >> password;
		cout << "Confirm Password: ";
		cin >> confirm;
		while (password != confirm)
		{
			cout << "Passwords do not match. Please try again." << endl;
			cout << "Enter new password: ";
			cin >> password;
			cout << "Confirm Password: ";
			cin >> confirm;
		}
		ofstream fout;
		fout.open("password.txt");
		if (fout)
		{
			fout << password;
			cout << "Password changed successfully" << endl;
		}
		else
			cout << "File not found" << endl;
		fout.close();
	}

	void displayAdminMenu()
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t____________________________________________________________________________________\n";
		cout << "\n\t\t\t\t\t INVENTORY MANAGEMENT SYSTEM\n";
		cout << "\t\t\t\t\t          ADMIN MENU\n";
		cout << "\t\t____________________________________________________________________________________\n";
		cout << "\n\t\t 1 - Add New Items Stock.";
		cout << "\n\t\t 2 - Update the Stock of Items.";
		cout << "\n\t\t 3 - Display Current Stock of Items.";
		cout << "\n\t\t 4 - Search Stock of an Item.";
		cout << "\n\t\t 5 - Delete a Stock of Items from Inventory.";
		cout << "\n\t\t 6 - Exit(On Exit all the Changes will be saved and return to main menu).\n";
		cout << "\t\t____________________________________________________________________________________\n";
		SetConsoleTextAttribute(h, 15);
	}

	int getAdminChoice()
	{
		int choice = -1;
		while (!((choice > 0) && (choice < 8)))
		{
			cout << "\n\n\tEnter your choice: ";
			cin >> choice;
			system("cls");
			if (!((choice > 0) && (choice < 8)))
			{
				cout << "\n\tPlease choose a valid number from the following options of menu.\n";
				displayAdminMenu();
			}
			cin.clear();
			cin.ignore(1000, '\n');
		}
		return choice;
	}

	void adminAccess(Stock stock)
	{

		stock.loadStock();
		int adminChoice;
		do
		{
			displayAdminMenu();
			adminChoice = getAdminChoice();
			switch (adminChoice)
			{
			case 1:
			{
				cout << "How many items do you want to add?" << endl;
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					string itemName;
					string itemCode;
					int quantity;
					long double price;
					cout << "Enter item name: ";
					cin >> itemName;
					cout << "Enter item code: ";
					cin >> itemCode;
					cout << "Enter item quantity: ";
					cin >> quantity;
					cout << "Enter item price: ";
					cin >> price;
					Item item(itemName, itemCode, quantity, price);
					stock.addItem(item);
					cout << endl;
					cout << "Stock of Item added successfully." << endl;
				}
				cout << n << " Items added successfully." << endl;
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}

			case 2:
			{
				cout << "How many items do you want to update?" << endl;
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					string itemCode; int quantity; int index;
					cout << "Enter item code: ";
					cin >> itemCode;
					cout << "Enter item quantity to update: ";
					cin >> quantity;
					index = stock.updateItem(itemCode, quantity);
					if (index == -1)
					{
						cout << "There is no Item with this Item Code\n";
						cout << "Do you want to add the item to inventory? (y/n)" << endl;
						char choice;
						cin >> choice;
						if (choice == 'y')
						{
							string itemName;
							long double price;
							cout << "Enter item name: ";
							cin >> itemName;
							cout << "Enter item price: ";
							cin >> price;
							Item item(itemName, itemCode, quantity, price);
							stock.addItem(item);
						}
					}
					cout << endl;
					cout << "Stock of Item updated successfully . " << endl;
				}
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}

			case 3:
			{
				stock.printStock();
				cout << "Press Enter to continue...";
				cin.get();
				system("cls");

				break;
			}


			case 4:
			{
				cout << "How many items do you want to search?" << endl;
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					string itemCode; int index;
					cout << "Enter item code: ";
					cin >> itemCode;
					index = stock.searchItem(itemCode);
					if (index == -1)
					{
						cout << "There is no Item with this Item Code\n";
						cout << "Do you want to add the item to inventory? (y/n)" << endl;
						char choice;
						cin >> choice;
						if (choice == 'y')
						{
							string itemName;
							int quantity;
							long double price;
							cout << "Enter item name: ";
							cin >> itemName;
							cout << "Enter item quantity: ";
							cin >> quantity;
							cout << "Enter item price: ";
							cin >> price;
							Item item(itemName, itemCode, quantity, price);
							stock.addItem(item);
						}
					}
					else
					{
						cout << "Item name: " << stock.getItem(index).getItemName() << endl;
						cout << "Item code: " << stock.getItem(index).getItemCode() << endl;
						cout << "Item quantity: " << stock.getItem(index).getQuantity() << endl;
						cout << "Item price: " << stock.getItem(index).getPrice() << endl;
						cout << "Total price: " << stock.getItem(index).getTotalPrice() << endl;
					}
					cout << endl;
				}
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}

			case 5:
			{
				cout << "How many items do you want to remove?" << endl;
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					string itemCode;
					cout << "Enter item code: ";
					cin >> itemCode;
					stock.removeItem(itemCode);
					cout << "Stock of Item removed successfully . " << endl;
					cout << endl;
				}
				cout << n << " items removed successfully." << endl;
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}

			case 6:
			{
				stock.saveStock();
				break;
			}

			default:
				cout << "Invalid choice" << endl;
				break;
			}

		} while (adminChoice != 6);
	}

};

class Employee :public User
{
private:
	string password;
	Stock stock;
public:
	Employee()
	{
		password = "";
	}
	bool check()
	{
		bool status;
		string password; string line;
		ifstream fin;
		fin.open("password.txt");
		if (fin)
		{
			getline(fin, line);
			getline(fin, line);
			password = line;
		}
		else
			cout << "File not found" << endl;
		fin.close();

		cout << "Enter password: ";
		char ch;
		ch = _getch();
		for (int i = 0; i < password.length(); i++)
		{
			password[i] = ch;
			cout << '*';
			ch = _getch();
		}

		if (password == line)
			status = true;
		else
			status = false;

		return status;

	}
	
	void changePasswordEmployee()
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
		else
			cout << "File not found" << endl;
		fin.close();

		string password;
		string confirm;
		cout << "Enter new password: ";
		cin >> password;
		cout << "Confirm Password: ";
		cin >> confirm;
		while (password != confirm)
		{
			cout << "Passwords do not match. Please try again." << endl;
			cout << "Enter new password: ";
			cin >> password;
			cout << "Confirm Password: ";
			cin >> confirm;
		}
		ofstream fout;
		fout.open("password.txt");
		if (fout)
		{
			fout << line << endl;
			fout << password << endl;
			cout << "Password changed successfully" << endl;
		}
		else
			cout << "File not found" << endl;
		fout.close();

	}


	void displayEmployeeMenu()
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t____________________________________________________________________________________\n";
		cout << "\n\t\t\t\t\t INVENTORY MANAGEMENT SYSTEM\n";
		cout << "\t\t\t\t\t        EMPLOYEE MENU\n";
		cout << "\t\t____________________________________________________________________________________\n";
		cout << "\n\t\t 1 - Update the Stock of Items.";
		cout << "\n\t\t 2 - Display Current Stock of Items.";
		cout << "\n\t\t 3 - Search Stock of an Item.";
		cout << "\n\t\t 4 - Exit(On Exit all the Changes will be saved and return to main menu).\n";
		cout << "\t\t____________________________________________________________________________________\n";
		SetConsoleTextAttribute(h, 15);
	}

	int getEmployeeChoice()
	{
		int choice = -1;
		cout << "\n\t\t Enter your choice: ";
		while (!((choice > 0) && (choice < 5)))
		{
			cout << "\n\tEnter your choice: ";
			cin >> choice;
			system("cls");
			if (!((choice > 0) && (choice < 5)))
			{
				cout << "\n\tPlease choose a valid number from the following options of menu.\n";
				displayEmployeeMenu();
			}
			cin.clear();
			cin.ignore(1000, '\n');
		}
		return choice;
	}


	void employeeAccess()
	{
		stock.loadStock();
		int employeeChoice;
		do
		{
			displayEmployeeMenu();
			employeeChoice = getEmployeeChoice();
			switch (employeeChoice)
			{
			case 1:
			{
				cout << "How many items do you want update?" << endl;
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					string itemCode; int quantity; int index;
					cout << "Enter item code: ";
					cin >> itemCode;
					cout << "Enter item quantity to update: ";
					cin >> quantity;
					index = stock.updateItem(itemCode, quantity);
					if (index == -1)
						cout << "Item not found" << endl
						<< "Tell the Admin that item is not in the stock" << endl
						<< "and also tell the Admin to add the item in the stock with this code" << endl;

					cout << endl;
					cout << "Stock of Item updated successfully . " << endl;
				}
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}

			case 2:
			{
				stock.printStock();
				cout << "Press Enter to continue...";
				cin.get();
				system("cls");
				break;
			}

			case 3:
			{
				cout << "How many items do you want to search?" << endl;
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					string itemCode; int index = 0;
					cout << "Enter item code: ";
					cin >> itemCode;
					index = stock.searchItem(itemCode);
					if (index == -1)
						cout << "Item not found" << endl
						<< "Tell the Admin that item is not in the stock whick you are searching" << endl
						<< "so that he can add the item in the stock " << endl;
					else
					{
						cout << "Item #" << index + 1 << endl;
						cout << "Item name: " << stock.getItem(index).getItemName() << endl;
						cout << "Item code: " << stock.getItem(index).getItemCode() << endl;
						cout << "Item quantity: " << stock.getItem(index).getQuantity() << endl;
						cout << "Item price: " << stock.getItem(index).getPrice() << endl;
						cout << "Item total price: " << stock.getItem(index).getTotalPrice() << endl;
					}
					cout << endl;
				}
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}

			case 4:
			{
				stock.saveStock();
				break;
			}

			default:
				cout << "Invalid choice" << endl;
				break;

			}
		} while (employeeChoice != 4);

	}


};

class Purchase
{
	Item* PurchaseItemArray;
	int size;
public:
	Purchase()
	{
		PurchaseItemArray = nullptr;
		size = 0;
	}
	Purchase(Item* a, int s)
	{
		size = s;
		PurchaseItemArray = new Item[size];
		for (int i = 0; i < s; i++)
		{
			PurchaseItemArray[i] = a[i];
		}
	}
	~Purchase()
	{
		delete[]PurchaseItemArray;
		PurchaseItemArray = nullptr;
	}
	void setItemPurshased(Item* arr, int s)
	{
		size = s;
		PurchaseItemArray = new Item[size];
		for (int i = 0; i < size; i++)
		{
			PurchaseItemArray[i] = arr[i];
		}
	}
	void displayReceipt()
	{
		long double totalBill = 0;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 10);
		cout << "-------------------------------------------------------------------------------------------";
		cout << "\n\t\t\t\tRECEIPT\n";
		cout << "-------------------------------------------------------------------------------------------";
		cout << "\nITEM NAME\t\tSINGLE ITEM PRICE\t\tITEM QUANTITY\t\tTOTAL PRICE\n";
		cout << "-------------------------------------------------------------------------------------------\n";
		for (int i = 0; i < size; i++)
		{
			cout << PurchaseItemArray[i].getItemName() << "\t\t\t\t" << PurchaseItemArray[i].getPrice() << "\t\t\t\t" << PurchaseItemArray[i].getQuantity() << "\t\t   " << PurchaseItemArray[i].getTotalPrice() << endl;
			totalBill += PurchaseItemArray[i].getTotalPrice();
		}
		cout << "-------------------------------------------------------------------------------------------\n";
		cout << "TOTAL BILL : " << totalBill << "$\n";
		cout << "-------------------------------------------------------------------------------------------\n";
		SetConsoleTextAttribute(h, 14);
	}
};

class Customer : public User
{
private:
	string address;
	string email;
	Stock obj;
	Purchase purchaseItem;
public:
	Customer()
	{
		address = "";
		email = "";
	}
	void setCustomer(string n, string id, string p, string a, string e)
	{
		setUser(n, id, p);
		address = a;
		email = e;
	}
	void print()
	{
		User::print();
		cout << "Address : " << address << endl;
		cout << "Email : " << email << endl;
	}
	string getAddress()
	{
		return address;
	}
	string getEmail()
	{
		return email;
	}
	void displayCustomerMenu()
	{
		SetConsoleTextAttribute(h, 14);
		cout << "\t\t____________________________________________________________________________________\n";
		cout << "\n\t\t\t\t\t INVENTORY MANAGEMENT SYSTEM\n";
		cout << "\t\t\t\t\t        CUSTOMER MENU\n";
		cout << "\t\t____________________________________________________________________________________\n";
		cout << "\n\t\t 1 - Purchase Items.";
		cout << "\n\t\t 2 - Display Current Stock of Items.";
		cout << "\n\t\t 3 - Search for Items.";
		cout << "\n\t\t 4 - Exit(On Exit all the Changes will be saved and return to main menu).\n";
		cout << "\t\t____________________________________________________________________________________\n";
		SetConsoleTextAttribute(h, 15);
	}

	int getCustomerChoice()
	{
		int choice = -1;
		while (!((choice > 0) && (choice < 5)))
		{
			cout << "\n\t\tEnter your choice: ";
			cin >> choice;
			system("cls");
			if (!((choice > 0) && (choice < 5)))
			{
				cout << "\n\tPlease choose a valid number from the following options of menu.\n";
				displayCustomerMenu();
			}
			cin.clear();
			cin.ignore(1000, '\n');
		}
		return choice;
	}
	void customerAccess()
	{
		string itemName;
		string itemCode;
		long double itemPrice;
		int itemQuantity{};
		int CustomerQuantity = 0;
		//int size{};
		int count = 0;
		obj.loadStock();
		int customerChoice;
		do
		{
			displayCustomerMenu();
			customerChoice = getCustomerChoice();
			switch (customerChoice)
			{
			case 1:
			{
				int size;
				Item* tempItemStorage;
				bool status;
				obj.printStock();
				cout << "Enter amount of items you want to purchase : ";
				cin >> size;
				tempItemStorage = new Item[size];
				for (int i = 0; i < size; i++)
				{
					do
					{
						cout << "Enter Item Name : ";
						cin >> itemName;
						status = obj.CheckItemAvailabillity(itemName, itemCode, itemQuantity, itemPrice);
						if (status)
						{
							tempItemStorage[i].setItemName(itemName);
							tempItemStorage[i].setItemCode(itemCode);
							tempItemStorage[i].setPrice(itemPrice);
							count = 0;
							do
							{
								cout << "Keep in mind \n";
								cout << "Quantity of " << itemName << " available in stock is = " << itemQuantity << endl;
								cout << "How many " << itemName << " do you want to purchase ?";
								cin >> CustomerQuantity;
								if (count > 0)
								{
									cout << "\nWRONG QUANTITY\n";
								}
								++count;
							} while (CustomerQuantity > itemQuantity);
							tempItemStorage[i].setQuantity(CustomerQuantity);
							tempItemStorage[i].setTotalPrice();
						}
						obj.updateItem(CustomerQuantity, itemName);

					} while (status == false);
				}
				purchaseItem.setItemPurshased(tempItemStorage, size);
				cin.get();
				system("cls");
				purchaseItem.displayReceipt();
				//customerChoice = 4;
				/*cout << "Press Enter to continue...";
				cin.get();
				system("cls");*/
				break;
			}

			case 2:
			{
				obj.printStock();
				break;
			}

			case 3:
			{
				cout << "How many items do you want to search?" << endl;
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					string itemCode;
					cout << "Enter item code: ";
					cin >> itemCode;
					obj.searchItem(itemCode);
				}
				break;
			}

			case 4:
			{
				obj.saveStock();
				break;
			}


			}//switch
		} while (customerChoice != 4);
	}

};



int main()
{
	Stock stock;
	//stock.loadStock();
	int choice;
	string username, password;
	SetConsoleTextAttribute(h, 14);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t|============ WELCOME TO GARMENTS INVENTORY MANAGEMENT ============|";
	SetConsoleTextAttribute(h, 7);
	cin.get();
	system("cls");
	do
	{
		choice = whoIsUser();
		switch (choice)
		{
		case 1:
		{
			Admin admin;
			cout << "User Name : ";
			cin.ignore();
			getline(cin, username);
			//cout << "Now Enter Security Password if you are admin!!!";
			if (admin.check())
			{
				cout << "\n------------------------------------";
				cout << "\n         LOGIN SUCCESSFUL\n";
				cout << "------------------------------------\n";
				cout << "Press Enter to continue...";
				cin.ignore();
				system("cls");
				admin.adminAccess(stock);
			}
			else
			{
				system("cls");
				SetConsoleTextAttribute(h, 4);
				cout << "\n--------------------------------------------";
				cout << "\n   YOU HAVE ENTERED WRONG PASSWORD\n";
				cout << "WE CANNOT GIVE YOU ACCESS TO ADMIN PAGE\n";
				cout << "----------------------------------------------\n";
				SetConsoleTextAttribute(h, 15);
			}
			cout << "\nPress Enter to continue...";
			cin.ignore();
			cin.get();
			system("cls");
			break;
		}

		case 2:
		{
			Employee employee;
			cout << "User Name : ";
			cin.ignore();
			getline(cin, username);
			cout << "Now Enter Security Password if you are employee!!!";
			if (employee.check() == true)
			{
				cout << "\n------------------------------------\n";
				cout << "LOGIN SUCCESSFUL\n";
				cout << "------------------------------------\n";
				cout << "Press Enter to continue...";
				cin.ignore();
				system("cls");
				employee.employeeAccess();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\n------------------------------------";
				cout << "\nYOU HAVE ENTERED WRONG PASSWORD\n";
				cout << "------------------------------------\n";
				SetConsoleTextAttribute(h, 7);
			}
			cout << "\nPress Enter to continue...";
			//cin.ignore();
			cin.get();
			system("cls");
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
			SetConsoleTextAttribute(h, 14);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t|============ THANK YOU FOR USING THE INVENTORY MANGEMENT SYSTEM  ============|";
			SetConsoleTextAttribute(h, 7);
			cin.get();
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
	SetConsoleTextAttribute(h, 14);
	cout << "\n\t\t\t   INVENTORY MANAGEMENT SYSTEM\n";
	cout << "\t\t__________________________________________________\n";
	cout << "\t\t\t           MAIN MENU\n";
	cout << "\t\t__________________________________________________\n";
	cout << "\n\t\t 1 - Admin Menu";
	cout << "\n\t\t 2 - Employee Menu";
	cout << "\n\t\t 3 - Customer Menu";
	cout << "\n\t\t 4 - Exit(On Exit all changes will be saved.).\n";
	cout << "\t\t__________________________________________________\n";
	SetConsoleTextAttribute(h, 15);
}


int getChoice()
{
	int choice = -1;
	while (!((choice > 0) && (choice < 5)))
	{
		cout << "\n\tEnter your choice: ";
		cin >> choice;
		system("cls");
		if (!((choice > 0) && (choice < 5)))
		{
			cout << "\n\tPlease choose a valid number from the following options of menu.\n";
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



