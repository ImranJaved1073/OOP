#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int month, day, year;

public:
	Date();
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	void displayDate1();
	void displayDate2();
	void displayDate3();
};

string monthName(int month);
Date::Date()
{
	cout << "Default constructor called.\n";
	month = 0; day = 0; year = 0;
}

void Date::setMonth(int m)
{	
	month=m;
}
void Date::setDay(int d)
{
	day=d;
}
void Date::setYear(int y)
{
	year=y;
}

int Date::getMonth() const
{
	return month;
}
int Date::getDay() const
{
	return day;
}
int Date::getYear() const
{
	return year;
}


void Date::displayDate1()
{
	cout << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}

void Date::displayDate2()
{
	cout << monthName(getMonth()) << " " << getDay() << "," << getYear() << endl;
}

void Date::displayDate3()
{
	cout << getDay() << " " << monthName(getMonth()) << " " << getYear() << endl;
}

string monthName(int month)
{
	string m;

	switch (month)
	{
	case 1: m = "January";
		break;
	case 2: m = "February";
		break;
	case 3: m = "March";
		break;
	case 4: m = "April";
		break;
	case 5: m = "May";
		break;
	case 6: m = "June";
		break;
	case 7: m = "July";
		break;
	case 8: m = "August";
		break;
	case 9: m = "September";
		break;
	case 10: m = "October";
		break;
	case 11: m = "November";
		break;
	case 12: m = "December";
		break;
	}
	return m;
}


int main()
{
	Date date; int input;
	date.displayDate1();
	int choice;
	cout << "Choose a number from the menu so that how your time will be displayed.\n";
	cout << " 1. 12/25/2012\n";
	cout << " 2. December 25, 2012\n";
	cout << " 3. 25 December 2012\n";
	cin >> choice;
	while (choice < 1 || choice>3)
	{
		cout << "INVALID CHOICE!Enter choice again:";
		cin >> choice;
	}
	cout << "Enter month: ";
	cin >> input;
	while (input < 1 || input>12)
	{
		cout << "INVALID!Month cannot be greater than 12 or less than 1.\n";
		cout << "Enter again:";
		cin >> input;
	}
	date.setMonth(input);
	cout << "Enter day: ";
	cin >> input;
	while (input < 1 || input>31)
	{
		cout << "INVALID!Day cannot be greater than 31 or less than 1.\n";
		cout << "Enter again:";
		cin >> input;
	}
	date.setDay(input);
	cout << "Enter Year : ";
	cin >> input;
	date.setYear(input);

	if (choice == 1)
		date.displayDate1();

	else if (choice == 2)
		date.displayDate2();

	else if (choice == 3)
		date.displayDate3();

	return 0;
}