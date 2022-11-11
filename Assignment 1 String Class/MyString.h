//BSEF21m033
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
using namespace std;
class MyString

{

private:

	char* str;
	int length;

public:


	MyString();
	MyString(const char*);

	MyString(const MyString&);
	~MyString();

	void display() const;
	int getLength() const;

	const MyString& operator=(const MyString&);

	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>>(istream&, MyString&);

	MyString operator+(const MyString&) const;
	bool operator==(const MyString&) const;
	bool operator!=(const MyString&) const;
	bool operator<(const MyString&) const;
	bool operator<=(const MyString&) const;
	bool operator>(const MyString&) const;
	bool operator>=(const MyString&) const;
	const MyString& operator += (const MyString&);
	void setStr(const char*);
	operator int();
	operator char* ();
	MyString& operator++();
	MyString subString(int, int) const;
	int find(const MyString&) const;
	int find(const char) const;
	int find(const MyString&, int) const;
	int rfind(const MyString&) const;
	int rfind(const char) const;

};

#endif // 


