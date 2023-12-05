#pragma once
#include <iostream>

// User-defined exception class
class InputException
{
	// public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: InputException is thrown with no arguments
			Postcondition: Set value of private member variable to "Error"
		**/
		InputException();

		/**
			Purpose: Constructor with 1 argument.
			Precondition: InputException is thrown with 1 argument
			Postcondition: Set value of private member variable to given message
		**/
		InputException(std::string message);
		std::string get_message() const;
	// private member variable
	private:
		std::string message;

};

