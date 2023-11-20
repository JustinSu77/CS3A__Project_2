
#include "ComputerBook.h"

ComputerBook::ComputerBook() : Book(), publisher("")
{

}

ComputerBook::ComputerBook(int code, std::string title, int available, int rented, std::string publisher) : 
	Book(code, title, available, rented), publisher(publisher)
{

}

void ComputerBook::setPublisher(std::string publisher)
{
	this->publisher = publisher;
}

std::string ComputerBook::getPublisher() const
{
	return publisher;
}
