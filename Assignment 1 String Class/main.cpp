//BSEF21m033

#include <iostream>
#include "MyString.h"
#include "MyString.cpp"
using namespace std;

void menu();


ostream& operator<<(ostream& out, const MyString& obj)		//overloading << operator
{
	for (int i = 0; obj.str[i] != '\0'; i++)
		out << obj.str[i];
	return out;
}


istream& operator>>(istream& in, MyString& obj)
{
	int n = 10, i{};

	char* temp = new char[n + 1];

	bool flag = true;

	for (i = 0; flag; i++)
	{
		in.get(temp[i]);

		if (temp[i] == 10)
		{
			flag = false;
		}

		if (i == n - 1)
		{
			n++;

			char* temp2 = new char[n + 1];

			for (int j = 0; j <= i; j++)
			{
				temp2[j] = temp[j];
			}

			delete[] temp;

			temp = temp2;
		}
	}

	temp[i - 1] = '\0';

	delete[] obj.str;

	obj.length = i - 1;

	obj.str = temp;

	return in;
}

//main.cpp

int main()
{
	int choice;
	cout << "From the following menu, please choose Which functionality would you like to use? " << endl;
	menu();
	cin >> choice;
	system("cls");

	while (choice < 1 || choice > 23)
	{
		cout << "Invalid choice. Please try again." << endl;
		cout << "Choose from the following menu: " << endl;
		menu();
		cin >> choice;
		system("cls");
	}

	MyString st1, st2;

	st1 = "The Real Slim Shady";
	st2 = st1;

	MyString st3("muaz"), st4("Goodbye");
	MyString st5(st3);
	int start{}, end{}, index{};
	char ch{};

	if (choice == 1)
	{
		cout << "\nPlease enter the string you want to display on the screen: ";
		cin.ignore();
		cin >> st1;
		cout << "\nThe string you entered is: ";
		cout << st1;
		cout << "\n\n";
	}

	else if (choice == 2)
	{
		cout << "\nPlease enter the string you want to get the length of: ";
		cin >> st1;
		cout << "\nThe length of the entered string (including spaces) is: " << st1.getLength();
		cout << "\n\n";
	}

	else if (choice == 3)
	{
		cout << "\nEnter String 1: ";
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		MyString st3 = st1 + st2;
		cout << st3 << "\n\n";
	}

	else if (choice == 4)
	{
		cout << "\nEnter String 1: ";
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		if (st1 == st2)
		{
			cout << "\n" << st1 << " and " << st2 << " are Equal.\n\n";
		}
		else
		{
			cout << "\n" << st1 << " and " << st2 << " are not Equal.\n\n";
		}
	}

	else if (choice == 5)
	{
		cout << "\nEnter String 1: ";
		cin.ignore();
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		if (st1 != st2)
		{
			cout << "\n" << st1 << " and " << st2 << " are not Equal.\n\n";
		}
		else
		{
			cout << "\n" << st1 << " and " << st2 << " are Equal.\n\n";
		}
	}

	else if (choice == 6)
	{
		cout << "\nEnter String 1: ";
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		if (st1 < st2)
		{
			cout << "\n" << st1 << " is less than " << st2 << "\n\n";
		}
		else
		{
			cout << "\n" << st1 << " is not less than " << st2 << "\n\n";
		}
	}

	else if (choice == 7)
	{
		cout << "\nEnter String 1: ";
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		if (st1 <= st2)
		{
			cout << "\n" << st1 << " is less than or equal to " << st2 << "\n\n";
		}
		else
		{
			cout << "\n" << st1 << " is not less than or equal to " << st2 << "\n\n";
		}
	}


	else if (choice == 8)
	{
		cout << "\nEnter String 1: ";
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		if (st1 > st2)
		{
			cout << "\n" << st1 << " is greater than " << st2 << "\n\n";
		}
		else
		{
			cout << "\n" << st1 << " is not greater than " << st2 << "\n\n";
		}
	}

	else if (choice == 9)
	{
		cout << "\nEnter String 1: ";
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		if (st1 >= st2)
		{
			cout << "\n" << st1 << " is greater than or equal to " << st2 << "\n\n";
		}
		else
		{
			cout << "\n" << st1 << " is not greater than or equal to " << st2 << "\n\n";
		}
	}


	else if (choice == 10)
	{
		cout << "\nEnter String 1: ";
		cin >> st1;
		cout << "\nEnter String 2: ";
		cin >> st2;
		st1 += st2;
		cout << "\n" << st1 << "\n\n";
	}

	else if (choice == 11)
	{
		cout << "\nEnter the String: ";
		cin >> st1;
		cout << "\nst1.str = " << st1 << "\n\n";
	}

	else if (choice == 12)
	{
		cout << "\nEnter the String: ";
		cin.ignore();
		cin >> st1;
		int temp = st1;
		cout << "\n\"" << st1 << "\" is converted to " << temp << "\n\n";
	}


	else if (choice == 13)
	{
		cout << "\nEnter the String: ";
		cin.ignore();
		cin >> st1;
		char* c[] = { st1 };
		cout << "\n\"" << st1 << "\" is converted to " << *c << "\n\n";
	}

	else if (choice == 14)
	{
		cout << "\nEnter the String: ";
		cin.ignore();
		cin >> st1;
		st2 = st1;
		cout << "\n\"" << st2 << "\" is incremented to " << ++st1 << "\n\n";
	}

	else if (choice == 15)
	{
		cout << "\nEnter the String: ";
		cin >> st1;
		cout << "\nEnter the starting index: ";
		cin >> start;
		cout << "\nEnter the ending index: ";
		cin >> end;
		cout << "\nThe substring is: " << st1.subString(start, end) << "\n\n";
	}

	else if (choice == 16)
	{
		cout << "\nEnter the String: ";
		cin >> st1;
		cout << "\nEnter the substring: ";
		cin >> st2;
		if (st1.find(st2) == -1)
		{
			cout << "Substring not found!\n\n";
		}
		else
		{
			cout << "\nThe index of the first occurence of the substring is: " << st1.find(st2) << "\n\n";
		}
	}

	else if (choice == 17)
	{
		cout << "\nEnter the String: ";
		cin >> st1;
		cout << "\nEnter the character: ";
		cin >> ch;
		if (st1.find(ch) == -1)
		{
			cout << "\nCharacter not found!\n\n";
		}
		else
		{
			cout << "\nThe index of the first occurence of the character is: " << st1.find(ch) << "\n\n";
		}
	}

	else if (choice == 18)
	{
		cout << "\nEnter the String: ";
		cin >> st1;
		cout << "\nEnter the substring: ";
		cin >> st2;
		cout << "\nEnter the starting index: ";
		cin >> index;
		if (st1.find(st2, index) == -1)
		{
			cout << "\nSubstring not found!\n\n";
		}
		else
		{
			cout << "\nThe index of the first occurence of the Substring after the starting index is: " << st1.find(st2, index) << "\n\n";
		}
	}

	else if (choice == 19)
	{
		cout << "\nEnter the String: ";
		cin.ignore();
		cin >> st1;
		cout << "\nEnter the substring: ";
		cin >> st2;
		if (st1.rfind(st2) == -1)
		{
			cout << "\nSubstring not found!\n\n";
		}
		else
		{
			cout << "\nThe start index of the last occurence of substring in the MyString object is: " << st1.rfind(st2) << "\n\n";
		}
	}

	else if (choice == 20)
	{
		cout << "\nEnter the String: ";
		cin.ignore();
		cin >> st1;
		cout << "\nEnter the character: ";
		cin >> ch;
		if (st1.rfind(ch) == -1)
		{
			cout << "\nCharacter not found!\n\n";
		}
		else
		{
			cout << "\nThe index of last occurence of character in the MyString object is: " << st1.rfind(ch) << "\n\n";
		}
	}

}

