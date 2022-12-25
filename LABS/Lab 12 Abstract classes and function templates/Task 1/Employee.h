#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;
class Employee
{
	string firstName;
	string lastName;
	string SSN;
	
public:
	Employee()
	{
		firstName = "";
		lastName = "";
		SSN = "";
	}
	Employee(string fName, string lName, string ssn)
	{
		firstName = fName;
		lastName = lName;
		SSN = ssn;
	}
	void setFirstName(string fname)
	{
		firstName = fname;
	}
	void setLastName(string lName)
	{
		lastName = lName;
	}
	void setSSN(string ssn)
	{
		SSN = ssn;
	}
	string getFirstName() const
	{
		return firstName;
	}
	string getLastName() const
	{
		return lastName;
	}
	string getSSN() const
	{
		return SSN;
	}
	virtual double earnings() = 0;
	virtual void print()
	{
		cout << "Name: " << firstName << " " << lastName << endl;
		cout << "SSN: " << SSN << endl;
	}
};

#endif // !EMPLOYEE_H
