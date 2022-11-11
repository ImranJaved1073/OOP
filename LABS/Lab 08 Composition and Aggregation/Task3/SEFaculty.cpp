#include "SEFaculty.h"
#include <iostream>
using namespace std;
SEFaculty::SEFaculty()
{
	prof = nullptr;
	size = 0;
	//cout << "SEFaculty Default Constructor!" << endl;
}
SEFaculty::SEFaculty(Professor* prof, int size)
{
	this->prof = prof;
	this->size = size;
}
void SEFaculty::setProf(Professor* prof)
{
	this->prof = prof;
}
Professor* SEFaculty::getProf(int i) const
{
	return &prof[i];
}
void SEFaculty::setSize(int size)
{
	this->size = size;
}
int SEFaculty::getSize() const
{
	return size;
}

void SEFaculty::displayFacultyMembers()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Professor " << i + 1 << endl;
		prof[i].display();
	}
}

SEFaculty::~SEFaculty()
{
	if (prof != nullptr)
	{
		delete[] prof;
		prof = nullptr;
	}

	//cout << "SEFaculty Destructor!" << endl;
}