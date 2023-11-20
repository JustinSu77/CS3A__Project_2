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

