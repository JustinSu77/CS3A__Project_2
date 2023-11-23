
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

void ComputerBook::displaySearchedInfo() const
{
	std::cout << "category : " << "computer" << std::endl;
	std::cout << "publisher : " << getPublisher() << std::endl;
	std::cout << getAvailable() << " available, " << getRented() << " rented" << std::endl;
}

int ComputerBook::getIdentification() const
{
	return getCode();
}

void ComputerBook::markRented()
{
	setAvailable(getAvailable() - 1);
	setRented(getRented() + 1);
}

void ComputerBook::markReturned()
{
	setAvailable(getAvailable() + 1);
	setRented(getRented() - 1);
}

void ComputerBook::displayInfo() const
{
	std::cout << "* " << getTitle() << "(" << getCode() << ")" << " - " 
		<< " publisher  " << getPublisher() << std::endl;
}

void ComputerBook::displayAllInfo() const
{
	std::cout << getCode() << " " << get_clean_title() << " " << getPublisher() << " " << getAvailable() << " " << getRented() << std::endl;
}

std::string ComputerBook::get_clean_title() const
{
	std::string title = getTitle();
	std::replace(title.begin(), title.end(), '_', ' ');
	return title;
}
