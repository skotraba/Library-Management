#include "Book.h"
#include "Library.h"

Book::Book(string name, string type, int year)
{
	m_bookTitle = name;
	m_bookType = type;
	m_year = year;
}

string Book::getType()
{
	return m_bookType;
}

void Book::setType(string type)
{
	m_bookType = type;
}

string Book::getTitle()
{
	return m_bookTitle;
}

void Book::setTitle(string title)
{
	m_bookTitle = title;
}

int Book::getYear()
{
	return m_year;
}

void Book::setYear(int year)
{
	m_year = year;
}

void Book::printBook()
{
	std::cout << "Title: " << m_bookTitle << "\n" << "Type: " << m_bookType <<
		"\n" << "Year: " << m_year << "\n";
}

bool Book::operator==(Book b2)
{
	return (this->m_bookTitle.compare(b2.m_bookTitle) == 0 && this->m_bookType.compare(b2.m_bookType) == 0
		&& this->m_year == b2.m_year);
}