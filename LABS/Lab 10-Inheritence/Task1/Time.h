#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time
{
	int hours, minutes, seconds;
public:
	Time(int h = 0, int m = 0, int s = 0)
	{
		hours = h;
		minutes = m;
		seconds = s;

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

		if (minutes >= 60)
		{
			hours += (minutes / 60);
			minutes = minutes % 60;
			if (hours >= 24)
			{
				hours = hours % 24;
			}
		}

		if (hours >= 24)
		{
			hours = hours % 24;
		}
	}
	int getHour() const
	{
		return hours;
	}
	int getMin() const
	{
		return minutes;
	}
	int getSec() const
	{
		return seconds;
	}
	void print() const
	{
		cout << hours << ":" << minutes << ":" << seconds;
	}
};

#endif