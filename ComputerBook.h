#include "Book.h"

class ComputerBook : Book
{
	public:
		ComputerBook();
		ComputerBook(int code, std::string title, int available, int rented, std::string publisher);
		void setPublisher(std::string publisher);
		std::string getPublisher() const;
	private:
		std::string publisher;
};
