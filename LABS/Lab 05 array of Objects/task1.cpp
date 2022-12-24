#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

int main()
{
	Employee defaultEmployee;
	int employId, hourPayRate, noOfHoursWorked;
	string employName, designation;
	
	cout << "___________________________________________________________________________________________________________________\n";
	cout << setw(20) << "ID" << setw(20) << "NAME" << setw(20) << "DESIGNATION"
		<< setw(20) << "WEEKLY SALARY" << setw(20) << "OVERTIME\n";
	cout << "___________________________________________________________________________________________________________________\n";
	cout << setw(20) << defaultEmployee.getId() << setw(20) << defaultEmployee.getName() << setw(20) << defaultEmployee.getDesignation();
	cout << setw(20) << defaultEmployee.calculateWeeklySalary();
	cout << setw(20) << defaultEmployee.calculateOverTime() << endl;

	Employee ParaEmployee(1, "Ahmad", "Cheif", 100, 52);
	cout << setw(20) << ParaEmployee.getId() << setw(20) << ParaEmployee.getName() << setw(20) << ParaEmployee.getDesignation();
	cout << setw(20) << ParaEmployee.calculateWeeklySalary();
	cout << setw(20) << ParaEmployee.calculateOverTime() << endl;

	Employee emp[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter ID of Employee#  " << i + 1 << " : ";
		cin >> employId;
		emp[i].setId(employId);
		cout << "Enter Name of Employee#  " << i + 1 << " : ";
		cin.ignore();
		getline(cin,employName);
		emp[i].setName(employName);
		cout << "Enter Designation of Employee#  " << i + 1 << " : ";
		getline(cin, designation); 
		emp[i].setDesignation(designation);
		cout << "Enter hourly pay rate of Employee#  " << i + 1 << " : ";
		cin >> hourPayRate;
		emp[i].setHourlyPayRate(hourPayRate);
		cout << "Enter number of hours worked for Employee#  " << i + 1 << " : ";
		cin >> noOfHoursWorked;
		emp[i].setNumberOfHoursWorked(noOfHoursWorked);
		
	}
	cout << "___________________________________________________________________________________________________________________\n";
	cout << setw(20) << "ID" << setw(20) << "NAME" << setw(20) << "DESIGNATION"
		<< setw(20) << "WEEKLY SALARY" << setw(20) << "OVERTIME\n";
	cout << "___________________________________________________________________________________________________________________\n";
	for (int i = 0; i < 2; i++)
	{
		cout << setw(20) << emp[i].getId() << setw(20) << emp[i].getName() << setw(20) << emp[i].getDesignation();
		cout << setw(20) << emp[i].calculateWeeklySalary();
		cout << setw(20) << emp[i].calculateOverTime() << endl;
	}
}