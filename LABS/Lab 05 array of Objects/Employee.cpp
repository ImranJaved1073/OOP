#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

// Default
Employee::Employee() :WEEKLY_WORKING_HOURS(40)
{
	cout << "Default constructor called.\n";
	employeeId = 0;
	employeeName = "";
	employeeDesignation = "";
	hourlyPayRate = 0;
	numberOfHoursWorked = 0;
}

// Parameterized
Employee::Employee(int id, string name, string designation, int hPR, int hW) :WEEKLY_WORKING_HOURS(40)
{
	cout << "Parameterized constructor called.\n";
	employeeId = id;
	employeeName = name;
	employeeDesignation = designation;
	hourlyPayRate = hPR;
	numberOfHoursWorked = hW;
}

void Employee::setId(int id)
{
	employeeId = id;
}

void Employee::setName(string name)
{
	employeeName = name;
}

void Employee::setDesignation(string designation)
{
	employeeDesignation = designation;
}

void Employee::setHourlyPayRate(int hPR)
{
	hourlyPayRate = hPR;
}

void Employee::setNumberOfHoursWorked(int hW)
{
	numberOfHoursWorked = hW;
}

int Employee::calculateMonthlySalary()
{
	return 4 * ((hourlyPayRate * (numberOfHoursWorked - (numberOfHoursWorked - WEEKLY_WORKING_HOURS))) + calculateOverTime());
}

int Employee::calculateWeeklySalary()
{
	return (hourlyPayRate * (numberOfHoursWorked - (numberOfHoursWorked - WEEKLY_WORKING_HOURS))) + calculateOverTime();
}

int Employee::calculateOverTime()
{
	return (numberOfHoursWorked - WEEKLY_WORKING_HOURS) * (1.5 * hourlyPayRate);
}

int Employee::getId() const
{
	return employeeId;
}

string Employee::getName() const
{
	return employeeName;
}

string Employee::getDesignation() const
{
	return employeeDesignation;
}

Employee::~Employee()
{
	cout << "Destructor Called.\n";
}