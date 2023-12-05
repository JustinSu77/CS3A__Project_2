#include "InputException.h"

// Set value of private member variable to "Error"
InputException::InputException() : 
	message("Error")
{

}

// Set value of private member variable to given message
InputException::InputException(std::string message) 
	: message(message)
{

}


std::string InputException::get_message() const
{
	// Return the value of private member variable message
	return message;
}


