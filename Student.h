#pragma once
#include "Person.h"
#include <iostream>
class Student : public Person
{
	public:
		Student();
		Student(int id, std::string name, int count, int firstCode, int secondCode);
		void setFirstCode(int firstCode);
		void setSecondCode(int secondCode);
		int getFirstCode() const;
		int getSecondCode() const;
		virtual void displayInfo() const;
		virtual int get_identification() const;
	private:
		int code[2];
};

