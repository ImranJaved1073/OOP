#include <iostream>
using namespace std;

//Prototypes
int findMin(int inArray[], const int size);
int findMax(int inArray[], const int size);
int computeAverage(int inArray[], const int size);
int computeMedian(int inArray[], const int size);
void sort(int array[], int size);
void swap(int& a, int& b);

int main()
{
	const int SIZE = 5;
	int students[SIZE];
	//cout << "Enter number of students enrolled in the course:";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter marks of student " << i + 1 << ":";
		cin >> students[i];
		while (students[i] < 0)
		{
			cout << "Invalid Marks! Marks Should be grater than 0.";
			cout << "Enter marks of student " << i << endl;

			cin >> students[i];
		}
	}
	cout << "Maximum Marks is: " << findMax(students, SIZE) << endl;
	cout << "Minimum marks is: " << findMin(students, SIZE) << endl;
	cout << "Average of marks is: " << computeAverage(students, SIZE) << endl;
	cout << "Median of marks is: " << computeMedian(students, SIZE) << endl;
	system("pause");
}//end of main

int findMin(int inArray[], const int size)
{
	int min = inArray[0];
	for (int i = 1; i < size; i++)
	{
		if (inArray[i] < min)
			min = inArray[i];
	}

	return min;
}
int findMax(int inArray[], const int size)
{
	int max = inArray[0];
	for (int i = 1; i < size; i++)
	{
		if (inArray[i] > max)
			max = inArray[i];
	}

	return max;
}

int computeAverage(int inArray[], const int size)
{
	int sum = 0, average;
	for (int i = 0; i < size; i++)
	{
		sum += inArray[i];
	}
	average = sum / size;
	return average;
}

int computeMedian(int inArray[], const int size)
{
	sort(inArray, size);
	if (size % 2 != 0)
	{
		return (double)inArray[size / 2];
	}
	else
	{
		return (double)(inArray[(size - 1) / 2] + inArray[size / 2]) / 2.0;
	}
}

void sort(int array[], int size)
{
    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (array[index] > array[index + 1])
            {
                swap(array[index], array[index + 1]);
            }
        }
    }
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}