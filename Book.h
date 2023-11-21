#pragma once
#include <iostream>
 
class Book
{
	public:
		Book();
		Book(int code, std::string title, int available, int rented);
		void setCode(int code);
		void setTitle(std::string title);
		void setAvailable(int available);
		void setRented(int rented);
		int getCode() const;
		std::string getTitle() const;
		int getAvailable() const;
		int getRented() const;
		virtual void displaySearchedInfo() const = 0;
		virtual int getIdentification() const = 0;
		virtual void markRented() = 0;
		virtual void markReturned() = 0;
		virtual void displayInfo() const = 0;
	private:
		int code;
		std::string title;
		int available;
		int rented;
};

