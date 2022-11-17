#include "Teacher.h"
#include <iostream>
#include <string>
using namespace std;

Teacher::Teacher()
{
	lectureName = nullptr;
	numOfLec = 0;
}

Teacher::Teacher(string na, int a, string* c, int n) : Person(na, a)
{
	lectureName = new string[n];
	for (int i = 0; i < n; i++)
	{
		lectureName[i] = c[i];
	}
	numOfLec = n;
}

string* Teacher::getLectures() const
{
	return lectureName;
}

int Teacher::getNumLec() const
{
	return numOfLec;
}

void Teacher::setLectures(string* c, int n)
{
	lectureName = new string[n];
	for (int i = 0; i < n; i++)
	{
		lectureName[i] = c[i];
	}
	numOfLec = n;
}

void Teacher::printInfo()
{
	cout << "Name of Teacher is:" << getFullName() << endl;
	cout << "Age of Teacher is:" << getAge() << endl;
	cout << "Number of classes taught by teacher are:" << numOfLec << endl;
	cout << "Classes taught by teacher are:" << endl;
	for (int i = 0; i < numOfLec; i++)
	{
		cout << i + 1 << ":" << lectureName[i] << endl;
	}
}

Teacher::~Teacher()
{
	cout << "\nTeacher destructor called" << endl;
	if (lectureName != nullptr)
	{
		delete[] lectureName;
		lectureName = nullptr;
	}
}