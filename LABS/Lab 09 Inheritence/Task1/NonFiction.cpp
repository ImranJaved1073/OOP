#include "NonFiction.h"
#include "Novel.h"
#include <iostream>
using namespace std;

NonFiction::NonFiction()
{
	inspiration = "";
}
NonFiction::NonFiction(string t, string a, int p, string i) : Novel(t, a, p)
{
	inspiration = i;
}
void NonFiction::showDetails() const
{
	cout << "Title: " << getTitle() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Pages: " << getPages() << endl;
	cout << "Inspiration: " << inspiration << endl;
}
NonFiction NonFiction::setData(string t, string a, int p, string i)
{
	NonFiction n;
	n.setTitle(t);
	n.setAuthor(a);
	n.setPages(p);
	n.inspiration = i;
	return n;
}