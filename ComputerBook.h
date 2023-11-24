#include "Book.h"
#include <iomanip>
class ComputerBook : public Book
{
	public:
		ComputerBook();
		ComputerBook(int code, std::string title, int available, int rented, std::string publisher);
		void setPublisher(std::string publisher);
		std::string getPublisher() const;
		virtual void displaySearchedInfo() const;
		virtual int getIdentification() const;
		virtual void markRented();
		virtual void markReturned();
		virtual void displayInfo() const;
		virtual void displayAllInfo() const;
		virtual std::string get_formatted_title() const;
	private:
		std::string publisher;
};
