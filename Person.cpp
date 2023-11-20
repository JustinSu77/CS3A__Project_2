#include "Person.h"

Person::Person() : id(0), name(""), count(0)
{
}

Person::Person(int id, std::string name, int count) : 
	id(id), name(name), count(count)
{

}

void Person::setId(int id)
{
	this->id = id;
}

void Person::setName(std::string name)
{
	this->name = name;
}

void Person::setCount(int count)
{
	this->count = count;
}

int Person::getId() const
{
	return id;
}

std::string Person::getName() const
{
	return name;
}

int Person::getCount() const
{
	return count;
}
