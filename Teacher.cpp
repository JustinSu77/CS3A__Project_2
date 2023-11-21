#include "Teacher.h"

Teacher::Teacher() : Person()
{
	code[0] = -1;
	code[1] = -1;
	code[2] = -1;
}

Teacher::Teacher(int id, std::string name, int count, int firstCode, int secondCode, int thirdCode) : Person(id, name, count)
{
	code[0] = firstCode;
	code[1] = secondCode;
	code[2] = thirdCode;
}

void Teacher::setFirstCode(int firstCode)
{
	code[0] = firstCode;
}

void Teacher::setSecondCode(int secondCode)
{
	code[1] = secondCode;
}

void Teacher::setThirdCode(int thirdCode)
{
	code[2] = thirdCode;
}

int Teacher::getFirstCode() const
{
	return code[0];
}

int Teacher::getSecondCode() const
{
	return code[1];
}

int Teacher::getThirdCode() const
{
	return code[2];
}

void Teacher::displayInfo() const
{
	std::cout << getId() << " " << getName() << " " << getCount() << " ";
	if (getCount() == 1)
	{
		std::cout << code[0];
	}
	if (getCount() == 2)
	{
		std::cout << code[0] << " " << code[1];
	}
	if (getCount() == 3)
	{
		std::cout << code[0] << " " << code[1] << " " << code[2];
	}
	std::cout << std::endl;
}

int Teacher::getIdentification() const
{
	return getId();
}

void Teacher::displayRentedInfo() const
{
	if (getCount() == 0 && getCount() == 2)
	{
		std::cout << "You are " << getName() << ".  " << "You rented " << getCount() << "books." << std::endl;
	}
	else if (getCount() == 1)
	{
		std::cout << "You are " << getName() << ".  " << "You rented " << getCount() << "book." << std::endl;
	}
	else
	{
		std::cout << "You are " << getName() << ".  " << "You already rented " << getCount() << "books." << std::endl;
	}

}

