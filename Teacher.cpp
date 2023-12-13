/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Teacher.cpp for Project #2
**/
#include "Teacher.h"

// Calls default constructor of parent class set inherited 
// private member variables to default values
Teacher::Teacher() : Person()
{
	// Set first element of private member variable code to -1
	code[0] = -1;
	// Set second element of private member variable code to -1
	code[1] = -1;
	// Set third element of private member variable code to -1
	code[2] = -1;
}

// Calls constructor of 3 arguments of parent class to 
// set inherited private member variables to given values
Teacher::Teacher(int id, std::string name, int count, int first_code, int second_code, int third_code) 
	: Person(id, name, count)
{
	// Set first element of private member variable code to given first_code
	code[0] = first_code;
	// Set second element of private member variable code to given second_code
	code[1] = second_code;
	// Set third element of private member variable code to given third_code
	code[2] = third_code;
}

void Teacher::setCodeAtIndex(int index, int book_code)
{
	// If given index is less than or greater than size 
	// of private member variable code array
	if (index < 0 || index > getMaxBooksToRent())
	{
		// Notify
		std::cout << " Given index is out of bounds" << std::endl;
		// Exit program with error code 1
		exit(1);
	}
	// Set element at given index to given book_code
	code[index] = book_code;
}

int Teacher::getCodeAtIndex(int index) const
{
	// If given index is less than or greater than size 
	// of private member variable code array
	if (index < 0 || index > getMaxBooksToRent())
	{
		// Notify
		std::cout << " Given index is out of bounds" << std::endl;
		// Exit program with error code 1
		exit(1);
	}
	// Return element in private member variable 
	// code array at given index
	return code[index];
}

int Teacher::getIdentification() const
{
	// Return value of private member variable id
	return getId();
}

void Teacher::displayRentInfo() const
{
	// If number of books rented is 0 or 2
	if (getCount() == 0 || getCount() == 2)
	{
		// Output values of private member variables name and count in plural tense
		std::cout << " You are " << getName() << ".  " << "You rented " 
			<< getCount() << " books." << std::endl;
	}
	// If number of books rented is 1
	else if (getCount() == 1)
	{
		// Output value of private member variables name and coiunt in single tense
		std::cout << " You are " << getName() << ".  " << "You rented " 
			<< getCount() << " book." << std::endl;
	}
	// Otherwise
	else
	{
		// Output value of private member variables name 
		// and count and notify that max number of books have already been rented
		std::cout << " You are " << getName() << ".  " << "You already rented " 
			<< getCount() << " books." << std::endl;
	}

}

int Teacher::getMaxBooksToRent() const
{

	// Return the size of private member variable code array
	return sizeof(code) / sizeof(int);
}

bool Teacher::hasRentedBookWithGivenCode(int book_code) const
{
	// Loop through private member variable code
	for (int i = 0; i < getMaxBooksToRent(); i++)
	{
		// If current element is equal to given book_code
		if (code[i] == book_code)
		{
			// Return true
			return true;
		}
	}
	// Otherwise return false
	return false;
}

void Teacher::rentBook(int book_code)
{
	// Boolean flag to track if given book_code is 
	// successfully added initially set to false
	bool added = false;
	// Loop through private member variable code array
	for (int i = 0; i < getMaxBooksToRent(); i++)
	{
		// If current element is -1
		if (code[i] == -1)
		{
			// Set current element to given book_code
			code[i] = book_code;
			// Set flag to true
			added = true;
			// Get out of loop
			break;
		}
	}
	// If flag is true
	if (added)
	{
		// Increment value of private member variable count by 1
		setCount(getCount() + 1);
	}
}

void Teacher::returnBook(int book_code)
{
	// Set flag to keep track if given book_code 
	// is set to -1 initially set to -1
	bool returned = false;
	// Loop through private member variable code array
	for (int i = 0; i < getMaxBooksToRent(); i++)
	{
		// If current element is equal to given book_code
		if (code[i] == book_code)
		{
			// Set current element at -1
			code[i] = -1;
			// Set flag to true
			returned = true;
			// Get out of loop
			break;
		}
	}
	// If flag was set to true
	if (returned)
	{
		// Decrement value of private member variable count by 1
		setCount(getCount() - 1);
	}
}