#pragma once
#include "Person.h"

class Student : public Person
{
	public:
		Student();
		Student(int id, std::string name, int count, int firstCode, int secondCode);
		void setFirstCode(int firstCode);
		void setSecondCode(int secondCode);
		int getFirstCode() const;
		int getSecondCode() const;
	private:
		int code[2];
};

