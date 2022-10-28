#include "Professor.h"
#include "SEFaculty.h"
#include <iostream>
using namespace std;

int main()
{
	int total, extNo;
	string name, designation;
	cout << "Enter the total professors in SE department\n";
	cin >> total;
	Professor* prof = new Professor[total];
	cout << "Enter the details of the professors\n";
	for (int i = 0; i < total; i++)
	{
		cout << "Enter the name of the professor " << endl;
		cin >> name;
		cout << "Enter the designation of the professor " << endl;
		cin >> designation;
		cout << "Enter the extension no of the professor " << endl;
		cin >> extNo;
		prof[i].setName(name);
		prof[i].setDesignation(designation);
		prof[i].setExtensionNo(extNo);
	}
	SEFaculty faculty(prof, total);
	faculty.displayFacultyMembers();
}