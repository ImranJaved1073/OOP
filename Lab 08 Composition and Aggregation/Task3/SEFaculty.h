#ifndef SEFACULTY_H
#define SEFACULTY_H
#include "Professor.h"
class SEFaculty
{
	Professor* prof;
	int size;
public:
	SEFaculty();
	SEFaculty(Professor* prof, int size);
	void setProf(Professor* prof);
	Professor* getProf(int i) const;
	void setSize(int size);
	int getSize() const;
	void displayFacultyMembers();
	~SEFaculty();
};

#endif // !SEFACULTY_H

