
#include <string>
using namespace std;
class Employee
{
private:
	int employeeId;
	string employeeName;
	string employeeDesignation;
	int hourlyPayRate;
	int numberOfHoursWorked;
	const int WEEKLY_WORKING_HOURS;

public:

	Employee();
	Employee(int,string,string,int,int);
	void setId(int);
	void setName(string);
	void setDesignation(string);
	void setHourlyPayRate(int);
	void setNumberOfHoursWorked(int);

	int calculateMonthlySalary();
	int calculateWeeklySalary();
	int calculateOverTime();

	int getId() const;
	string getName() const;
	string getDesignation() const;
	~Employee();

};

