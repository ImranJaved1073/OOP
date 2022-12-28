#include <iostream>
#include <string>
using namespace std;

template<class A>
void displayArray(const A* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	cout << "Which Data type you want to choose?\n";
	cout << "1. Array of Integers" << endl;
	cout << "2. Array of Floats" << endl;
	cout << "3. Array of Doubles" << endl;
	cout << "4. Array of char" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		int arr1[5] = { 1, 2, 3, 4, 5 };
		displayArray(arr1, 5);
	}
	else if (choice == 2)
	{
		float arr2[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
		displayArray(arr2, 5);
	}
	else if (choice == 3)
	{
		double arr3[5] = { 1.11, 2.22, 3.33, 4.44, 5.55 };
		displayArray(arr3, 5);
	}
	else if (choice == 4)
	{
		char arr4[5] = { 'a', 'b', 'c', 'd', 'e' };
		displayArray(arr4, 5);
	}
	else
	{
		cout << "Invalid choice" << endl;
	}
}