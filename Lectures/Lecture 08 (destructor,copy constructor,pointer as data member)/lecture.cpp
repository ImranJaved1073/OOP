#include <iostream>
#include <string>
using namespace std;

const int N = 30;

class Student
{
private:
	char name[N + 1];

public:

	Student(char* n)
	{
		strcpy_s(name, n);
	}

	Student()
	{
		strcpy_s(name, "");
	}

	void setName(char* n)
	{
		strcpy_s(name, n);
	}

	const char* getName() const
	{
		return name; //very dangerous to return private member variable pointer
	}

	void displayStudent() const
	{
		cout << "Name is: " << name << endl;
	}
}; 
 

int main()
{
	char temp[N + 1];
	strcpy_s(temp, "Xyz");
	Student st1(temp);
	st1.displayStudent();

	const char* nm = st1.getName();
	cout << "In main: " << nm << endl;

	// strcpy(nm, "Abc Def");
	cout << "In main: " << nm << endl;
	st1.displayStudent();
	return 0;
}