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
		virtual int getIdentification() const;
		virtual void displayRentInfo() const;
		virtual int getMaxBooksToRent() const;
		virtual void setCodeByIndex(int book_code, int index);
		virtual bool bookIsRented(int book_code) const;
	private:
		int code[2];
};

