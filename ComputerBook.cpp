
#include "ComputerBook.h"

ComputerBook::ComputerBook() : Book(), publisher("")
{

}

ComputerBook::ComputerBook(int newCode, std::string newTitle, int newAvailable, int newRented, std::string newPublisher) : 
	Book(newCode, newTitle, newAvailable, newRented), publisher(newPublisher)
{

}

void ComputerBook::setPublisher(std::string newPublisher)
{
	publisher = newPublisher;
}

std::string ComputerBook::getPublisher() const
{
	return publisher;
}
