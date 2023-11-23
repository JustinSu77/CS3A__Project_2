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

void Novel::displaySearchedInfo() const
{
	std::cout << "category : " << "novel" << std::endl;
	std::cout << "publish date : " << get_publish_date() << std::endl;
	std::cout << getAvailable() << " available, " << getRented() << " rented" << std::endl;
}

int Novel::getIdentification() const
{
	return getCode();
}

void Novel::markRented()
{
	setAvailable(getAvailable() - 1);
	setRented(getRented() + 1);
}

void Novel::markReturned()
{
	setAvailable(getAvailable() + 1);
	setRented(getRented() - 1);
}

void Novel::displayInfo() const
{
	std::cout << "* " << getTitle() << "(" << getCode() << ")" << " - " << " publish date " << get_publish_date() << std::endl;
}

void Novel::displayAllInfo() const
{
	std::cout << getCode() << " " << get_clean_title() << " " << get_publish_date() 
		<< " " << getAvailable() << " " << getRented() << std::endl;
}

std::string Novel::get_clean_title() const
{
	std::string title = getTitle();
	std::replace(title.begin(), title.end(), '_', ' ');
	return title;
}
