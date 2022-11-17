#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
#ifndef TEACHER_H
#define TEACHER_H

class Teacher : public Person
{
private:
	string* lectureName;
	int numOfLec;

public:
	Teacher();
	Teacher(string, int, string*, int);
	string* getLectures() const;
	int getNumLec() const;
	void setLectures(string*, int);
	void printInfo();
	~Teacher();
};

#endif // !TEACHER_H

