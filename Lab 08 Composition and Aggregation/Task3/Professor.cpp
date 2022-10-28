#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor()
	{
		name = "";
		designation = "";
		extNo = 0;
		//cout << "Professor Default Constructor!" << endl;
	}
Professor::Professor(string name, string designation, int extNo)
{
	this->name = name;
	this->designation = designation;
	this->extNo = extNo;
}
void Professor::setName(string name)
{
	this->name = name;
}
void Professor::setDesignation(string designation)
{
	this->designation = designation;
}
void Professor::setExtensionNo(int extNo)
{
	this->extNo = extNo;
}
string Professor::getName() const
{
	return name;
}
string Professor::getDesignation() const
{
	return designation;
}
int Professor::getExtNo() const
{
	return extNo;
}

void Professor::display()
{
	cout << "Name: " << name << endl;
	cout << "Designation: " << designation << endl;
	cout << "Extension No: " << extNo << endl;
}
Professor::~Professor()
{
	//cout << "Professor Destructor!" << endl;
}