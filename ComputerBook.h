#include "Book.h"

class ComputerBook : Book
{
	public:
		ComputerBook();
		ComputerBook(int newCode, std::string newTitle, int newAvailable, int newRented, std::string newPublisher);
		void setPublisher(std::string newPublisher);
		std::string getPublisher() const;
	private:
		std::string publisher;
};
