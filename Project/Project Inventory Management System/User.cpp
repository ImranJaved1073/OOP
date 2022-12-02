#include <string>
#include <iostream>
#include "User.h"

using namespace std;

User::User()
{
	name = " ";
	userid = " ";
	contact = " ";
}

void User::setUser(string n, string id, string p)
{
	name = n;
	userid = id;
	contact = p;
}

void User::print()
{
	cout << "Name : " << name << endl;
	cout << "User Id : " << userid << endl;
	cout << "Phone Number : " << contact << endl;
}

string User::getName()
{
	return name;
}

string User::getPhone()
{
	return contact;
}

string User::getUserid()
{
	return userid;
}