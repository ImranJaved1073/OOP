#include "Fiction.h"
#include "Novel.h"
#include "NonFiction.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	cout << "Which Functionality you want to use?";
	cout << "1. Fiction";
	cout << "2. NonFiction";
	cout << "3. Novel";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		Fiction f("Spiderman", "Human", 50, 1, "Scific");
		f.showDetails();
	}
	else if (choice == 2)
	{
		NonFiction n;
		n=n.setData("Unknown", "XYZ.", 22, "Horror");
		n.showDetails();
	}
	else if (choice == 3)
	{
		Novel n("Unknown", "XYZ.", 22);
		n.showDetails();
	}
	else
	{
		cout << "Invalid Choice";
	}

	//NonFiction n;
	//Fiction f;
	//n = n.setData("Avengers", "ABC", 197, "XYZ");;
	//n.showDetails();
	//f.showDetails();
	return 0;
}