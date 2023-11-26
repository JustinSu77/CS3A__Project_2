#pragma once
#include <iostream>
class Person
{
	public:
		Person();
		Person(int id, std::string name, int count);
		void setId(int id);
		void setName(std::string name);
		void setCount(int count);
		int getId() const;
		std::string getName() const;
		int getCount() const;
		virtual void displayInfo() const = 0;
		virtual int getIdentification() const = 0;
		virtual void displayRentInfo() const = 0;
		virtual int getMaxBooksToRent() const = 0;
		virtual bool hasRentedBookWithGivenCode(int book_code) const = 0;
		virtual void rentBook(int book_code) = 0;
		virtual void returnBook(int book_code) = 0;
		virtual int getCodeAtIndex(int index)const = 0;
	private:
		int id;
		std::string name;
		int count;
};

