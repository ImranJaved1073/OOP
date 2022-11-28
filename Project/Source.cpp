#include <iostream>
#include <string>
#include "Stock.h"
#include "Item.h"
#include <fstream>
#include <Windows.h>
#include "User.h"
#include "Admin.h"
#include "Employee.h"
#include "Customer.h"

using namespace std;

void displayMainMenu();

int getChoice();
int whoIsUser();


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
				admin.adminAccess();
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
			//cout << "Now Enter Security Password if you are employee!!!";
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

