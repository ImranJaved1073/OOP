#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include "Date.h"
#include "Time.h"
using namespace std;

class DateTime :public Date, public Time
{
public:
	DateTime(int d, int m, int y, int h, int mi, int s) :Date(d, m, y), Time(h, mi, s)
	{
	}
	void printDateTime()
	{
		Date::print();
		cout << " ";
		Time::print();
	}
	void showFormattedDateTime()
	{
		cout << monthName(getMonth()) << " " << getDay() << ", " << getYear();
		cout << " ";
		Time::print();
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

};


#endif // !DATETIME_H

