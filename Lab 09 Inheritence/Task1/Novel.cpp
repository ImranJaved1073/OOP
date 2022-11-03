#include "Novel.h"
#include <iostream>
using namespace std;


Novel::Novel()
{
	title = "";
	author = "";
	pages = 0;
}

Novel::Novel(string t, string a, int p)
{
	title = t;
	author = a;
	pages = p;
}

void Novel::setTitle(string t)
{
	title = t;
}

void Novel::setAuthor(string a)
{
	author = a;
}
void Novel::setPages(int p)
{
	pages = p;
}
string Novel::getTitle() const
{
	return title;
}
string Novel::getAuthor() const
{
	return author;
}
int Novel::getPages() const
{
	return pages;
}

void Novel::showDetails() const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Pages: " << pages << endl;
}