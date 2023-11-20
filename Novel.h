#pragma once
#include "Book.h"

class Novel : public Book
{
	public:
		Novel();
		Novel(int code, std::string title, int available, int rented, int publish_date);
		void set_publish_date(int publish_date);
		int get_publish_date() const;
	private:
		int publish_date;
};

