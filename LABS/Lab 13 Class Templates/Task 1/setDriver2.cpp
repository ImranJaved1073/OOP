#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	cout << "How many sets you want to create? ";
	int n;
	cin >> n;
	Set<int>* s = new Set<int>[n];
	for (int i = 0; i < n; i++)
	{
		cout << "How many elements you want to insert in set " << i + 1 << "? ";
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int temp;
			cout << "Enter element " << j + 1 << ": ";
			cin >> temp;
			s[i].insert(temp);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Set " << i + 1 << ": ";
		for (int j = 0; j < s[i].getIndex(); j++)
		{
			cout << s[i].getElement(j) << " ";
		}
		cout << endl;
	}
	int choice;
	do
	{
		system("pause");
		system("cls");
		for (int i = 0; i < n; i++)
		{
			cout << "Set " << i + 1 << ": ";
			for (int j = 0; j < s[i].getIndex(); j++)
			{
				cout << s[i].getElement(j) << " ";
			}
			cout << endl;
		}
		cout << "1. Union" << endl;
		cout << "2. Intersection" << endl;
		cout << "3. Difference" << endl;
		cout << "4. Subset" << endl;
		cout << "5. Equality" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Enter set numbers to perform union: ";
			int a, b;
			cin >> a >> b;
			while (a > n || b > n)
			{
				cout << "Enter valid set numbers to perform union: ";
				cin >> a >> b;
			}
			Set<int> temp = s[a - 1] + s[b - 1];
			cout << "UNION of set " << a << " and set " << b << " is: ";
			for (int i = 0; i < temp.getIndex(); i++)
			{
				cout << temp.getElement(i) << " ";
			}
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Enter set numbers to perform intersection: ";
			int a, b;
			cin >> a >> b;
			while (a > n || b > n)
			{
				cout << "Enter valid set numbers to perform intersection: ";
				cin >> a >> b;
			}
			Set<int> temp = s[a - 1].common(s[a - 1], s[b - 1]);
			cout << "INTERSECTION of set " << a << " and set " << b << " is: ";
			for (int i = 0; i < temp.getIndex(); i++)
			{
				cout << temp.getElement(i) << " ";
			}
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Enter set numbers to perform difference: ";
			int a, b;
			cin >> a >> b;
			while (a > n || b > n)
			{
				cout << "Enter valid set numbers to perform difference: ";
				cin >> a >> b;
			}
			Set<int> temp = s[a - 1] - s[b - 1];
			cout << "DIFFERENCE of set " << a << " and set " << b << " is: ";
			for (int i = 0; i < temp.getIndex(); i++)
			{
				cout << temp.getElement(i) << " ";
			}
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Enter set numbers to check subset: ";
			int a, b;
			cin >> a >> b;
			while (a > n || b > n)
			{
				cout << "Enter valid set numbers to check subset: ";
				cin >> a >> b;
			}
			if (s[a - 1].isSubset(s[b - 1]))
				cout << "Set " << a << " is SUBSET of set " << b << endl;
			else
				cout << "Set " << a << " is not SUBSET of set " << b << endl;
			break;
		}
		case 5:
		{
			cout << "Enter set numbers to check equality: ";
			int a, b;
			cin >> a >> b;
			while (a > n || b > n)
			{
				cout << "Enter valid set numbers to check equality: ";
				cin >> a >> b;
			}
			if (s[a - 1] == s[b - 1])
				cout << "Set " << a << " is EQUAL to set " << b << endl;
			else
				cout << "Set " << a << " is NOT EQUAL to set " << b << endl;
			break;
		}
		case 6:
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (choice != 6);
}