#include "Library.h"

//Create Library and book List
Library::Library(bool run) : isRunning(run)
{
	bookList = { Book("Something", "idk", 1990), Book("Another", "Not sure", 2000), Book("Test", "Not sure", 2000) };
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

	for (unsigned int i = 0; i < bookList.size(); i++)
	{
		bookList[i].printBook();
	}

}

//Student can check out book
void Library::bookCheckout()
{
	
		string tempBookTitle;
		std::cout << "Enter book to check out \n " << std::endl;
		std::cin >> tempBookTitle;

		for (unsigned int i = 0; i < bookList.size(); i++)
		{

			if (tempBookTitle == bookList[i].getTitle())
			{
				char input;
				std::cout << "Confirm book checkout Y/N? \n" << std::endl;
				std::cin >> input;

				if (input == 'y')
				{
					//TODO Remove book from list
					bookList.erase(std::remove(bookList.begin(), bookList.end(), bookList[i]), bookList.end());
					std::cout << "Book Checked out." << std::endl;
					break;

				}
				else if (input == 'n')
				{
					std::cout << "Book checkout canceled.  Return to main menu." << std::endl;
				}

			}
			else
			{
				std::cout << "Book not available." << std::endl;
				break;
			}
		}

}

//Student can return book
void Library::bookReturn()
{

	string name = "N/a";
	std::cout << "Enter book to return \n" << std::endl;
	std::cin >> name;

	string type = "n/a";
	std::cout << "Type in book type: \n" << std::endl;
	std::cin >> type;

	int year = 0;
	std::cout << "Type in book year: \n" << std::endl;
	std::cin >> year;

	Book book2(name, type, year);
	bookList.push_back(book2);

	std::cout << book2.getTitle() << " " << "Book has been returned;" << std::endl;

}

//librarian or student can show available books
void Library::showBookList()
{
	std::cout << "Books that are available: \n" << std::endl;
	for (unsigned int i = 0; i < bookList.size(); i++)
	{
		bookList[i].printBook();
		std::cout << "\n";
	}
}

//Show the Menu for the Librarian
bool Library::showMenuL()
{
	std::cout << "\n";
	std::cout << " \nPlease choose an option" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << " 1. Book Checkout \n 2. Book Return \n 3. List available books \n 4. Add Book \n 5. Logout \n 6. Quit program" << std::endl;
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
		Menu::showMainMenu();
	}
	else if (choice == 6)
	{
		return isRunning = false;
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



bool Library::is_running()
{
	return isRunning;
}
