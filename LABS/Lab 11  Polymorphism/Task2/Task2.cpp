#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

int main()
{
	const int SIZE = 2;
	Person* person[SIZE];
	cout << "Which functionality you want to use?" << endl;
	cout << "1. Student" << endl;
	cout << "2. Teacher " << endl;
	int choice;
	cin >> choice;
	while (choice < 1 || choice > SIZE)
	{
		cout << "Invalid choice. Please enter a number 1 or 2." << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		string name; int age, numOfSubjects;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age;
		cout << "Enter number of subjects: ";
		cin >> numOfSubjects;
		int* marks = new int[numOfSubjects];
		cout << "Enter subjects:\n";
		for (int i = 0; i < numOfSubjects; i++)
		{
			cout << "Enter marks for subject " << i + 1 << ": ";
			cin >> marks[i];
		}
		person[0] = new Student(name, age, marks, numOfSubjects);
		person[0]->printInfo();
		delete person[0];
		person[0] = nullptr;
	}
	else if (choice == 2)
	{
		string name;
		int age;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter age: ";
		cin >> age;
		int numClasses;
		cout << "Enter number of classes: ";
		cin >> numClasses;
		string* classes = new string[numClasses];
		cout << "Enter classes:\n";
		for (int i = 0; i < numClasses; i++)
		{
			cout << "Title of Lecture # " << i + 1 << ": ";
			cin >> classes[i];
		}
		person[1] = new Teacher(name, age, classes, numClasses);
		person[1]->printInfo();
		delete person[1];
		person[1] = nullptr;
	}
	return 0;
}