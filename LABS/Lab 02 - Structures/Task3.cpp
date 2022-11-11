#include <iostream>
using namespace std;
int main()
{
	int row = 0, col = 0;
	cout << "Enter Size of matrix.....\n";
	cout << "Enter row:";
	cin >> row;
	cout << "Enter column:";
	cin >> col;
	while (row != col)
	{
		cout << "Matrix must be square(rows and cols must be equal)\n";
		cout << "Enter again!\n";
		cout << "Enter row:";
		cin >> row;
		cout << "Enter column:";
		cin >> col;
	}
	int** arr = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	cout << "Enter elements:\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << "\nEntered matrix is:\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	bool isValid = false;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i != j && arr[i][j] != 0)
			{
				isValid = true;
				break;
			}
		}
	}
	if (isValid == true)
		cout << "Matrix is not diagnol.";
	else
		cout << "Matrix is diagnol.";


	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;
}