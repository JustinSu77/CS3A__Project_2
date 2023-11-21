#pragma once
#include "Person.h"
#include <iostream>
class Student : public Person
{
	public:
		Student();
		Student(int id, std::string name, int count, int firstCode, int secondCode);
		
		virtual int getCodeAtIndex(int index) const;
		virtual void displayInfo() const;
		virtual int getIdentification() const;
		virtual void displayRentInfo() const;
		virtual int getMaxBooksToRent() const;
		virtual bool hasRentedBookWithGivenCode(int book_code) const;
		virtual void rentBook(int book_code);
		virtual void returnBook(int book_code);
	private:
		int code[2];
};

