/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: ProgramException.h for Project #2
**/
#pragma once
#include <iostream>

// User-defined exception class
class ProgramException
{
	// public member functions
public:
	/**
		Purpose: Default constructor.
		Precondition: InputException is thrown with no arguments
		Result: Set value of private member variable to "Error"
	**/
	ProgramException();

	/**
		Purpose: Constructor with 1 argument.
		Precondition: InputException is thrown with 1 argument
		Result: Set value of private member variable to given message
	**/
	ProgramException(std::string message);

	/**
		Purpose: Getter function for private member variable message
		Precondition: InputException object is instantiated
		Result: Return the value of private member variable message
	**/
	std::string get_message() const;

	// private member variable
private:
	std::string message;
};