#ifndef COMMISSIONPLOYEE_H
#define COMMISSIONPLOYEE_H

#include <string>
#include <iostream>
#include "Employee.h"

using namespace std;
class CommissionEmployee : public Employee
{
	double grossSales;
	double commisionRate;

public:
	CommissionEmployee(string fName = "Imran", string lName = "Javed", string ssn = "123", double grosssales = 0.0, double commisionrate = 0.0)
		:Employee(fName, lName, ssn)
	{
		grossSales = grosssales;
		commisionRate = commisionrate;
	}
	void setGrossSales(double g)
	{
		grossSales = g;
	}
	void setCommisionRate(double c)
	{
		commisionRate = c;
	}
	double getGrossSales() const
	{
		return grossSales;
	}
	double getCommisionRate() const
	{
		return commisionRate;
	}
	double earnings()
	{
		return grossSales * commisionRate;
	}
	void print()
	{
		Employee::print();
		cout << "Gross Sales: " << grossSales << endl;
		cout << "Commision Rate: " << commisionRate << endl;
	}
};

#endif // !EMPLOYEE_H
