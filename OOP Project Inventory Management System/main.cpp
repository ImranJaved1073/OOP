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

void displayIntro(string);
void displayMainMenu();

int getChoice();
int whoIsUser();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	displayIntro("WELCOME TO INVENTORY MANAGEMENT");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	Stock stock;
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

				cout << "\n\n\t";
				system("pause");
				system("cls");
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
			}
			cout << "\n\n\t";
			system("pause");
			system("cls");
			break;
		}

		case 2:
		{
			Employee employee;
			cout << "\n\n\n\t\tUser Name : ";
			cin.ignore();
			getline(cin, username);
			//cout << "Now Enter Security Password if you are employee!!!";
			/*if (employee.check() == true)
			{*/
				cout << "\n\n\t------------------------------------\n";
				SetConsoleTextAttribute(h, 10);
				cout << "\n\t         LOGIN SUCCESSFUL\n";
				SetConsoleTextAttribute(h, 15);
				cout << "\n\t------------------------------------\n";
				cout << "\n\n\t";
				system("pause");
				system("cls");
				employee.employeeAccess();
			//}
			/*else
			{*/

				cout << "\n\n\t------------------------------------";
				SetConsoleTextAttribute(h, 4);
				cout << "\n\tYOU HAVE ENTERED THE WRONG PASSWORD\n";
				SetConsoleTextAttribute(h, 15);
				cout << "\n\n\t------------------------------------\n";

			//}
			cout << "\n\n\t";
			system("pause");
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
			displayIntro("THANK YOU FOR USING THE INVENTORY MANGEMENT");
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

// ye part urana hai
void displayIntro(string s)
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	static CONSOLE_FONT_INFOEX  fontex;

	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(h, 0, &fontex);

	fontex.FontWeight = 800;

	fontex.dwFontSize.X = 18;
	fontex.dwFontSize.Y = 18;

	SetCurrentConsoleFontEx(h, NULL, &fontex);

	cout << "\n\n\n\n\n\n\n";

	for (int i = 0; i < 42; i++)
	{
		cout << " ";
	}

	for (int i = 0; i < 84; i++)
	{
		cout << "\u001b[34;1m" << "*" << "\u001b[0m";
	}

	cout << endl;

	for (int j = 0; j < 16; j++)
	{
		for (int i = 0; i < 42; i++)
		{
			cout << " ";
		}

		for (int i = 0; i < 63; i++)
		{
			if (i == 0)
			{
				cout << "\u001b[34;1m" << "*" << "\u001b[0m";
			}

			else if (i > 0 && i <= 21)
			{
				cout << " ";
			}

			else if (i == 22)
			{
				if (j == 7)
				{
					cout << "\u001b[33;1m" << s;

					for (int i = 0; i < 21; i++)
					{
						cout << " ";
					}

					cout << "\u001b[34;1m" << "*" << "\u001b[0m" << endl;
					break;
				}

				else
				{
					for (int i = 0; i < 22; i++)
					{
						cout << " ";
					}
				}
			}

			else if (i > 22 && i < 62)
			{
				cout << " ";
			}

			else
			{
				cout << "\u001b[34;1m" << "*" << "\u001b[0m" << endl;
			}
		}
	}

	for (int i = 0; i < 42; i++)
	{
		cout << " ";
	}

	for (int i = 0; i < 84; i++)
	{
		cout << "\u001b[34;1m" << "*" << "\u001b[0m";
	}
	cout << "\n\n";
	cin.get();
	system("cls");
}