#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student : public Person
{
private:
	int* marks;
	int numSubjects;

public:
	Student();
	Student(string, int, int*, int);
	int* getMarks() const;
	int getNumSubjects() const;
	void setMarks(int*, int);
	void printInfo();
	~Student();
};

#endif // !STUDENT_H


