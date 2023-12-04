/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: ChildrenBook.cpp for Project #2
**/
#include "ChildrenBook.h"

// Calls parent default constructor
// Sets private member variable age to 0
ChildrenBook::ChildrenBook() : Book(), age(0) 
{

}

// Calls parent constructor with 4 arguments
// Sets private member variable age to given age
ChildrenBook::ChildrenBook(int code, std::string title, int available, int rented, int age) : 
	Book(code, title, available, rented), age(age)
{

}


void ChildrenBook::setAge(int age)
{
	// Sets private member variable age to given age
	this->age = age;
}

int ChildrenBook::getAge() const
{
	// Return value of private member variable age 
	return age;
}

void ChildrenBook::displaySearchedInfo() const
{
	// Output category to terminal
	std::cout << "category : " << "children" << std::endl;
	// Output value of private member variable age to terminal
	std::cout << "age : " << getAge() << std::endl;
	// Output value of private member variables available and rented to terminal
	std::cout << getAvailable() << " available, " << getRented() << " rented" << std::endl;
}

int ChildrenBook::getIdentification() const
{
	// Return the value of inherited private member variable code
	return getCode();
}

void ChildrenBook::markRented()
{
	// Decrease value of private member variable by 1 
	setAvailable(getAvailable() - 1);
	// Increase value of private member variable by 1
	setRented(getRented() + 1);
}

void ChildrenBook::markReturned()
{
	// Increase value of private member variable by 1 
	setAvailable(getAvailable() + 1);
	// Decrease value of private member variable by 1
	setRented(getRented() - 1);
}

void ChildrenBook::displayInfoForPerson() const
{
	// Output value of private member variable title, code, and age formatted to terminal
	std::cout << "* " << getTitle() << "(" << getCode() << ")" 
		<< " - " << " age " << getAge() <<  std::endl;
}

void ChildrenBook::displayAllInfo() const
{
	// Outout values of private member variables code, title with no underscore, age, available, and rented
	std::cout << " " << getCode() << std::setw(30) << get_formatted_title() 
		<< std::setw(4) << getAge() << std::setw(10) << getAvailable() 
		<< std::setw(7) << getRented() << std::endl;
}

std::string ChildrenBook::get_formatted_title() const
{
	// Declare and initialize string variable to the value if private member variable title
	std::string title = getTitle();
	// Replace the underscores in title with spaces
	std::replace(title.begin(), title.end(), '_', ' ');
	// Return the title
	return title;
}
