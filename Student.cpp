#include "Student.h"

Student::Student() : Person()
{
	code[0] = -1;
	code[1] = -1;
}

Student::Student(int id, std::string name, int count, int firstCode, int secondCode) : Person(id, name, count)
{
	code[0] = firstCode;
	code[1] = secondCode;
}

void Student::setFirstCode(int firstCode)
{
	code[0] = firstCode;
}

void Student::setSecondCode(int secondCode)
{
	code[1] = secondCode;
}

int Student::getFirstCode() const
{
	return code[0];
}

int Student::getSecondCode() const
{
	return code[1];
}

void Student::displayInfo() const
{
	std::cout << getId() << " " << getName()<< " " << getCount();
	if (getCount() == 1)
	{
		std::cout << code[0] << " ";
	}
	if (getCount() == 2)
	{
		std::cout << code[0] << " " <<  code[1] << " ";
	}
	std::cout << std::endl;
}

int Student::get_identification() const
{
	return getId();
}


