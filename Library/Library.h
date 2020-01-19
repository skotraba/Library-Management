#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Menu.h"
#include <algorithm>


class Library
{
public:
	//Constructor
	Library(bool run);

	//Methods
	void addBook();
	void bookCheckout();
	void bookReturn();
	void showBookList();
	bool showMenuL();
	bool showMenuS();
	void showCheckedOutList();
	bool is_running();

private:
	//Variables
	bool isRunning = true;
	
	//Methods
	void writeToFile(vector<Book> vec, bool checkOut, string fileName, bool append);
	void writeBookToFile(Book b, string fileName, bool append);

};

#endif //LIBRARY_H

