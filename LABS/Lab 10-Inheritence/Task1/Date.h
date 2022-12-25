#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
	int day, month, year;
public:
	Date(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
		if (day < 1 || day > 31)
		{
			cout << "Invalid day" << endl;
			exit(1);
		}
		if (month < 1 || month > 12)
		{
			cout << "Invalid month" << endl;
			exit(1);
		}
		if (year < 1900 || year > 2100)
		{
			cout << "Invalid year" << endl;
			exit(1);
		}
	}
	int getDay() const
	{
		return day;
	}
	int getMonth() const
	{
		return month;
	}
	int getYear() const
	{
		return year;
	}
	void print() const
	{
		cout << day << "/" << month << "/" << year;
	}
};

#endif