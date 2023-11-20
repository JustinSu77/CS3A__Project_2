#include "Book.h"

class ComputerBook : public Book
{
	public:
		ComputerBook();
		ComputerBook(int code, std::string title, int available, int rented, std::string publisher);
		void setPublisher(std::string publisher);
		std::string getPublisher() const;
		virtual void displayInfo() const;
		virtual int get_identification() const;
	private:
		std::string publisher;
};
