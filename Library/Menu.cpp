#include "Menu.h"

Library lib = Library(true);


//void centerString(char* s)
//{
//	int l = strlen(s);
//	int pos = (int)((80 - l) / 2);
//	for (int i = 0;i < pos;i++)
//	{
//		std::cout << " ";
//		std::cout << s;
//	}
//}


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

		if (tempPassword == password)
		{
			while (lib.is_running() != false)
			{
				lib.showMenuL();
			}
		}
	}
	else if (input == 1)
	{
		string login;
		std::cout << "Enter Login name: " << std::endl;
		std::cin >> login;

		int password;
		int tempPassword = 123;
		std::cout << "Enter password: " << std::endl;
		std::cin >> password;

		if (password == tempPassword)
		{
			while (lib.is_running() != false)
			{
				lib.showMenuS();
			}
		}
	}
}

