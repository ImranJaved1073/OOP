#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	int h,m,s;
	Time t1;
	
	cout << "\nEnter hours:";
	cin >> h;
	while (h > 23 || h < 0)
	{
		cout << "Invalid!Enter hours again.\n";
		cin >> h;
	}
	t1.setHours(h);
	
	cout << "Enter minutes:";
	cin >> m;
	while (m > 59 || m < 0)
	{
		cout << "Invalid!Enter minutes again.\n";
		cin >> m;
	}
	t1.setMinutes(m);
	
	
	cout << "Enter seconds:";
	cin >> s;
	while (s > 59 || s < 0)
	{
		cout << "Invalid!Enter seconds again.\n";
		cin >> s;
	}
	t1.setSeconds(s);

	cout << "\nTime is: ";
	t1.print();

	cout << "\nEnter hours to advance:";
	cin >> h;
	cout << "Enter minutes to advance:";
	cin >> m;
	cout << "Enter seconds to advance:";
	cin >> s;
	cout << "\nTime advanced by: " << h << ":" << m << ":" << s << endl;
	t1.advance(h, m, s);
	cout << "\nAdvanced time is: ";
	t1.print();

	cout << "\nEnter hours to reset:";
	cin >> h;
	if (h > 23 || h < 0)
	{
		cout << "Invalid!Enter hours again.\n";
		cin >> h;
	}
	cout << "Enter minutes to reset:";
	cin >> m;
	if (m > 59 || m < 0)
	{
		cout << "Invalid!Enter minutes again.\n";
		cin >> m;
	}
	cout << "Enter seconds to reset:";
	cin >> s;
	if (s > 59 || s < 0)
	{
		cout << "Invalid!Enter seconds again.\n";
		cin >> s;
	}
	t1.reset(h, m, s);
	cout << "\nTime reset to: ";
	t1.print();

	Time t2 = t1;
	cout << endl << endl;
	t2.print();

}