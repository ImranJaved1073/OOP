#include <iostream>
#include "Set.h"

using namespace std;

int main()
{
	Set<int>s1(4);
	Set<int>s2(5);
	cout << "SET 1\n";
	for (int i = 0; i < s1.getLength(); i++)
	{
		int val;
		cout << "Enter value: ";
		cin >> val;
		s1.insert(val);
	}
	cout << "\nSET 2\n";
	for (int i = 0; i < s2.getLength(); i++)
	{
		int val;
		cout << "Enter value: ";
		cin >> val;
		s2.insert(val);
	}

	// UNION OF SETS
	Set<int> s3 = s3.U(s1, s2);
	cout << "\nUNION OF SETS: ";
	for (int i = 0; i < s3.getIndex(); i++)
	{
		cout << s3.getElement(i) << " ";
	}
	cout << endl;
	
	// COMMON ELEMENTS OF SETS
	Set<int> s4 = s1.common(s1, s2);
	cout << "INTERSECTION OF SETS: ";
	for (int i = 0; i < s4.getIndex(); i++)
	{
		cout << s4.getElement(i) << " ";
	}
	cout << endl;

	if (s1 == s2)
		cout << "SETS ARE EQUAL" << endl;
	else
		cout << "SETS ARE NOT EQUAL" << endl;

	// SUBSET OF SETS

	if (s1.isSubset(s2))
		cout << "SET 1 IS A SUBSET OF SET 2" << endl;
	else
		cout << "SET 1 IS NOT A SUBSET OF SET 2" << endl;
	
	// DIFFERENCE OF SETS
	Set<int> s5 = s1 - s2;
	cout << "DIFFERENCE OF SETS: ";
	for (int i = 0; i < s5.getIndex(); i++)
	{
		cout << s5.getElement(i) << " ";
	}
	cout << endl;

}