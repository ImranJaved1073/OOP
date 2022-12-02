#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"
#include "Stock.h"
#include <iostream>
#include <string>
#include <fstream>
//#include <conio.h>
//#include <windows.h>

using namespace std;
//HANDLE e = GetStdHandle(STD_OUTPUT_HANDLE);

class Employee :public User
{
private:
	string password;
	Stock object;
public:
	Employee();
	bool check();

	void changePasswordEmployee();
	void displayEmployeeMenu();
	int getEmployeeChoice();
	void employeeAccess();
	void pauseAndClear();

};


#endif // !ADMIN_H
