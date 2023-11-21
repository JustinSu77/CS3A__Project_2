#pragma once
#include "Person.h"

class Teacher : public Person
{
	public:
		Teacher();
		Teacher(int id, std::string name, int count, int firstCode, int secondCode, int thirdCode);
		void setCodeAtIndex(int index, int book_code);
		virtual int getCodeAtIndex(int index) const;
		virtual void displayInfo() const;
		virtual int getIdentification() const;
		virtual void displayRentInfo() const;
		virtual int getMaxBooksToRent() const;
		virtual bool hasRentedBookWithGivenCode(int book_code) const;
		virtual void rentBook(int book_code);
		virtual void returnBook(int book_code);
	private:
		int code[3];
};

