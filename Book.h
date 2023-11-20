#pragma once
#include <iostream>
 
class Book
{
	public:
		Book();
		Book(int newCode, std::string newTitle, int newAvailable, int newRented);
		void setCode(int newCode);
		void setTitle(std::string newTitle);
		void setAvailable(int newAvailable);
		void setRented(int newRented);
		int getCode() const;
		std::string getTitle() const;
		int getAvailable() const;
		int getRented() const;
	private:
		int code;
		std::string title;
		int available;
		int rented;
};

