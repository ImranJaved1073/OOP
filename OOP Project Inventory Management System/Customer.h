#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include "User.h"
#include "Stock.h"
#include "Purchase.h"
//#include <windows.h>

using namespace std;
//HANDLE c = GetStdHandle(STD_OUTPUT_HANDLE);

class Customer : public User
{
private:
	string address;
	string email;
	string CNIC;
	Stock obj;
	Purchase purchaseItem;
public:
	Customer();
	void setCustomer(string, string, string, string, string, string);

	void print();
	string getAddress();
	string getEmail();
	string getCNIC();

	void displayCustomerMenu();

	int getCustomerChoice();

	void gotoXY(int, int);

	void saveReceipt();
	void customerAccess();
	void pauseAndClear();
};


#endif // !CUSTOMER_H
