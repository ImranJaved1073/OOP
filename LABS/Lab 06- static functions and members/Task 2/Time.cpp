#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
	//cout << "Default constructor.\n";
	hours = 0;
	minutes = 0;
	seconds = 0;

}

Time::Time(int h, int m, int s)
{
	//cout << "Parameterized constructor.\n";
	hours = h;
	minutes = m;
	seconds = s;
}

Time::~Time()
{
	//cout << "Destructor.\n";
}

void Time::setHours(int hours)
{
	this->hours = hours;
}

void Time::setMinutes(int minutes)
{
	this->minutes = minutes;
}

void Time::setSeconds(int seconds)
{
	this->seconds = seconds;
}

int Time::getHours() const
{
	return hours;
}

int Time::getMinutes() const
{
	return minutes;
}

int Time::getSeconds() const
{
	return seconds;
}

void Time::advance(int h, int m, int s)
{
	seconds += s;
	if (seconds >= 60)
	{
		minutes += (seconds / 60);
		seconds = seconds % 60;
		if (minutes >= 60)
		{
			hours += (minutes / 60);
			minutes = minutes % 60;
			if (hours >= 24)
			{
				hours = hours % 24;
			}
		}
	}
	minutes += m;
	if (minutes >= 60)
	{
		hours += (minutes / 60);
		minutes = minutes % 60;
		if (hours >= 24)
		{
			hours = hours % 24;
		}
	}
	hours += h;
	if (hours >= 24)
	{
		hours = hours % 24;
	}
}

void Time::reset(int h, int m, int s)
{
	hours = h;
	minutes = m;
	seconds = s;
}

void Time::print()
{
	cout << hours << ":" << minutes << ":" << seconds << endl;
}

Time::Time(const Time& t)
{
	//cout << "Copy constructor.\n";
	hours = t.hours;
	minutes = t.minutes;
	seconds = t.seconds;
}

