#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include "User.h"
#include "Stock.h"
#include "Purchase.h"
#include <windows.h>

using namespace std;

class Customer : public User
{
private:
	string id;
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
	
	void setID(string id)
	{
		this->id = id;
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


#endif // !CUSTOMER_H
