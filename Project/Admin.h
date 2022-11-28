#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Stock.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

class Admin :public User
{
private:
	string username;
	string password;
	Stock stock;
public:
	Admin()
	{
		username = "admin";
		password = "admin";
	}
	bool check()
	{
		int count = 3;
		string password;
		string line;
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
			fout << password << "\n";
			fout << empPassword;
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
		cout << "\n\t\t 6 - Change Password.";
		cout << "\n\t\t 7 - Exit(On Exit all the Changes will be saved and return to main menu).\n";
		cout << "\t\t____________________________________________________________________________________\n";
		SetConsoleTextAttribute(h, 15);
	}

	int getAdminChoice()
	{
		int choice = -1;
		while (!((choice > 0) && (choice < 9)))
		{
			cout << "\n\n\tEnter your choice: ";
			cin >> choice;
			system("cls");
			if (!((choice > 0) && (choice < 9)))
			{
				cout << "\n\tPlease choose a valid number from the following options of menu.\n";
				displayAdminMenu();
			}
			cin.clear();
			cin.ignore(1000, '\n');
		}
		return choice;
	}

	void adminAccess()
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
				changePassword();
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			
			case 7:
			{
				stock.saveStock();
				break;
			}

			default:
				cout << "Invalid choice" << endl;
				break;
			}

		} while (adminChoice != 7);
	}

};


#endif // !ADMIN_H
