#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;

int main()
{
	cout << "Which functionality you want to use?" << endl;
	cout << "1. Student" << endl;
	cout << "2. Teacher " << endl;
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 2)
	{
		cout << "Invalid choice. Please enter a number 1 or 2: ";
		cin >> choice;
	}
	if (choice == 1)
	{
		string name; int age, numOfSubjects;
		Person* p;
		p = new Student;
		int* marks;

		cout << "______________________STUDENT____________________" << endl;
		cout << "                ENTER STUDENT DATA " << endl;
		cout <<"_________________________________________________"<<endl;
		cout << "Enter the name of the Student:";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the Age of the Student:";
		while (!(cin >> age) || age < 0 || age > 100)
		{
			cout << "Invalid age. Please enter a number between 0 and 100: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		p->setName(name);
		p->setAge(age);
		cout << "Enter number of subjects: ";
		while (!(cin >> numOfSubjects) || numOfSubjects < 0)
		{
			cout << "Invalid number of subjects. Please enter a number greater than 0: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		while (numOfSubjects < 0)
		{
			cout << "Enter Valid COurses..!" << endl;
			cin >> numOfSubjects;
		}
		marks = new int[numOfSubjects];
		cout << "Enter subjects:\n";
		for (int i = 0; i < numOfSubjects; i++)
		{
			cout << "Enter marks for subject " << i + 1 << ": ";
			while (!(cin >> marks[i]) || marks[i] < 0 || marks[i] > 100)
			{
				cout << "Invalid marks. Please enter marks between 0 and 100: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
		p->setMarks(marks, numOfSubjects);
		cout << "_________________________________________________" << endl;
		cout << "            INFORMATION OF STUDENT  " << endl;
		cout << "_________________________________________________" << endl;
		p->printInfo();
		cout << "_________________________________________________" << endl;
		delete p;
		p= nullptr;

	}
	else if (choice == 2)
	{
		string name; 
		int age, numOfLectures;
		Person* p;
		p = new Teacher;
		string* lecturesName;
		
		cout << "______________________TEACHER____________________" << endl;
		cout << "                ENTER TEACHER DATA " << endl;
		cout << "_________________________________________________" << endl;
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Age of Teacher: ";
		while(!(cin>>age) || age<0 || age>120)
		{
			cout << "Enter valid Age" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		p->setName(name);
		p->setAge(age);
		cout << "Enter number of lectures: ";
		while (!(cin >> numOfLectures) || numOfLectures < 0)
		{
			cout << "Enter Valid Lectures..!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		lecturesName = new string[numOfLectures];
		cout << "Enter lectures:\n";
		cin.ignore();
		for (int i = 0; i < numOfLectures; i++)
		{
			cout << "Enter name of lecture " << i + 1 << ": ";
			getline(cin, lecturesName[i]);
		}
		p->setLectures(lecturesName, numOfLectures);
		cout << "_________________________________________________" << endl;
		cout << "             INFORMATION OF TEACHER  " << endl;
		cout << "_________________________________________________" << endl;
		p->printInfo();
		cout << "_________________________________________________" << endl;
		delete p;
		p = nullptr;
	}

	return 0;
}