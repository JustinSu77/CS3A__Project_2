#include "Book.h"

Book::Book() : 
	code(0), title(""), available(0), rented(0)
{

}

Book::Book(int newCode, std::string newTitle, int newAvailable, int newRented) :
	code(newCode), title(newTitle), available(newAvailable), rented(newRented)
{

}

void Book::setCode(int newCode)
{
	code = newCode;
}

void Book::setTitle(std::string newTitle)
{
	title = newTitle;
}

void Book::setAvailable(int newAvailable)
{
	available = newAvailable;
}

void Book::setRented(int newRented)
{
	rented = newRented;
}

int Book::getCode() const
{
	return code;
}

std::string Book::getTitle() const
{
	return title;
}

int Book::getAvailable() const
{
	return available;
}

int Book::getRented() const
{
	return rented;
}

 