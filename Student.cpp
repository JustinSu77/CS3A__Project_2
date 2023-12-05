#include "Student.h"

// Calls default constructor of Parent class to set inherited 
// private member variables with default values
Student::Student() : Person()
{
	// Set first and second element of private member variable code array to -1
	code[0] = -1;
	code[1] = -1;
}

// Calls constructor with 3 arguments of Parent class to set 
// inherited private member variables to given values
Student::Student(int id, std::string name, int count, int first_code, int second_code) : 
	Person(id, name, count)
{
	// Sets first element of private member variable code array to given first_code
	code[0] = first_code;
	// Sets second element of private member variable code array to given second_code
	code[1] = second_code;
}

void Student::setCodeAtIndex(int index, int book_code)
{
	// If given index is less than 0 or greater than max number of books to be rented
	if (index < 0 || index > getMaxBooksToRent())
	{
		// Notify
		std::cout << "Given index is out of bounds" << std::endl;
		// Exit program with error code 1
		exit(1);
	}
	// Set the value of element at given index to given book_code
	code[index] = book_code;
}

 int Student::getCodeAtIndex(int index) const
{
	// If given index is less than 0 or greater than max number of books to rent
	if (index < 0 || index > getMaxBooksToRent())
	{
		// Notify
		std::cout << "Given index is out of bounds" << std::endl;
		// Exit program with error code 1
		exit(1);
	}
	// Return value of private member variable code array at given index
	return code[index];
}

void Student::displayInfo() const
{
	std::cout << getId() << " " << getName() << " " << getCount();
	if (getCount() == 1)
	{
		std::cout << " " <<  code[0] << " ";
	}
	if (getCount() == 2)
	{
		std::cout <<  " " << code[0] << " " << code[1] << " ";
	}
	std::cout << std::endl;
}

int Student::getIdentification() const
{
	// Return the value of inherited private member variable id
	return getId();
}

void Student::displayRentInfo() const
{
	// If number of books rented is 0
	if (getCount() == 0)
	{
		// Output to name and count to terminal in plural tense
		std::cout << "You are " << getName() << ".  " << "You rented " 
			<< getCount() << " books." << std::endl;
	}
	// If number of books rented is 1
	else if (getCount() == 1)
	{
		// Output name and count to terminal in single tense
		std::cout << "You are " << getName() << ".  " << "You rented " 
			<< getCount() << " book." << std::endl;
	}
	// Otherwise
	else
	{
		// Output name and count and the max number of books have already been rented
		std::cout << "You are " << getName() << ".  " << "You already rented " 
			<< getCount() << " books." << std::endl;
	}
}

int Student::getMaxBooksToRent() const
{
	// Return the size of private member variable code array
	return sizeof(code) / sizeof(int);
}


 

bool Student::hasRentedBookWithGivenCode(int book_code) const
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

void Student::rentBook(int book_code)
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

void Student::returnBook(int book_code)
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
