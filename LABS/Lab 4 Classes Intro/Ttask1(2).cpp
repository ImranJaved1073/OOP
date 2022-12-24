#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

class Employee
{
private:
	string name;
	int idNumber;
	string department;
	string position;

public:
	Employee();
	Employee(string empName, int empId, string empDep, string empPos);
	Employee(string empName, int empId);

	void setEmployeName(string);
	void setEmployeDepartment(string);
	void setEmployePosition(string);
	void setEmployeID(int);

	string getEmployeName() const;
	string getEmployeDepartment() const;
	string getEmployePosition() const;
	int getEmployeID() const;
	void displayEmployee() const;

};

Employee::Employee()
{
	name = "";
	department = "";
	position = "";
	idNumber = 0;
}
Employee::Employee(string empName, int empId, string empDep, string empPos)
{
	name = empName;
	department = empDep;
	position = empPos;
	idNumber = empId;
}
Employee::Employee(string empName, int empId)
{
	name = empName;
	department = "";
	position = "";
	idNumber = empId;
}

void Employee::setEmployeName(string n)
{
	name = n;
}

void Employee::setEmployeDepartment(string d)
{
	department = d;
}

void Employee::setEmployePosition(string p)
{
	position = p;
}

void Employee::setEmployeID(int id)
{
	idNumber = id;
}


string Employee::getEmployeName() const
{
	return name;
}

string Employee::getEmployeDepartment() const
{
	return department;
}

string Employee::getEmployePosition() const
{
	return position;
}

int Employee::getEmployeID() const
{
	return idNumber;
}

void Employee::displayEmployee() const
{
	cout << getEmployeName() << "			" 
		<< getEmployeID() << "			" 
		<< getEmployePosition() << "			" 
		<< getEmployeDepartment() << endl;
}

int main()
{
	string input; int id;
	Employee e1;
	Employee e2("imran", 33);
	Employee e3("imran", 33, "SE", "CEO");
	e1.displayEmployee();
	e2.displayEmployee();
	e3.displayEmployee();
	Employee emp[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter name of Employee # " << i + 1 << ": ";
		getline(cin, input);
		emp[i].setEmployeName(input);
		cout << "Enter ID of Employee # " << i + 1 << ": ";
		cin >> id;
		emp[i].setEmployeID(id);
		cout << "Enter Department of Employee # " << i + 1 << ": ";
		cin.ignore();
		getline(cin, input);
		emp[i].setEmployeDepartment(input);
		cout << "Enter job title of Employee # " << i + 1 << ": ";
		getline(cin, input);
		emp[i].setEmployePosition(input);
	}
	cout << "_______________________________________________________________________________________\n";
	cout << setw(20) << "Name " << setw(20) << "ID Number "
		<< setw(20) << "Department " << setw(20) << "Position " << endl;
	cout << "_______________________________________________________________________________________\n";

	for (int i = 0; i < 2; i++)
	{
		cout << setw(20);
		cout << emp[i].getEmployeName();
		cout << setw(20);
		cout << emp[i].getEmployeID();
		cout << setw(20);
		cout << emp[i].getEmployeDepartment();
		cout << setw(20);
		cout << emp[i].getEmployePosition();
		cout << setw(20);
		cout << endl;
	}

	return 0;
}