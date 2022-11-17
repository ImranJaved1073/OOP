#include <iostream>
#include <string>
#include "Ship.h"
using namespace std;

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class BattleShip : public Ship 
{
private:
	int totalNumOfMissiles;

public:
	BattleShip();
	BattleShip(int, string, string);
	int getTotalMissiles();
	void setMissiles(int);
	void print();
	~BattleShip();
};

#endif // !BATTLESHIP_H


