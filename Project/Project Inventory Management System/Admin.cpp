
#include "Admin.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

void pauseAndClear()
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
	string password,line;
	bool flag = true;
	
	ifstream fin;
	fin.open("password.txt");
	if (fin)
	{
		getline(fin, line);
		password = line;
	}
	
	else
		cout << "\n\n\t \u001b[31mFile not found!! \u001b[0m" << endl;
	fin.close();

	while (count!=0 && flag)
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
	else
		cout << "\n\n\t \u001b[31mFile not found!! \u001b[0m" << endl;
	fin.close();


	string password,confirm;
	cout << "\n\n\n\t\tEnter new password: ";
	//cin.ignore();
	getline(cin, password);
	cout << "\n\t\tConfirm New Password: ";
	getline(cin, confirm);
	while (password != confirm)
	{
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
						cout << "\u001b[31m\n\n\t\tQuantity of " << itemName << " must be greater than 0. Please try again.\u001b[0m" << endl;
						cout << "\n\t\tEnter quantity of\u001b[33m " << itemName << "\u001b[0m :";
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
						cout << "\u001b[31m\n\n\t\tPrice of " << itemName << " must be more than 0. Please try again.\u001b[0m" << endl;
						cout << "\n\t\tEnter price of\u001b[33m " << itemName << "\u001b[0m :";
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

			pauseAndClear();
			cin.clear();
			cin.ignore(1000, '\n');
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
					cout << "\n\t\tEnter item code: ";
					getline(cin, itemCode);

					index = stock.updateItem(itemCode);

					if (index == -1)
					{
						cout << "\u001b[31m\n\n\n\t\tThere is no Item with this Item Code.Add it to Stock.\u001b[0m\n";
					}
					pauseAndClear();
					cout << "\n\n\n\t\tDo you want to update another item to stock? (press y for yes and any other key for no): ";
					cin >> choice;
				}
				pauseAndClear();
				cin.clear();
				cin.ignore(1000, '\n');
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
						cout << "\n\n\n\tItem name: " << stock.getItem(index).getItemName() << endl;
						cout << "\tItem code: " << stock.getItem(index).getItemCode() << endl;
						cout << "\tItem quantity: " << stock.getItem(index).getQuantity() << endl;
						cout << "\tItem price: " << stock.getItem(index).getPrice() << endl;
						cout << "\tTotal price: " << stock.getItem(index).getTotalPrice() << endl;
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
		}//end of case 4


		case 5://search
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
					if (stock.getSize() != 0)
					{
						count++;
						string itemCode;
						cout << "\n\n\tEnter item code: ";
						getline(cin, itemCode);
						stock.removeItem(itemCode);
						cout << "\n\n\t\u001b[32mStock of Item removed successfully.\u001b[0m" << endl;
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
					cin.ignore();
				}
				cout << "\n\n\t\t\u001b[32m" << count << " item(s) removed successfully.\u001b[0m" << endl;

				pauseAndClear();
				cin.clear();
				cin.ignore(1000, '\n');
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