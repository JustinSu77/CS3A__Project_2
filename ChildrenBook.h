#pragma once
#include "Book.h"
class ChildrenBook : public Book
{
	public:
		ChildrenBook();
		ChildrenBook(int newCode, std::string newTitle, int newAvailable, int newRented, int newAge);
		void setAge(int newAge);
		int getAge() const;
	private:
		int age;
};

