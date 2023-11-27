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

void Student::setCodeAtIndex(int index, int book_code)
{
	if (index < 0 || index > getMaxBooksToRent())
	{
		std::cout << "Given index is out of bounds" << std::endl;
		exit(1);
	}

	code[index] = book_code;
}

 

int Student::getCodeAtIndex(int index) const
{
	if (index < 0 || index > getMaxBooksToRent())
	{
		std::cout << "Given index is out of bounds" << std::endl;
		exit(1);
	}

	return code[index];
}

void Student::displayInfo() const
{
	std::cout << getId() << " " << getName() << " " << getCount();
	if (getCount() == 1)
	{
		std::cout << " " <<  code[0] << " ";
	}
	if (getCount() == 2)
	{
		std::cout <<  " " << code[0] << " " << code[1] << " ";
	}
	std::cout << std::endl;
}

int Student::getIdentification() const
{
	return getId();
}

void Student::displayRentInfo() const
{
	if (getCount() == 0)
	{
		std::cout << "You are " << getName() << ".  " << "You rented " << getCount() << " books." << std::endl;
	}
	else if (getCount() == 1)
	{
		std::cout << "You are " << getName() << ".  " << "You rented " << getCount() << " book." << std::endl;
	}
	else
	{
		std::cout << "You are " << getName() << ".  " << "You already rented " << getCount() << " books." << std::endl;
	}
}

int Student::getMaxBooksToRent() const
{
	return sizeof(code) / sizeof(int);
}


 

bool Student::hasRentedBookWithGivenCode(int book_code) const
{
	for (int i = 0; i < getMaxBooksToRent(); i++)
	{
		if (code[i] == book_code)
		{
			return true;
		}
	}
	return false;
}

void Student::rentBook(int book_code)
{
	for (int i = 0; i < getMaxBooksToRent(); i++)
	{
		if (code[i] == -1)
		{
			code[i] = book_code;
			break;
		}
	}
	setCount(getCount() + 1);
}

void Student::returnBook(int book_code)
{
	for (int i = 0; i < getMaxBooksToRent(); i++)
	{
		if (code[i] == book_code)
		{
			code[i] = -1;
			break;
		}
	}
	setCount(getCount() - 1);
}
