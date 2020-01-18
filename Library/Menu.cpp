#include "Menu.h"

Library lib = Library(true);


bool Menu::isLoggedIn()
{
	std::string username, password, un, pw;

	std::cout << "\n";
	std::cout << "Enter username: "; std::cin >> username;
	std::cout << "Enter password: "; std::cin >> password;

	std::ifstream read("Logins\\" + username + ".txt");
	std::getline(read, un);
	std::getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Menu::showMainMenu()
{

	std::cout << "Welcome to Library Management System \t" << std::endl;
	std::cout << "-------------------------------------- " << std::endl;

	int input;
	std::cout << "Are you a student or a librarian? \n" << std::endl;
	std::cout << "1. Student \n2. Librarian" << std::endl;
	std::cin >> input;

	if (input == 2)
	{
		int password = 1234;
		int tempPassword;
		std::cout << "Enter admin password: " << std::endl;
		std::cin >> tempPassword;
		std::cin.ignore();

		if (tempPassword == password)
		{
			while (lib.is_running() != false)
			{
				lib.showMenuL();
			}
		}
		else
		{
			std::cout << "Wrong password." << std::endl;
			showMainMenu();
		}
	}
	else if (input == 1)
	{
		int choice = 0;


		std::cout << "1. Register \n2. Login \n" << std::endl;
		std::cin >> choice;

		if (choice == 1)
		{
			std::string username, password;

			std::cout << "Select a username: "; std::cin >> username;
			std::cout << "Select a password: "; std::cin >> password;

			std::ofstream file;
			file.open("Logins\\" + username + ".txt");
			file << username << std::endl << password;
			file.close();

			showMainMenu();

		}
		else if (choice == 2)
		{
			bool status = isLoggedIn();

			if (!status)
			{
				std::cout << "False login." << std::endl;
				showMainMenu();
			}
			else
			{
				std::cout << "Successfully logged in";
				while (lib.is_running() != false)
				{
					lib.showMenuS();
				}

			}
		}

	}
}

