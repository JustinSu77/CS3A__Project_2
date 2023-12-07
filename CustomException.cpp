#include "CustomException.h"

// Set value of private member variable to "Error"
CustomException::CustomException() : 
	message("Error")
{

}

// Set value of private member variable to given message
CustomException::CustomException(std::string message) 
	: message(message)
{

}


std::string CustomException::get_message() const
{
	// Return the value of private member variable message
	return message;
}


