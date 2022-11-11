#ifndef FICTION_H
#define FICTION_H
#include<string>
#include "Novel.h"
using namespace std;
class Fiction :public Novel
{
	int level;
	string type;
public:
	Fiction();
	Fiction(string, string, int, int, string);
	void showDetails() const;
	void setLevel(int l);
	void setType(string t);
	int getLevel() const;
	string getType() const;
};


#endif // !NOVEL_H

