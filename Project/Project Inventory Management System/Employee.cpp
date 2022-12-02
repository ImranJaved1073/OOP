//#include "User.h"
//#include "Stock.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include "Employee.h"

using namespace std;


HANDLE e = GetStdHandle(STD_OUTPUT_HANDLE);

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
	else
		cout << "\n\n\t \u001b[31mFile not found!! \u001b[0m" << endl;
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
			SetConsoleTextAttribute(e, 4);
			cout << "\n\n\t\tWRONG PASSWORD!!" << endl;
			SetConsoleTextAttribute(e, 15);
			cout << "\n\n\t\tYou have ";
			SetConsoleTextAttribute(e, 10);
			cout << count - 1;
			SetConsoleTextAttribute(e, 15);
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
	else
		cout << "\n\n\t \u001b[31mFile not found!! \u001b[0m" << endl;
	fin.close();

	string password, confirm;

	cout << "\n\n\n\t\tEnter new password: ";
	getline(cin, password);

	cout << "\n\t\tConfirm Password: ";
	getline(cin, confirm);

	while (password != confirm)
	{
		SetConsoleTextAttribute(e, 4);
		cout << "\n\t\tPasswords do not match. Please try again!" << endl;
		SetConsoleTextAttribute(e, 15);
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
	SetConsoleTextAttribute(e, 14);
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
	SetConsoleTextAttribute(e, 15);
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
					cout << "\n\n\n\t\tEnter item code: ";
					getline(cin, itemCode);

					index = object.updateItem(itemCode);
					if (index == -1)
						cout << "\u001b[31m\n\n\t\tItem not found!!\u001b[0m" << endl
						<< "\n\n\t\tKindly Inform the Admin that item is not in the stock" << endl
						<< "\t\tand also tell the Admin to add the item in the stock with this code." << endl;

					pauseAndClear();
					cout << "\n\n\t\tDo you want to update another item from stock? (press y for yes and any other key for no): ";
					/*cin.clear();
					cin.ignore(1000, '\n');*/
					cin >> choice;
					cin.ignore();
				}
				pauseAndClear();
				cin.clear();
				cin.ignore(1000, '\n');
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
						cout << "\u001b[31m\n\n\t\tItem not found!!\u001b[0m" << endl
						<< "\n\n\t\tKindly inform the Admin that item is not in the stock whick you are searching" << endl
						<< "\t\tso that he can add the item in the stock " << endl;
					else
					{
						cout << "\n\n\n\tItem name: " << object.getItem(index).getItemName() << endl;
						cout << "\tItem code: " << object.getItem(index).getItemCode() << endl;
						cout << "\tItem quantity: " << object.getItem(index).getQuantity() << endl;
						cout << "\tItem price: " << object.getItem(index).getPrice() << endl;
						cout << "\tItem total price: " << object.getItem(index).getTotalPrice() << endl;
					}
					pauseAndClear();
					cout << "\n\n\tDo you want to search another item? (press y for yes and any other key for no): ";
					cin >> choice;
					cin.ignore();
				}
				pauseAndClear();
				cin.clear();
				cin.ignore(1000, '\n');
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

