#include <iostream>
#include <string>
using namespace std;

template <class T>
T getMin(T val1, T val2)
{
	if (val1 < val2)
		return val1;
	else
		return val2;
}

int main()
{
	cout << "Which Data type you want to choose?\n";
	cout << "1. Integer" << endl;
	cout << "2. Float" << endl;
	cout << "3. Double" << endl;
	cout << "4. char" << endl;
	cout << "Enter your choice: ";

	int choice;
	cin >> choice;
	if (choice == 1)
	{
		int val1, val2;
		cout << "Enter two Aegers: ";
		cin >> val1 >> val2;
		cout << "The minimum value is: " << getMin(val1, val2) << endl;
	}
	else if (choice == 2)
	{
		float val1, val2;
		cout << "Enter two floats: ";
		cin >> val1 >> val2;
		cout << "The minimum value is: " << getMin(val1, val2) << endl;
	}
	else if (choice == 3)
	{
		double val1, val2;
		cout << "Enter two doubles: ";
		cin >> val1 >> val2;
		cout << "The minimum value is: " << getMin(val1, val2) << endl;
	}
	else if (choice == 4)
	{
		char val1, val2;
		cout << "Enter two chars: ";
		cin >> val1 >> val2;
		cout << "The lowest character is: " << getMin(val1, val2) << endl;
	}
	else
	{
		cout << "Invalid choice" << endl;
	}
}