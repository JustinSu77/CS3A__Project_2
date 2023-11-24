#pragma once
#include "Book.h"
#include <iomanip>
class Novel : public Book
{
	public:
		Novel();
		Novel(int code, std::string title, int available, int rented, int publish_date);
		void set_publish_date(int publish_date);
		int get_publish_date() const;
		virtual void displaySearchedInfo() const;
		virtual int getIdentification() const;
		virtual void markRented();
		virtual void markReturned();
		virtual void displayInfo() const;
		virtual void displayAllInfo() const;
		virtual std::string get_formatted_title() const;
	private:
		int publish_date;
};

