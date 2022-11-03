#ifndef NONFICTION_H
#define NONFICTION_H
#include "Novel.h"
#include<string>
using namespace std;


class NonFiction :public Novel
{
	string inspiration;
public:
	NonFiction();
	NonFiction(string, string, int, string);
	void showDetails() const;
	NonFiction setData(string , string , int , string );
};



#endif // !NOVEL_H
