#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include "Stock.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Employee :public User
{
private:
	string password;
	Stock object;
public:
	Employee()
	{
		password = "";
	}
	bool check()
	{
		bool status;
		string password,line;
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
			fout << line << "\n";
			fout << password;
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
		cout << "\n\t\t 4 - Change Password.";
		cout << "\n\t\t 5 - Exit(On Exit all the Changes will be saved and return to main menu).\n";
		cout << "\t\t____________________________________________________________________________________\n";
		SetConsoleTextAttribute(h, 15);
	}

	int getEmployeeChoice()
	{
		int choice = -1;
		cout << "\n\t\t Enter your choice: ";
		while (!((choice > 0) && (choice < 6)))
		{
			cout << "\n\tEnter your choice: ";
			cin >> choice;
			system("cls");
			if (!((choice > 0) && (choice < 6)))
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
		object.loadStock();
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
					index = object.updateItem(itemCode, quantity);
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
				object.printStock();
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
					index = object.searchItem(itemCode);
					if (index == -1)
						cout << "Item not found" << endl
						<< "Tell the Admin that item is not in the stock whick you are searching" << endl
						<< "so that he can add the item in the stock " << endl;
					else
					{
						cout << "Item #" << index + 1 << endl;
						cout << "Item name: " << object.getItem(index).getItemName() << endl;
						cout << "Item code: " << object.getItem(index).getItemCode() << endl;
						cout << "Item quantity: " << object.getItem(index).getQuantity() << endl;
						cout << "Item price: " << object.getItem(index).getPrice() << endl;
						cout << "Item total price: " << object.getItem(index).getTotalPrice() << endl;
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
				changePasswordEmployee();
				cout << "Press Enter to continue...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			}
			
			case 5:
			{
				object.saveStock();
				break;
			}

			default:
				cout << "Invalid choice" << endl;
				break;

			}
		} while (employeeChoice != 5);

	}


};


#endif // !ADMIN_H
