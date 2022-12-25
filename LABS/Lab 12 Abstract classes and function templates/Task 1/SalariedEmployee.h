#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include <iostream>
#include "Employee.h"

using namespace std;
class SalariedEmployee : public Employee
{
	double weeklySalary;
	
public:
	SalariedEmployee(string fName = "Imran", string lName = "Javed", string ssn = "123", double salary = 0.0) :Employee(fName, lName, ssn)
	{
		weeklySalary = salary;
	}
	void setWeeklySalary(double salary)
	{
		weeklySalary = salary;
	}
	double getWeeklySalary() const
	{
		return weeklySalary;
	}
	double earnings()
	{
		return weeklySalary;
	}
	void print()
	{
		Employee::print();
		cout << "Weekly Salary: " << weeklySalary << endl;
	}
};

#endif // !EMPLOYEE_H
