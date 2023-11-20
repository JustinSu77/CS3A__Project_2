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
