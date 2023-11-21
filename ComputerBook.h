#include "Book.h"

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
	private:
		std::string publisher;
};
