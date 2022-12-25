#include <string>
#include <iostream>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "BasePlusCommisionEmployee.h"

using namespace std;

int main()
{
	/*HourlyEmployee e1("Imran", "Javed", "123", 10, 10);
	SalariedEmployee e2("Imran", "Javed", "122", 1000);
	CommissionEmployee e3("Imran", "Javed", "121", 1000, 0.1);
	BasePlusCommissionEmployee e4("Imran", "Javed", "123", 1000);

	e1.print();
	e2.print();
	e3.print();
	e4.print();*/
	
	cout << "What type of employee you want to create?" << endl;
	cout << "1. Hourly Employee" << endl;
	cout << "2. Salaried Employee " << endl;
	cout << "3. Commission Employee " << endl;
	cout << "4. Base Plus Commission Employee " << endl;
	cout << "Enter your choice: ";
	int choice = -1;
	while (choice < 1 || choice > 4)
	{
		cin >> choice;
		if (choice < 1 || choice > 4)
		{
			cout << "Invalid choice. Please enter again: ";
		}
		cin.clear();
		cin.ignore(1000, '\n');
	}
	Employee** employees = new Employee * [4];
	if (choice == 1)
	{
		string lName,ssn,fName;
		double wage,hours;
		cout << "Enter first name: ";
		cin.ignore();
		getline(cin, fName);
		cout << "Enter last name: ";
		getline(cin, lName);
		cout << "Enter SSN: ";
		getline(cin, ssn);
		cout << "Enter hourly wage: ";
		cin >> wage;
		cout << "Enter hours: ";
		cin >> hours;
		employees[0] = new HourlyEmployee(fName, lName, ssn, wage, hours);
		employees[0]->print();
		cout << "Earnings: " << employees[0]->earnings() << endl;
	}
	else if (choice == 2)
	{
		string lName, ssn, fName;
		double salary;
		cout << "Enter first name: ";
		cin.ignore();
		getline(cin, fName);
		cout << "Enter last name: ";
		getline(cin, lName);
		cout << "Enter SSN: ";
		getline(cin, ssn);
		cout << "Enter salary: ";
		cin >> salary;
		employees[1] = new SalariedEmployee(fName, lName, ssn, salary);
		employees[1]->print();
		cout << "Earnings: " << employees[1]->earnings() << endl;
	}
	else if (choice == 3)
	{
		string lName, ssn, fName;
		double salary, commission;
		cout << "Enter first name: ";
		cin.ignore();
		getline(cin, fName);
		cout << "Enter last name: ";
		getline(cin, lName);
		cout << "Enter SSN: ";
		getline(cin, ssn);
		cout << "Enter salary: ";
		cin >> salary;
		cout << "Enter commission: ";
		cin >> commission;
		employees[2] = new CommissionEmployee(fName, lName, ssn, salary, commission);
		employees[2]->print();
		cout << "Earnings: " << employees[2]->earnings() << endl;
	}
	else if (choice == 4)
	{
		string lName, ssn, fName;
		double salary, commission, baseSalary;
		cout << "Enter first name: ";
		cin.ignore();
		getline(cin, fName);
		cout << "Enter last name: ";
		getline(cin, lName);
		cout << "Enter SSN: ";
		getline(cin, ssn);
		cout << "Enter salary: ";
		cin >> salary;
		cout << "Enter commission: ";
		cin >> commission;
		cout << "Enter base salary: ";
		cin >> baseSalary;
		employees[3] = new BasePlusCommissionEmployee(fName, lName, ssn, salary, commission, baseSalary);
		employees[3]->print();
		cout << "Earnings: " << employees[3]->earnings() << endl;
	}

	return 0;
}