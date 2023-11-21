#include "ChildrenBook.h"
#include <iostream>

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

void ChildrenBook::displayInfo() const
{
	std::cout << "category : " << "childen" << std::endl;
	std::cout << "age : " << getAge() << std::endl;
	std::cout << getAvailable() << " available, " << getRented() << " rented" << std::endl;


}

int ChildrenBook::getIdentification() const
{
	return getCode();
}
