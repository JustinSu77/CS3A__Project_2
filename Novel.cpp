#include "Novel.h"

Novel::Novel() : Book(), publish_date(0)
{

}

Novel::Novel(int code, std::string title, int available, int rented, int publish_date)
	: Book(code, title, available, rented), publish_date(publish_date)
{

}

void Novel::set_publish_date(int publish_date)
{
	this->publish_date = publish_date;
}

int Novel::get_publish_date() const
{
	return publish_date;
}
