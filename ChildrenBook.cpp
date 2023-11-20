#include "ChildrenBook.h"

ChildrenBook::ChildrenBook() : Book(), age(0) 
{

}

ChildrenBook::ChildrenBook(int newCode, std::string newTitle, int newAvailable, int newRented, int newAge) : 
	Book(newCode, newTitle, newAvailable, newRented), age(newAge)
{

}

void ChildrenBook::setAge(int newAge)
{
	age = newAge;
}

int ChildrenBook::getAge() const
{
	return age;
}
