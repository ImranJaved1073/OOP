#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct StudentData
{
	string name, rollNumber;
	double cgpa = 0;
};

//Prototypes
void populateArray(StudentData*, const int size);
StudentData findCR(const StudentData*, const int size);
void printDropOutStudents(StudentData*, const int size);
void printProbations(StudentData*, const int size);
void printStudentData(string, StudentData*, const int size);
void printDegree(string);
void printSection(char);
void printDepartment(char, string);
string convertLowertoUpperCase(string);

//start of main
int main()
{
	const int SIZE = 30;
	StudentData students[SIZE];
	populateArray(students, SIZE);

	StudentData getCR = findCR(students, SIZE);
	cout << "_____________\n";
	cout << "\nThe CR is:\n";
	cout << "_____________\n";
	cout << "\nNAME: " << getCR.name;
	cout << "\nROLL#: " << getCR.rollNumber;
	cout << "\nCGPA: " << getCR.cgpa << endl << endl;

	printDropOutStudents(students, SIZE);
	printProbations(students, SIZE);

	string rollNoInput;
	cout << "___________________________________________________________________________\n\n";
	cout << "Enter the Roll No. of the student you want to get information about: ";
	cin >> rollNoInput;
	rollNoInput = convertLowertoUpperCase(rollNoInput);
	printStudentData(rollNoInput, students, SIZE);

}//end of main

void populateArray(StudentData* students, const int size)
{
	ifstream inputFile;
	inputFile.open("Students.txt");
	if (!inputFile)
	{
		cout << "ERROR!file is not being read.\n";
	}
	else
	{
		cout << "\"File Successfully read\"\n\n";
		for (int i = 0; i < size; i++)
		{
			getline(inputFile >> ws, students[i].rollNumber, ',');
			getline(inputFile >> ws, students[i].name, ',');
			inputFile >> students[i].cgpa;
		}
		inputFile.close();
	}
}

StudentData findCR(const StudentData* gPA, const int size)
{
	StudentData CR;
	CR.cgpa = gPA[0].cgpa;
	for (int i = 0; i < size; i++)
	{
		if (gPA[i].cgpa > CR.cgpa)
		{
			CR.cgpa = gPA[i].cgpa;
			CR.name = gPA[i].name;
			CR.rollNumber = gPA[i].rollNumber;
		}
	}
	return CR;
}

void printDropOutStudents(StudentData* dropOuts, const int size)
{
	cout << "____________________________________________\n";
	cout << "\nTHE LIST OF DROP OUT STUDENTS IS BELOW : \n";
	cout << "____________________________________________\n\n\n";
	for (int i = 0; i < size; i++)
	{
		if (dropOuts[i].cgpa < 2.70)
		{
			cout << "\tRoll #: " << dropOuts[i].rollNumber << endl;
			cout << "\tNAME: " << dropOuts[i].name << endl;
			cout << "\tCGPA: " << dropOuts[i].cgpa << endl;
			cout << endl;
		}
	}
}

void printProbations(StudentData* probation, const int size)
{
	cout << "____________________________________________\n";
	cout << "\nTHE LIST OF PROBATED STUDENTS IS BELOW : \n";
	cout << "____________________________________________\n\n";
	for (int i = 0; i < size; i++)
	{
		if (probation[i].cgpa > 2.30 && probation[i].cgpa < 2.70)
		{
			cout << "\tRoll#: " << probation[i].rollNumber << endl;
			cout << "\tNAME:" << probation[i].name << endl;
			cout << "\tCGPA = " << probation[i].cgpa << endl << endl;
		}
	}
	cout << endl;
}

void printStudentData(string rollNo, StudentData* data, const int size)
{
	bool isValidRecord = 0;
	string name;
	string degree = rollNo.substr(0, 3);
	string session = rollNo.substr(4, 2);
	char section = rollNo[6];
	char department = rollNo[7];
	for (int i = 0; i < size; i++)
	{
		if (data[i].rollNumber == rollNo)
		{
			name = data[i].name;
			isValidRecord = 1;
		}
	}

	if (isValidRecord == 1)
	{
		cout << "\nRoll#: " << rollNo;
		cout << "\nName: " << name;
		printDegree(degree);
		cout << "\nSession: 20" << stoi(session) << "-20" << (stoi(session) + 4);
		printSection(section);
		printDepartment(department, degree);
	}
	else
		cout << "\nThere is no Record against this roll number.\n\n";
}

void printDegree(string degree)
{
	if (degree == "BSE")
		cout << "\nDegree: BS Software Engineering.";

	else if (degree == "BIT")
		cout << "\nDegree: BS Information Technology.";

	else if (degree == "BCS")
		cout << "\nDegree: BS Computer Science.";
}

void printSection(char section)
{
	if (section == 'A')
		cout << "\nSection: Afternoon.";

	else if (section == 'M')
		cout << "\nSection: Morning.";
}

void printDepartment(char department, string degree)
{
	if (department == '0' && degree == "BSE")
		cout << "\nDepartment: Department of Software Engineering, Old Campus.";

	else if (department == '0' && degree == "BIT")
		cout << "\nDepartment: Department of Information Technology, Old Campus.";

	else if (department == '0' && degree == "BCS")
		cout << "\nDepartment: Department of Computer Science, Old Campus.";

	else if (department == '5' && degree == "BSE")
		cout << "\nDepartment: Department of Software Engineering, New Campus.";

	else if (department == '5' && degree == "BIT")
		cout << "\nDepartment: Department of Information Technology, New Campus.";

	else if (department == '5' && degree == "BCS")
		cout << "\nDepartment: Department of Computer Science, New Campus." << endl << endl;
	cout << endl;
}


string convertLowertoUpperCase(string convert)
{
	string roll = convert;
	for (int i = 0; i < 11; i++)
	{
		if (roll[i] >= 97 && roll[i] <= 122)
			roll[i] -= 32;
	}
	return roll;
}