//BSEF21m033
#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	str = new char;
	*str = '\0';
	length = 0;
}

MyString::MyString(const char* str1)
{
	int size = 0;
	while (str1[size] != '\0')
		size++;
	length = size;
	str = new char[this->length + 1];
	for (int i = 0; i < length; i++)
		str[i] = str1[i];
	str[length] = '\0';
}

MyString::MyString(const MyString& str1)
{
	length = str1.length;
	str = new char[this->length + 1];
	for (int i = 0; i < length; i++)
		str[i] = str1.str[i];
	str[length] = '\0';
}

MyString::~MyString()
{
	delete[] str;
	str = nullptr;
}

void MyString::display() const
{
	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
}

int MyString::getLength() const
{
	return length;
}

const MyString& MyString::operator=(const MyString& rhs)
{
	if (this != &rhs)
	{
		delete[] str;
		length = rhs.length;
		str = new char[this->length + 1];
		for (int i = 0; i < length; i++)
			str[i] = rhs.str[i];
		str[length] = '\0';
	}
	return *this;
}


//overloading + operator. you can perform concatenation using
//+ operator
MyString MyString::operator+(const MyString& obj) const
{
	MyString temp;

	temp.length = this->length + obj.length;
	temp.str = new char[temp.length + 1];

	int i{};
	for (i = 0; str[i] != '\0'; i++)
		temp.str[i] = this->str[i];
	for (int j = i, k = 0; j < temp.length; j++, k++)
		temp.str[j] = obj.str[k];
	temp.str[temp.length] = '\0';
	return temp;
}
//overloading += operator
const MyString& MyString::operator+= (const MyString& rhs)
{
	*this = *this + rhs;
	return *this;
}


void MyString::setStr(const char* str1)
{
	delete[] str;
	int size = 0;
	while (str1[size] != '\0')
		size++;
	length = size;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = str1[i];
	str[length] = '\0';
}

//overloading == operator
bool MyString::operator==(const MyString& rhs) const
{
	if (this->length != rhs.length)
		return false;
	for (int i = 0; i < length; i++)
	{
		if (this->str[i] != rhs.str[i])
			return false;
	}
	return true;
}

bool MyString::operator!=(const MyString& rhs) const
{
	if (*this == rhs)
		return false;
	else
		return true;
}

//overloading < operator
bool MyString::operator<(const MyString& rhs) const
{
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (this->str[i] < rhs.str[i])
			count++;
	}

	if (count == length)
		return true;
	else
		return false;
}

//overloading <= operator
bool MyString::operator<=(const MyString& rhs) const
{
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (this->str[i] <= rhs.str[i])
			count++;
	}

	if (count == length)
		return true;
	else
		return false;
}

bool MyString::operator>(const MyString& rhs) const
{
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (this->str[i] > rhs.str[i])
			count++;
	}

	if (count == length)
		return true;
	else
		return false;
}


bool MyString::operator>=(const MyString& rhs) const
{
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (this->str[i] >= rhs.str[i])
			count++;
	}

	if (count == length)
		return true;
	else
		return false;
}

//returns substring of the string from index 'start' to 'end'
MyString MyString::subString(int startIdx, int endIdx) const
{
	MyString temp;
	temp.length = endIdx - startIdx + 1;
	temp.str = new char[temp.length + 1];
	int j = 0;
	for (int i = startIdx; i <= endIdx; i++)
	{
		temp.str[j] = str[i];
		j++;
	}
	temp.str[temp.length] = '\0';
	return temp;

}

//overloading pre-increment operator
MyString& MyString::operator++()
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		this->str[i]++;
	}
	return *this;
}

//for conversion from 'MyString' to 'int'
MyString::operator int()
{
	int num = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			num = (str[i] - 48) + (num * 10);
		else
			num = num + static_cast<int>(str[i]);
	}

	return num;

}

MyString::operator char* ()
{
	char* temp = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}

	temp[length] = '\0';

	return temp;
}

//returns index of first occurence of substring in the string
int MyString::find(const MyString& subStr) const
{
	int index = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == subStr.str[0])
		{
			int j = 0;
			while (j < subStr.length && str[i + j] == subStr.str[j])
				j++;
			if (j == subStr.length)
			{
				index = i;
			}
		}
	}
	return index;
}

//returns index of first occurence of char in the string
int MyString::find(const char ch) const
{
	int index = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ch)
			index = i;
	}
	return index;
}


//returns index of first occurence of substring in the string after index 'start'
int MyString::find(const MyString& subStr, int start) const
{
	int index = -1;
	for (int i = start; i < length; i++)
	{
		if (str[i] == subStr.str[0])
		{
			int j = 0;
			while (j < subStr.length && str[i + j] == subStr.str[j])
				j++;
			if (j == subStr.length)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

//returns index of last occurence of substring in the string
int MyString::rfind(const MyString& last) const
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] == last.str[0])
		{
			int j = 0;
			while (j < last.length && this->str[i + j] == last.str[j])
				j++;
			if (j == last.length)
			{
				for (int index = this->length - 1; index >= 0; index--)
				{
					for (int index1 = 0; index1 < last.length; index1++)
					{
						if (this->str[index] == last.str[index1])
							return index;
					}
				}
			}
		}
	}
	return -1;
}

int MyString::rfind(const char ch) const
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == ch)
			return i;
	}
	return -1;
}

