/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Book.cpp for Project #2
**/
#include "Book.h"

// Sets private member variable to 0
// Sets private member variable title to empty string
// Sets private member variable available to 0
// Sets private member variable rented to 0
Book::Book() : 
	code(0), title(""), available(0), rented(0)
{

}

// Sets private member variable code to given code
// Sets private member variable title to given title
// Sets private member variable available to given available
// Sets private member varaible rented to given rented
Book::Book(int code, std::string title, int available, int rented) :
	code(code), title(title), available(available), rented(rented)
{

}

void Book::setCode(int code)
{
	// Sets private member variable code to given code
	this->code = code;
}

void Book::setTitle(std::string title)
{
	// Sets private member variable title to given title
	this->title = title;
}

void Book::setAvailable(int available)
{
	// Sets private member variable available to given available
	this->available = available;
}

void Book::setRented(int rented)
{
	// Sets private member variable rented to given rented
	this->rented = rented;
}

int Book::getCode() const
{
	// Return value of private member variable code
	return code;
}

std::string Book::getTitle() const
{
	// Return value of private member variable title
	return title;
}

int Book::getAvailable() const
{
	// Return value of private member variable available
	return available;
}

int Book::getRented() const
{
	// Return value of private member variable rented
	return rented;
}