void menu()
{
	cout << "\n\n\t1- Display a MyString object.";
	cout << "\n\t2- Get length of a MyString object.";
	cout << "\n\t3- Concatenation Two MyString objects.";
	cout << "\n\t4- Compare equality of two Mystring objects.";
	cout << "\n\t5- Compare inequality of two Mystring objects.";
	cout << "\n\t6- Check if one MyString object is less than another.";
	cout << "\n\t7- Check if one MyString object is less than or equal to another.";
	cout << "\n\t8- Check if one MyString object is greater than another.";
	cout << "\n\t9- Check if one MyString object is greater than or equal to another.";
	cout << "\n\t10- Append second MyString object to the first.";
	cout << "\n\t11- Set the data member of a MyString object and display it.";
	cout << "\n\t12- Convert a MyString object to int.";
	cout << "\n\t13- Convert a MyString object to char.";
	cout << "\n\t14- Increment every element of a MyString object.";
	cout << "\n\t15- Get substring from a MyString object (including spaces).";
	cout << "\n\t16- Get index of first occurence of substring in a Mystring object.";
	cout << "\n\t17- Get index of first occurence of character in a MyString object.";
	cout << "\n\t18- Get index first occurence of substring in a MyString object after index 'start'.";
	cout << "\n\t19- Get index of last occurence of substring in the MyString object.";
	cout << "\n\t20- Get index of last occurence of character in the MyString object.";
	cout << "\n\n\n";
}



