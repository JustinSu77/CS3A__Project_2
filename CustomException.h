#pragma once
#include <iostream>

// User-defined exception class
class CustomException
{
	// public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: InputException is thrown with no arguments
			Postcondition: Set value of private member variable to "Error"
		**/
		CustomException();

		/**
			Purpose: Constructor with 1 argument.
			Precondition: InputException is thrown with 1 argument
			Postcondition: Set value of private member variable to given message
		**/
		CustomException(std::string message);
		
		/**
			Purpose: Getter function for private member variable message
			Precondition: InputException object is instantiated
			Postcondition: Return the value of private member variable message
		**/
		std::string get_message() const;
	// private member variable
	private:
		std::string message;

};

