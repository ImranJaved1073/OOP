
#include <iostream>
#include<string>
using namespace std;
struct feetInches
{
	int feet;
	int inches;
};
struct roomDimension
{
	feetInches length;
	feetInches width;
};
double computeCarpetingCost(const roomDimension* arr, int num)
{
	double area = (arr[num].length.feet + (arr[num].length.inches) / 12) * (arr[num].width.feet + (arr[num].width.inches) / 12);
	double cost = area * 18;
	return cost;
}
int main()
{
	int rooms;
	cout << "How many rooms do you have in your house?";
	cin >> rooms;
	roomDimension* arr = new roomDimension[rooms];
	for (int i = 0; i < rooms; i++)
	{
		cout << "Enter length of room " << i + 1 << " in feet:";
		cin >> arr[i].length.feet;
		cout << "Enter length of room " << i + 1 << " in inches:";
		cin >> arr[i].length.inches;
		cout << "Enter width of room " << i + 1 << " in feet:";
		cin >> arr[i].width.feet;
		cout << "Enter width of room " << i + 1 << " in inches:";
		cin >> arr[i].width.inches;
	}
	double* roomCost = new double[rooms];
	for (int i = 0; i < rooms; i++)
	{
		roomCost[i] = computeCarpetingCost(arr, i);
	}
	int houseCost = 0;
	for (int i = 0; i < rooms; i++)
	{
		houseCost += roomCost[i];
	}
	char choice;
	cout << "Press R if you want to see the carpeting cost for a room" << endl 
		<< " & press H if you want to see the cost for the whole house:" << endl;
	cin >> choice;
	while (choice != 'R' && choice != 'r' && choice != 'H' && choice != 'h')
	{
		cout << "Invalid Choice!\n";
		cout << "Press R if you want to see the carpeting cost for a room" << endl
			<< " & press H if you want to see the cost for the whole house:" << endl;
		cin >> choice;

	}
	if (choice == 'R' || choice == 'r')
	{
		int i;
		cout << "Which room's cost do you want to see?";
		cin >> i;
		while (i > rooms)
		{
			cout << "You have enter room out of range.Enter again!\n";
			cin >> i;
		}
		cout << roomCost[i - 1] << endl;
	}
	else if (choice == 'H' || choice == 'h')
	{
		cout << houseCost << endl;
	}
}
