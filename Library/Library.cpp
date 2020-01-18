#include "Library.h"
#include "Menu.h"

//Create Library and book List
Library::Library(bool run) : isRunning(run)
{
}

//librarian Can Add book to library
void Library::addBook()
{
	string name = "N/a";
	std::cout << "Type in book name: \n" << std::endl;
	std::cin >> name;

	string type = "n/a";
	std::cout << "Type in book type: \n" << std::endl;
	std::cin >> type;

	int year = 0;
	std::cout << "Type in book year: \n" << std::endl;
	std::cin >> year;

	Book book2(name, type, year);
	bookList.push_back(book2);

	// adds book to the master booklist file
	std::ofstream bookFile("Books\\Booklist.txt", std::ios::app);
	if (bookFile.is_open())
	{
		bookFile << std::endl << book2.getTitle() << " " << book2.getType() << " " << book2.getYear();
	}
	else
	{
		std::cout << "Text file error";
	}

	bookFile.close();

	// adds book to the available booklist file
	std::ofstream bookUpdateFile("Books\\Booklistavailable.txt", std::ios::app);
	if (bookUpdateFile.is_open())
	{
		bookUpdateFile << std::endl << book2.getTitle() << " " << book2.getType() << " " << book2.getYear();
	}
	else
	{
		std::cout << "Text file error";
	}

	bookUpdateFile.close();
}

//Student can check out book
void Library::bookCheckout()
{
	string tempTitle;
	std::cout << "Enter Title: " << std::endl; std::cin >> tempTitle;

	string tempType;
	std::cout << "Enter type: " << std::endl; std::cin >> tempType;

	int tempYear;
	std::cout << "Enter year: " << std::endl; std::cin >> tempYear;

	Book tempBook = Book(tempTitle, tempType, tempYear);

	std::ifstream bookFile("Books\\Booklistavailable.txt", std::ios::app);

	if (bookFile.is_open())
	{
		string title, type;
		int year = 0;
		while (bookFile >> title >> type >> year)
		{
			Book book3(title, type, year);

			if (book3 == tempBook) 
			{
				char choice;
				std::cout << "Would you like to check out " << title << " Y/N ?" << std::endl;
				std::cin >> choice;

				if (choice == 'y')
				{
					tempCheckOut.push_back(book3);
				}
			}
			// store all books except for the one we're removing in the booklist
			else 
			{
				bookList.push_back(book3);
			}
		}
	}
	else
	{
		std::cout << "File did not open";
	}

	bookFile.close();

	// Removes the book from the available booklist file
	// rewrites the file with the new available books
	std::ofstream updateBookFile("Books\\Booklistavailable.txt");
	if (updateBookFile.is_open())
	{
		for (auto i = 0; i < bookList.size(); i++)
		{
			updateBookFile << bookList[i].getTitle() << " " << bookList[i].getType() << " " << bookList[i].getYear() << std::endl;
		}
	}
	else
	{
		std::cout << "Book list available did not open";
	}

	// Updates the checked out books file
	std::ofstream updateCheckedOut("Books\\Booklistcheckedout.txt", std::ios::app);
	if (updateCheckedOut.is_open())
	{
		for (auto i = 0; i < tempCheckOut.size(); i++)
		{
			updateCheckedOut << tempCheckOut[i].getTitle() << " " << tempCheckOut[i].getType() << " " << tempCheckOut[i].getYear() << std::endl;
		}
	}
	else
	{
		std::cout << "Book list available did not open";
	}

	bookList = {};
	tempCheckOut = {};
}

