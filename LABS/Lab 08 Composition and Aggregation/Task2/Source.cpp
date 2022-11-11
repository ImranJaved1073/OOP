#include "Location.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main()
{
	Player player;
	int x, y;
	cout << "ENTER X-CORDINATE OF PLAYER : ";
	cin >> x;
	player.obj.setX(x);

	cout << "ENTER Y-CORDINATE OF PLAYER : ";
	cin >> y;
	player.obj.setY(y);

	cout << "LOCATION OF PLAYER IS : \n" << "X-CORDINATE : " << player.obj.ShowX() << endl << "Y-CORDINATE : " << player.obj.ShowY();
}