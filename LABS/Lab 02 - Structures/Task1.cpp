#include <iostream>
#include <string>
using namespace std;
struct MovieData
{
	string title, director;
	int yearReleased=0,runningTime=0;
};
void getInput(MovieData&);
void displayData(MovieData);
int main()
{
	MovieData movie1, movie2;
	cout << "Movie 1 Data:\n";
	getInput(movie1);
	displayData(movie1);
	cout << "Movie 2 Data:\n";
	getInput(movie2);
	displayData(movie2);
}

void getInput(MovieData & m1)
{
	cout << "\nEnter the name of the movie:";
	cin.ignore();
	getline(cin, m1.title);
	cout << "Enter the name of director of the movie:";
	cin.ignore();
	getline(cin, m1.director);
	cout << "Enter released year:";
	cin >> m1.yearReleased;
	while (m1.yearReleased>2022)
	{
		cout << "ERROR!Enter a valid data.Year cannot be greater than 2022.\n";
		cout << "Enter released year again:";
		cin >> m1.yearReleased;
	}
	cout << "Enter time duration of the movie(in minutes):";
	cin >> m1.runningTime;
	while (m1.runningTime <= 25 || m1.runningTime >= 500)
	{
		cout << "ERROR!Enter a valid data in range of 25 to 500 min.\n";
		cout << "Enter time duration of the movie(in minutes):";
		cin >> m1.runningTime;
	}
}

void displayData(MovieData m1)
{
	cout << "\n\nThe name of the movie is:	" << m1.title << endl;
	cout << "\nThe name of director of the movie is:	" << m1.director << endl;
	cout << "\nReleased in year:	" << m1.yearReleased << endl;
	cout << "\nThe time duration of the movie is:	" << m1.runningTime << "minutes." << endl << endl;
}


