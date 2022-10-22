#include <iostream>
using namespace std;

int* resizeArray(int inArray[], const int size);

int main()
{
	int size;
	cout << "Enter size of the array:";
	cin >> size;
	int* array = new int[size];
	cout << "Enter elements of array:";
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}

	int* array2;
	array2 = resizeArray(array, size);

	for (int i = 0; i < size*2; i++)
	{
		cout << array2[i] << " ";
	}
	delete[] array;
	array = nullptr;
	delete[] array2;
	array2 = nullptr;

	return 0;
}

int* resizeArray(int inArray[], const int size)
{
	int* array = new int[size*2];
	for (int i = 0; i < size; i++)
	{
		array[i] = inArray[i];
	}
	for (int i = 0; i < size; i++)
	{
		array[i + size] = inArray[i] * 2;
	}
	
	return array;
}
