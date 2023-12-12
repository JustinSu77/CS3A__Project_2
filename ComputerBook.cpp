/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: ComputerBook.h for Project #2
**/
#include "ComputerBook.h"

// Calls parent default constructor
// Sets private member variable publisher to empty string
ComputerBook::ComputerBook() : Book(), publisher("")
{

}

// Calls parent constructor with 5 arguments
// Sets private member variable publisher to given publisher
ComputerBook::ComputerBook(int code, std::string title, int available, int rented, std::string publisher) : 
	Book(code, title, available, rented), publisher(publisher)
{

}

void ComputerBook::setPublisher(std::string publisher)
{
	// Sets value of private member variable publisher to given publisher
	this->publisher = publisher;
}

std::string ComputerBook::getPublisher() const
{
	// Return value of private member variable publisher
	return publisher;
}

void ComputerBook::displaySearchedInfo() const
{
	// Output category
	std::cout << " category : " << "computer" << std::endl;
	// Output value of private member variable publisher
	std::cout << " publisher : " << getPublisher() << std::endl;
	// Output the value of private member variables available and rented
	std::cout << " " << getAvailable() << " available, " << getRented() << " rented" << std::endl;
}

int ComputerBook::getIdentification() const
{
	// Return value of inherited private member variable code
	return getCode();
}

void ComputerBook::markRented()
{
	// Decrease value of inherited private member variable available by 1
	setAvailable(getAvailable() - 1);
	// Increase value of inherited private member variable rented by 1
	setRented(getRented() + 1);
}

void ComputerBook::markReturned()
{
	// Increase value of inherited private member variable available by 1
	setAvailable(getAvailable() + 1);
	// Decrease value of inherited private member variable rented by 1
	setRented(getRented() - 1);
}

void ComputerBook::displayInfoForPerson() const
{
	// Output values of private member variable title, code, 
	// and publisher neatly formatted to terminal
	std::cout << "* " << getTitle() << "(" << getCode() << ")" << " - " 
		<< " publisher  " << getPublisher() << std::endl;
}

void ComputerBook::displayAllInfo() const
{
	// Output values of private member variable code, title with no underscore, 
	// publisher, available, and rented neatly formatted to terminal
	std::cout << " " << getCode() << std::setw(30) << get_formatted_title() 
		<< std::setw(20) << getPublisher() << std::setw(7) << getAvailable() 
		<< std::setw(7) << getRented() << std::endl;
}

std::string ComputerBook::get_formatted_title() const
{
	// Declare and initialize string variable to 
	// store value of private member variable title
	std::string title = getTitle();
	// Replace the underscores with spaces in title variable
	std::replace(title.begin(), title.end(), '_', ' ');
	// Return the title
	return title;
}
