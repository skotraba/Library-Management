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
	//Constructor
	Book(string name, string type, int year);

	//Methods
	string getType();
	void setType(string type);
	string getTitle();
	void setTitle(string title);
	int getYear();
	void setYear(int year);
	void printBook();
	bool operator==(Book b2);
	
private:
	//Variables
	string m_bookType;
	string m_bookTitle;
	int m_year;

};

#endif BOOK_H

