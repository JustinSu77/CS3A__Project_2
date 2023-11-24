#include "ChildrenBook.h"

ChildrenBook::ChildrenBook() : Book(), age(0) 
{

}

ChildrenBook::ChildrenBook(int code, std::string title, int available, int rented, int age) : 
	Book(code, title, available, rented), age(age)
{

}

void ChildrenBook::setAge(int age)
{
	this->age = age;
}

int ChildrenBook::getAge() const
{
	return age;
}

void ChildrenBook::displaySearchedInfo() const
{
	std::cout << "category : " << "children" << std::endl;
	std::cout << "age : " << getAge() << std::endl;
	std::cout << getAvailable() << " available, " << getRented() << " rented" << std::endl;
}

int ChildrenBook::getIdentification() const
{
	return getCode();
}

void ChildrenBook::markRented()
{
	setAvailable(getAvailable() - 1);
	setRented(getRented() + 1);
}

void ChildrenBook::markReturned()
{
	setAvailable(getAvailable() + 1);
	setRented(getRented() - 1);
}

void ChildrenBook::displayInfo() const
{
	std::cout << "* " << getTitle() << "(" << getCode() << ")" << " - " << " age " << getAge() <<  std::endl;
}

void ChildrenBook::displayAllInfo() const
{
	std::cout << " " << getCode() << std::setw(30) << get_formatted_title() << std::setw(4) << getAge() << std::setw(10) << getAvailable() << std::setw(7) << getRented() << std::endl;
}

std::string ChildrenBook::get_formatted_title() const
{
	std::string title = getTitle();
	std::replace(title.begin(), title.end(), '_', ' ');
	return title;

}
