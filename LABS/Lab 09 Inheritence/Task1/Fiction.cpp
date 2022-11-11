#include "Fiction.h"
#include "Novel.h"
#include <iostream>
using namespace std;


Fiction::Fiction()
{
	level = 0;
	type = "";
}

Fiction::Fiction(string t, string a, int p, int l, string ty) : Novel(t, a, p)
{
	level = l;
	type = ty;
}

void Fiction::showDetails() const
{
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Pages: " << getPages() << endl;
	cout << "Level: " << level << endl;
	cout << "Type: " << type << endl;
}

void Fiction::setLevel(int l)
{
	level = l;
}

void Fiction::setType(string t)
{
	type = t;
}

int Fiction::getLevel() const
{
	return level;
}

string Fiction::getType() const
{
	return type;
}