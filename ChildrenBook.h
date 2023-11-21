#pragma once
#include "Book.h"
class ChildrenBook : public Book
{
	public:
		ChildrenBook();
		ChildrenBook(int code, std::string title, int available, int rented, int age);
		void setAge(int age);
		int getAge() const;
		virtual void displayInfo() const;
		virtual int getIdentification() const;
		virtual void markRented();
		virtual void markReturned();
	private:
		int age;
};

