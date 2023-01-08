// GPA calculator

#include <iostream>
#include <string>

using namespace std;

class GPA
{
private:
    int numClasses;
    double *gradePoint;
    double *creditHour;
    float *marks;
    string *className;
    double gpa;

public:
    GPA();
    ~GPA();
    void setNumClasses(int);
    void setMarks();
    void setGradePoint();
    void setCreditHours();
    void setClassName();
    double calcGPA();
    void displayGPA();
};

GPA::GPA()
{
    numClasses = 0;
    gradePoint = nullptr;
    creditHour = nullptr;
    marks = nullptr;
    className = nullptr;
    gpa = 0.0;
}

GPA::~GPA()
{
    if (gradePoint != nullptr)
    {
        delete[] gradePoint;
        gradePoint = nullptr;
    }
    if (creditHour != nullptr)
    {
        delete[] creditHour;
        creditHour = nullptr;
    }
    if (marks != nullptr)
    {
        delete[] marks;
        marks = nullptr;
    }
    if (className != nullptr)
    {
        delete[] className;
        className = nullptr;
    }
}

void GPA::setNumClasses(int num)
{
    numClasses = num;
}

void GPA::setClassName()
{
    cin.ignore();
    className = new string[numClasses];
    for (int i = 0; i < numClasses; i++)
    {
        cout << "Enter the name of class " << i + 1 << ": ";
        getline(cin, className[i]);
    }
}

void GPA::setMarks()
{
    marks = new float[numClasses];
    for (int i = 0; i < numClasses; i++)
    {
        cout << "Enter the marks for " << className[i] << ": ";
        cin >> marks[i];
        if (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks. Please enter marks between 0 and 100." << endl;
            cout << "Enter the marks for " << className[i] << ": ";
            cin >> marks[i];
        }
    }
}

void GPA::setGradePoint()
{
    gradePoint = new double[numClasses];
    for (int i = 0; i < numClasses; i++)
    {
        if (marks[i] >= 85)
            gradePoint[i] = 4.0;
        else if (marks[i] >= 80)
            gradePoint[i] = 3.7;
        else if (marks[i] >= 75)
            gradePoint[i] = 3.3;
        else if (marks[i] >= 70)
            gradePoint[i] = 3.0;
        else if (marks[i] >= 65)
            gradePoint[i] = 2.7;
        else if (marks[i] >= 61)
            gradePoint[i] = 2.3;
        else if (marks[i] >= 58)
            gradePoint[i] = 2.0;
        else if (marks[i] >= 55)
            gradePoint[i] = 1.7;
        else if (marks[i] >= 50)
            gradePoint[i] = 1.0;
        else
            gradePoint[i] = 0.0;
    }
}

void GPA::setCreditHours()
{
    creditHour = new double[numClasses];
    for (int i = 0; i < numClasses; i++)
    {
        cout << "Enter the credit hours for " << className[i] << ": ";
        cin >> creditHour[i];
    }
}

double GPA::calcGPA()
{
    double AGP = 0.0;
    double totalCreditHours = 0.0;
    for (int i = 0; i < numClasses; i++)
    {
        AGP += gradePoint[i] * creditHour[i];
        totalCreditHours += creditHour[i];
    }
    gpa = AGP / totalCreditHours;
    return gpa;
}

void GPA::displayGPA()
{
    cout << "Your GPA is: " << gpa << endl;
}

int main()
{
    GPA student;
    int numClasses;
    int numSemesters;
    cout << "How many semesters have you taken? ";
    cin >> numSemesters;
    double *cgpa = new double[numSemesters];
    for (int i = 0; i < numSemesters; i++)
    {
        cout<<"Do you want to calculate your GPA for semester "<<i+1<<"? (y/n) ";
        char choice;
        cin>>choice;
        if(choice=='y')
        {
            int numClasses;
            cout << "How many classes are you taking? ";
            cin >> numClasses;
            student.setNumClasses(numClasses);
            student.setClassName();
            student.setMarks();
            student.setGradePoint();
            student.setCreditHours();
            student.calcGPA();
            student.displayGPA();
            cgpa[i]=student.calcGPA();
        }
        else
        {
            cout << "Enter your GPA for semester " << i + 1 << ": ";
            cin >> cgpa[i];
        }
    }
    double total = 0.0;
    for (int i = 0; i < numSemesters; i++)
    {
        total += cgpa[i];
    }
    double cgpaFinal = total / numSemesters;
    cout << "Your CGPA is: " << cgpaFinal << endl;

    delete[] cgpa;
    cgpa = nullptr;

    return 0;
}
