#ifndef NOVEL_H
#define NOVEL_H
#include<string>
using namespace std;
class Novel
{
private:
	string title;
	string author;
	int pages;
public:
	Novel();
	Novel(string , string , int );
	void showDetails() const;
	void setTitle(string t);
	void setAuthor(string a);
	void setPages(int p);
	string getTitle() const;
	string getAuthor() const;
	int getPages() const;
};


#endif // !NOVEL_H


