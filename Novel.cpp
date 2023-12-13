/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Novel.cpp for Project #2
**/
#include "Novel.h"

// Call default constructor of parent class to set inherited 
// private member variables to default values
// Set private member variable publish_date to 0
Novel::Novel() : Book(), publish_date(0)
{

}

// Calls constructor with 4 arguments of parent class to set inherited 
// private member variables to given corresponding values
// Set private member variable publish_date to given publish_date 
Novel::Novel(int code, std::string title, int available, int rented, int publish_date)
	: Book(code, title, available, rented), publish_date(publish_date)
{

}

void Novel::set_publish_date(int publish_date)
{
	// Set private member variable publish_date to given publish_date
	this->publish_date = publish_date;
}

int Novel::get_publish_date() const
{
	// Return value of private member variable publish_date
	return publish_date;
}

void Novel::displaySearchedInfo() const
{
	// Output the category of Novel to terminal
	std::cout << " category : " << "novel" << std::endl;
	// Outout the value of private member variable publish_date to terminal
	std::cout << " publish date : " << get_publish_date() << std::endl;
	// Output values of inherited private member variables available and rented to terminal 
	std::cout << " " << getAvailable() << " available, " << getRented() << " rented" << std::endl;
}

int Novel::getIdentification() const
{
	// Return the value of inherited private member variable code
	return getCode();
}

void Novel::markRented()
{
	// Decrease value of inherited private member variable available  by 1
	setAvailable(getAvailable() - 1);
	// Increase value of inherited private member variable rented by 1
	setRented(getRented() + 1);
}

void Novel::markReturned()
{
	// Increase value of inherited private member variable available by 1
	setAvailable(getAvailable() + 1);
	// Decrease value of inherited private member variable rented by 1
	setRented(getRented() - 1);
}

void Novel::displayInfoForPerson() const
{
	// Output the values of inherited private member variables title 
	// and code and value of private member variable publish_date formatted to terminal
	std::cout << " * " << getTitle() << "(" << getCode() << ")" 
		<< " - " << " publish date " << get_publish_date() << std::endl;
}

void Novel::displayAllInfo() const
{
	// Output the values of inherited private member variables code, 
	// title with no underscore, publish_date, available and rented 
	// formatted to terminal
	std::cout << " " << getCode() << std::setw(25) 
		<< get_formatted_title() << std::setw(12) 
		<< get_publish_date() << std::setw(15) 
		<< getAvailable() << std::setw(8) << getRented() << std::endl;
}

std::string Novel::get_formatted_title() const
{
	// Declare and initailize string variable to value of 
	// inherited private member variable title
	std::string title = getTitle();
	// Replace the underscores in title to space
	std::replace(title.begin(), title.end(), '_', ' ');
	// Return value of title
	return title;
}
