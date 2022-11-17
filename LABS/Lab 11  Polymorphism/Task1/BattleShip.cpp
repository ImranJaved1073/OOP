#include "BattleShip.h"
#include <iostream>
#include <string>
using namespace std;

BattleShip::BattleShip()
{
	totalNumOfMissiles = 0;
}

BattleShip::BattleShip(int no, string n, string y) : Ship(n, y) 
{
	totalNumOfMissiles = no;
}

int BattleShip::getTotalMissiles() 
{
	return totalNumOfMissiles;
}

void BattleShip::setMissiles(int m) 
{
	totalNumOfMissiles = m;
}

void BattleShip::print() 
{
	cout << "Name of Ship: " << getName() << endl;
	cout << "Year Ship was made: " << getYear() << endl;
	cout << "Total Number of Missiles ship has: " << totalNumOfMissiles << endl;
}

BattleShip::~BattleShip()
{
	cout << "\nBattle Ship destructor" << endl;
}