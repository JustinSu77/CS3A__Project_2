#include "Book.h"

Book::Book() : 
	code(0), title(""), available(0), rented(0)
{

}

Book::Book(int code, std::string title, int available, int rented) :
	code(code), title(title), available(available), rented(rented)
{

}

void Book::setCode(int code)
{
	this->code = code;
}

void Book::setTitle(std::string title)
{
	this->title = title;
}

void Book::setAvailable(int available)
{
	this->available = available;
}

void Book::setRented(int rented)
{
	this->rented = rented;
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

 