#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include "Stock.h"
#include "Item.h"
//#include <iostream>
//#include <fstream>
//#include <conio.h>
#include <string>
//#include <Windows.h>

using namespace std;
//HANDLE a = GetStdHandle(STD_OUTPUT_HANDLE);

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


#endif // !ADMIN_H