//Student can return book
//TODO Need to implement to text file
void Library::bookReturn()
{

	string tempTitle;
	std::cout << "Enter Title: " << std::endl; std::cin >> tempTitle;

	string tempType;
	std::cout << "Enter type: " << std::endl; std::cin >> tempType;

	int tempYear;
	std::cout << "Enter year: " << std::endl; std::cin >> tempYear;

	Book tempBook = Book(tempTitle, tempType, tempYear);

	std::ifstream bookFile("Books\\Booklistcheckedout.txt", std::ios::app);

	if (bookFile.is_open())
	{
		string title, type;
		int year = 0;
		while (bookFile >> title >> type >> year)
		{
			Book book3(title, type, year);

			if (book3 == tempBook)
			{
				char choice;
				std::cout << "Would you like to return " << title << " Y/N ?" << std::endl;
				std::cin >> choice;

				if (choice == 'y')
				{
					tempCheckOut.push_back(bookList[i]);

				}

			}
			// store all books except for the one we're removing in the booklist
			else
			{
				bookList.push_back(book3);
			}
		}
	}
	else
	{
		std::cout << "File did not open";
	}

	bookFile.close();

	std::ofstream updateBookFile("Books\\Booklistcheckedout.txt");
	if (updateBookFile.is_open())
	{
		for (auto i = 0; i < bookList.size(); i++)
		{
			updateBookFile << bookList[i].getTitle() << " " << bookList[i].getType() << " " << bookList[i].getYear() << std::endl;
		}
	}
	else
	{
		std::cout << "Book list available did not open";
	}

	std::ofstream updateCheckedOut("Books\\Booklistavailable.txt", std::ios::app);
	if (updateCheckedOut.is_open())
	{
		for (auto i = 0; i < tempCheckOut.size(); i++)
		{
			updateCheckedOut << tempCheckOut[i].getTitle() << " " << tempCheckOut[i].getType() << " " << tempCheckOut[i].getYear() << std::endl;
		}
	}
	else
	{
		std::cout << "Book list available did not open";
	}
	bookList = {};
	tempCheckOut = {};

}

//librarian or student can show available books
void Library::showBookList()
{

	std::ifstream myReadFile("Books\\Booklistavailable.txt");
	string title, type;
	int year;
	while (myReadFile >> title >> type >> year)
	{
		std::cout << "Title: " << title << std::endl << "Type: " << type << std::endl
			<< "Year: " << year << "\n" << std::endl;
	}

	myReadFile.close();

}


//Show books that are Currently not available
void Library::showCheckedOutList()
{

	std::ifstream myReadFile("Books\\Booklistcheckedout.txt");
	string title, type;
	int year;
	while (myReadFile >> title >> type >> year)
	{
		std::cout << "Title: " << title << std::endl << "Type: " << type << std::endl
			<< "Year: " << year << "\n" << std::endl;
	}

	myReadFile.close();

}

//Show the Menu for the Librarian
bool Library::showMenuL()
{
	std::cout << "\n";
	std::cout << " \nPlease choose an option" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << " 1. Book Checkout \n 2. Book Return \n 3. List available books \n 4. Add Book \n 5. Show Unavailable Books \n 6. Logout \n 7. Quit program" << std::endl;
	std::cout << "Enter number or other character to quit: \n " << std::endl;
	int choice = 0;
	std::cin >> choice;

	if (choice == 1)
	{
		bookCheckout();
	}
	else if (choice == 2)
	{
		bookReturn();
	}
	else if (choice == 3)
	{
		showBookList();
	}
	else if (choice == 4)
	{
		addBook();
	}
	else if (choice == 5)
	{
		showCheckedOutList();
	}
	else if (choice == 6)
	{
		Menu::showMainMenu();
	}
	else
	{
		return isRunning = false;
	}
}

//Show the Menu for the student, omit the add book to library function
bool Library::showMenuS()
{
	std::cout << "\n";
	std::cout << "Please choose an option" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << " 1. Book Checkout \n 2. Book Return \n 3. List available books \n 4. Logout \n 5. Quit Program" << std::endl;
	std::cout << "Enter number or other character to quit: \n " << std::endl;
	int choice = 0;
	std::cin >> choice;

	if (choice == 1)
	{
		bookCheckout();
	}
	else if (choice == 2)
	{
		bookReturn();
	}
	else if (choice == 3)
	{
		showBookList();
	}
	else if (choice == 4)
	{
		Menu::showMainMenu();
	}
	else if (choice == 5)
	{
		return isRunning = false;
	}
	else
	{
		return isRunning = false;
	}
}

//Keeps the program running
bool Library::is_running()
{
	return isRunning;
}
