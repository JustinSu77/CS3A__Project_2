/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Person.cpp for Project #2
**/
#include "Person.h"

// Set private member variable id to 0
// Set private member variable name to empty string
// Set private member variable count to 0
Person::Person() : id(0), name(""), count(0)
{
}

// Set private member variable id to given id
// Set private member variable name to given name
// Set private member variable to given count
Person::Person(int id, std::string name, int count) : 
	id(id), name(name), count(count)
{

}

void Person::setId(int id)
{
	// Set value of private member variable id to given id
	this->id = id;
}

void Person::setName(std::string name)
{
	// Set value of private member variable name to given name
	this->name = name;
}

void Person::setCount(int count)
{
	// Set value of private member variable count to given count
	this->count = count;
}

int Person::getId() const
{
	// Return the value of private member variable id
	return id;
}

std::string Person::getName() const
{
	// Return the value of private member variable name
	return name;
}

int Person::getCount() const
{
	// Return the value of private member variable count
	return count;
}