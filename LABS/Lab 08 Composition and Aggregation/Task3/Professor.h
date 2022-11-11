#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>
using namespace std;
class Professor
{
private:
	
	string name;
	string designation;
	int extNo;
	
public:
	Professor();
	Professor(string name, string designation, int extNo);
	void setName(string name);
	void setDesignation(string designation);
	void setExtensionNo(int extNo);
	string getName() const;
	string getDesignation() const;
	int getExtNo() const;

	void display();
	~Professor();
};

#endif // !PROFESSOR_H
