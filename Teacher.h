#pragma once
#include "Person.h"

class Teacher : public Person
{
	public:
		Teacher();
		Teacher(int id, std::string name, int count, int firstCode, int secondCode, int thirdCode);
		void setFirstCode(int firstCode);
		void setSecondCode(int secondCode);
		void setThirdCode(int thirdCode);
		int getFirstCode() const;
		int getSecondCode() const;
		int getThirdCode() const;
		virtual void displayInfo() const;
		virtual int getIdentification() const;
		virtual void displayRentInfo() const;
		virtual int getMaxBooksToRent() const;
		virtual void setCodeByIndex(int book_code, int index);
		virtual bool bookIsRented(int book_code) const;
	private:
		int code[3];
};

