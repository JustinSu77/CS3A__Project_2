#include "ProgramException.h"

// Set value of private member variable to "Error"
ProgramException::ProgramException() : 
	message("Error")
{

}

// Set value of private member variable to given message
ProgramException::ProgramException(std::string message) 
	: message(message)
{

}


std::string ProgramException::get_message() const
{
	// Return the value of private member variable message
	return message;
}


