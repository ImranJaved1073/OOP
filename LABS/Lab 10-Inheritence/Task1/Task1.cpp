#include <iostream>
#include "Date.h"
#include "Time.h"
#include "DateTime.h"
using namespace std;


int main()
{
	Date d1(28,5,2015);
	d1.print();
	cout << " ";
	Time t(11, 30, 15);
	t.print();
	cout << endl << endl;
	DateTime a(28, 5, 2015, 11, 30, 15);
	a.printDateTime();
	cout << endl << endl;
	a.showFormattedDateTime();

}