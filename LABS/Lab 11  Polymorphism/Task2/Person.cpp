#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person()
{
	name = "";
	age = 0;
}
Person::Person(string name, int age)
{
	this->name = name;
	this->age = age;
}
string Person::getFullName() const
{
	return name;
}
int Person::getAge() const
{
	return age;
}
void Person::setName(string name)
{
	this->name = name;
}
void Person::setAge(int age)
{
	this->age = age;
}
void Person::printInfo()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}
Person::~Person()
{
	cout << "\nPerson destructor called" << endl;
}

void Person::setMarks(int*, int) {}
void Person::setLectures(string*, int){}