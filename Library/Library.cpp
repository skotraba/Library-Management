#include "Library.h"
#include "Menu.h"
#include <string>
#include <sstream>

//Create Library and book List
Library::Library(bool run) : isRunning(run)
{
}

//librarian Can Add book to library
void Library::addBook()
{
	string name = "N/a";
	std::cout << "Type in book name: " << std::endl;
	std::getline(std::cin, name);

	string type = "n/a";
	std::cout << "Type in book type: \n" << std::endl;
	std::getline(std::cin, type);

	int year = 0;
	std::cout << "Type in book year: \n" << std::endl;
	std::cin >> year;
	std::cin.ignore();

	char c = ',';
	Book book2(name, type, year);

	// adds book to the master booklist file
	writeBookToFile(book2, "Booklist", true);

	// adds book to the available booklist file
	writeBookToFile(book2, "Booklistavailable", true);
}

//Librarian can check out book
void Library::bookCheckout()
{
	vector<Book> bookList;
	vector<Book> tempCheckOut;

	string tempTitle;
	std::cout << "Enter Title: " << std::endl; 
	std::getline(std::cin, tempTitle);

	string tempType;
	std::cout << "Enter type: " << std::endl; 
	std::getline(std::cin, tempType);

	int tempYear;
	std::cout << "Enter year: " << std::endl; 
	std::cin >> tempYear;

	Book tempBook = Book(tempTitle, tempType, tempYear);

	std::ifstream bookFile("Books\\Booklistavailable.txt", std::ios::app);

	if (bookFile.is_open())
	{
		string title, type, tmpYear;
		int year = 0;

		string line;

		// read a line of the file
		while (getline(bookFile, line)) {
			std::stringstream ss(line);
			getline(ss, title, ',');
			getline(ss, type, ',');
			getline(ss, tmpYear, ',');

			year = std::stoi(tmpYear);

			Book b = Book(title, type, year);

			if (b == tempBook)
			{

				char choice;
				std::cout << "Would you like to check out " << title << " Y/N ?" << std::endl;
				std::cin >> choice;

				if (choice == 'y')
				{
					tempCheckOut.push_back(b);
				}
			}
			// store all books except for the one we're removing in the booklist
			else
			{
				bookList.push_back(b);
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
	writeToFile(bookList, false, "Booklistavailable", false);

	// Updates the checked out books file
	writeToFile(tempCheckOut, true, "Booklistcheckedout", true);
	
}

//Librarian can return book
void Library::bookReturn()
{
	vector<Book> bookList;
	vector<Book> tempCheckOut;

	string tempTitle;
	std::cout << "Enter Title: " << std::endl; 
	std::getline(std::cin, tempTitle);

	string tempType;
	std::cout << "Enter type: " << std::endl; 
	std::getline(std::cin, tempType);

	int tempYear;
	std::cout << "Enter year: " << std::endl; 
	std::cin >> tempYear;

	Book tempBook = Book(tempTitle, tempType, tempYear);

	std::ifstream bookFile("Books\\Booklistcheckedout.txt", std::ios::app);

	if (bookFile.is_open())
	{
		string title, type, tmpYear;
		int year = 0;

		string line;

		// read a line of the file
		while (getline(bookFile, line)) {
			std::stringstream ss(line);
			getline(ss, title, ',');
			getline(ss, type, ',');
			getline(ss, tmpYear, ',');

			year = std::stoi(tmpYear);

			Book b = Book(title, type, year);

			if (b == tempBook)
			{
				char choice;
				std::cout << "Would you like to return " << title << " Y/N ?" << std::endl;
				std::cin >> choice;

				if (choice == 'y')
				{
					tempCheckOut.push_back(b);
				}
			}
			// store all books except for the one we're removing in the booklist
			else
			{
				bookList.push_back(b);
			}
		}
	}
	else
	{
		std::cout << "File did not open";
	}

	bookFile.close();

	if (bookList.empty())
	{
		std::ofstream bookFile("Books\\Booklistcheckedout.txt");
	}
	else
	{
		writeToFile(bookList, false, "Booklistcheckedout", false);
	}

	writeToFile(tempCheckOut, true, "Booklistavailable", true);

}

//librarian or student can show available books
void Library::showBookList()
{
	std::ifstream myReadFile("Books\\Booklistavailable.txt");
	string title, type, tmpYear;
	int year;
	string line;

	// read a line of the file
	while (getline(myReadFile, line)) {
		std::stringstream ss(line);
		getline(ss, title, ',');
		getline(ss, type, ',');
		getline(ss, tmpYear, ',');

		year = std::stoi(tmpYear);

		Book b = Book(title, type, year);
		b.printBook();
	}
	myReadFile.close();
}


//Show books that are Currently not available
void Library::showCheckedOutList()
{

	std::ifstream myReadFile("Books\\Booklistcheckedout.txt");
	string title, type, tmpYear;
	int year;
	string line;
	while (getline(myReadFile, line))
	{
		std::stringstream ss(line);
		getline(ss, title, ',');
		getline(ss, type, ',');
		getline(ss, tmpYear, ',');

		year = std::stoi(tmpYear);

		Book b = Book(title, type, year);
		b.printBook();

	}

	myReadFile.close();

}

//Show the Menu for the Librarian
bool Library::showMenuL()
{
	std::cout << "\n";
	std::cout << " \nPlease choose an option" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << " 1. Book Checkout \n 2. Book Return \n 3. List available books \n 4. Add Book \n 5. Show Unavailable Books \n 6. Logout \n 7. Q to Quit program" << std::endl;
	std::cout << "Enter number or other character to quit: \n " << std::endl;
	string choice;
	std::getline(std::cin, choice);

	if (choice == "1")
	{
		bookCheckout();
	}
	else if (choice == "2")
	{
		bookReturn();
	}
	else if (choice == "3")
	{
		showBookList();
	}
	else if (choice == "4")
	{
		addBook();
	}
	else if (choice == "5")
	{
		showCheckedOutList();
	}
	else if (choice == "6")
	{
		Menu::showMainMenu();
	}
	else if (choice == "7")
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
	string choice;
	std::getline(std::cin, choice);

	if (choice == "1")
	{
		bookCheckout();
	}
	else if (choice == "2")
	{
		bookReturn();
	}
	else if (choice == "3")
	{
		showBookList();
	}
	else if (choice == "4")
	{
		Menu::showMainMenu();
	}
	else if (choice == "5")
	{
		return isRunning = false;
	}
}

//Keeps the program running
bool Library::is_running()
{
	return isRunning;
}

void Library::writeToFile(vector<Book> vec, bool checkOut, string fileName, bool append) 
{
	
	for (auto i = 0; i < vec.size(); i++)
	{
		if (i > 0) 
		{
			append = true;
		}
		writeBookToFile(vec[i], fileName, append);
	}
}

void Library::writeBookToFile(Book b, string fileName, bool append)
{
	string filePath = "Books\\" + fileName + ".txt";
	std::ofstream file;
	if (append)
	{
		file.open(filePath, std::ios::app);
	}
	else
	{
		file.open(filePath);
	}
	if (file.is_open())
	{
		file << b.getTitle() << "," << b.getType() << "," << b.getYear() << std::endl;
	}
	else
	{
		std::cout << "Book list available did not open";
	}
	file.close();
}
