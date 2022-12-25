#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include <iostream>
#include "Employee.h"

using namespace std;
class HourlyEmployee : public Employee
{
	double wage;
	double hours;

public:
	HourlyEmployee(string fName = "Imran", string lName = "Javed", string ssn = "123", double wages = 0.0, double hour = 0.0) :Employee(fName, lName, ssn)
	{
		wage = wages;
		hours = hour;
	}
	void setWages(double w)
	{
		wage = w;
	}
	void setHours(double h)
	{
		hours = h;
	}
	double getWages() const
	{
		return wage;
	}
	double getHours() const
	{
		return hours;
	}
	double earnings()
	{

		return wage * hours;
	}
	void print()
	{
		Employee::print();
		cout << "Wages: " << wage << endl;
		cout << "Hours: " << hours << endl;
	}
};

#endif // !EMPLOYEE_H
