#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User
{
private:
	string name;
	string userid;
	string contact;
public:

	User()
	{
		name = " ";
		userid = " ";
		contact = " ";
	}
	void setUser(string n, string id, string p)
	{
		name = n;
		userid = id;
		contact = p;
	}
	void print()
	{
		cout << "Name : " << name << endl;
		cout << "User Id : " << userid << endl;
		cout << "Phone Number : " << contact << endl;
	}
	string getName()
	{
		return name;
	}
	string getPhone()
	{
		return contact;
	}
	string getUserid()
	{
		return userid;
	}                                                     												

};


#endif // !USER_H

