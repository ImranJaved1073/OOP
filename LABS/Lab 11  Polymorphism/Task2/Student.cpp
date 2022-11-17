#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student()
{
	marks = nullptr;
	numSubjects = 0;
}

Student::Student(string name, int age, int* s, int n) : Person(name, age)
{
	marks = new int[n];
	for (int i = 0; i < n; i++)
	{
		marks[i] = s[i];
	}
	numSubjects = n;
}

int* Student::getMarks() const
{
	return marks;
}

int Student::getNumSubjects() const
{
	return numSubjects;
}

void Student::setMarks(int* s, int n)
{
	marks = new int[n];
	for (int i = 0; i < n; i++)
	{
		marks[i] = s[i];
	}
	numSubjects = n;
}

void Student::printInfo()
{
	cout << "Name of student is:" << getFullName() << endl;
	cout << "Age of student is:" << getAge() << endl;
	for (int i = 0; i < numSubjects; i++)
		cout << "Marks in subject " << i + 1 << " is: " << marks[i] << endl;
}

Student::~Student()
{
	cout << "\nStudent destructor called" << endl;
	if (marks != nullptr)
	{
		delete[] marks;
		marks = nullptr;
	}
}