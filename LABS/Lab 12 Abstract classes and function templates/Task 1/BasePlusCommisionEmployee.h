#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include <string>
#include <iostream>
#include "Employee.h"
#include "CommisionEmployee.h"

using namespace std;

class BasePlusCommissionEmployee : public CommissionEmployee
{
	double baseSalary;

public:
	BasePlusCommissionEmployee(string fName = "Imran", string lName = "Javed", string ssn = "123", double grosssales = 0.0, double commisionrate = 0.0, double salary = 0.0)
		:CommissionEmployee(fName, lName, ssn, grosssales, commisionrate)
	{
		baseSalary = salary;
	}
	void setBaseSalary(double salary)
	{
		baseSalary = salary;
	}
	double getBaseSalary() const
	{
		return baseSalary;
	}
	double earnings()
	{
		return baseSalary + CommissionEmployee::earnings();
	}
	void print()
	{
		//CommissionEmployee::print;
		cout << "Base Salary: " << baseSalary << endl;
	}
};

#endif // !EMPLOYEE_H
