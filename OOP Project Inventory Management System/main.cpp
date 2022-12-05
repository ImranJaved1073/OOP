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

void displayIntro();
void displayExit();
void displayMainMenu();

int getChoice();
int whoIsUser();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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