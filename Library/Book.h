#ifndef BOOK_H
#define BOOK_H
#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::vector;
using std::string;

class Book
{
public:
	Book(string name, string type, int year);

	string getType();
	void setType(string type);
	string getTitle();
	void setTitle(string title);
	int getYear();
	void setYear(int year);

	void printBook();
	bool operator==(Book b2);

	string m_bookType;
	string m_bookTitle;
	int m_year;
	

private:


};

#endif BOOK_H

