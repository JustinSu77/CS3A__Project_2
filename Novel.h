#pragma once
#include "Book.h"

class Novel : public Book
{
	public:
		Novel();
		Novel(int code, std::string title, int available, int rented, int publish_date);
		void set_publish_date(int publish_date);
		int get_publish_date() const;
		virtual void displayInfo() const;
		virtual int get_identification() const;
	private:
		int publish_date;
};

