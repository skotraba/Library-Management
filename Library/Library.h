#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Menu.h"
#include <algorithm>


class Library
{
public:
	Library(bool run);
	void addBook();
	void bookCheckout();
	void bookReturn();
	void showBookList();
	bool showMenuL();
	bool showMenuS();
	void showCheckedOutList();
	

	bool is_running();
private:

	vector<Book> tempCheckOut;
	vector<Book> bookList;
	bool isRunning = true;
	
	void writeToFile(bool checkOut, string fileName, bool append);
	void writeBookToFile(Book b, string fileName, bool append);

};

#endif //LIBRARY_H

