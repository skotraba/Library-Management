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
	
};

#endif //LIBRARY_H

