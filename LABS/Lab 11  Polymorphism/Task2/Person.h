#include <iostream>
#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person
{
private:
	string name;
	int age;

public:
	Person();
	Person(string, int);
	string getFullName() const;
	int getAge() const;
	void setName(string);
	void setAge(int);
	virtual void printInfo();
	virtual ~Person();
	virtual void setMarks(int*, int);
	virtual void setLectures(string*, int);
};

#endif // PERSON_H


