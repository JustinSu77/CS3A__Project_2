/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: ComputerBook.h for Project #2
**/
#include "Book.h"
#include <iomanip>

// ComputerBook class inherits from Book class
class ComputerBook : public Book
{
	// Public member functions
public:
	/**
		Purpose: Default constructor
		Precondition: ComputerBook is constructed
					  with no arguments
		Result: Private member variable publisher
				is set to empty string
	**/
	ComputerBook();

	/**
		Purpose: Constructor with 5 arguments.
		Precondition: ComputerBook is constructed with 5 arguments
		Result: - Private member variables code is set to given code
				- Private member variables title is
				  set to given title
				- Private member variables available is set to given available
				- Private member variagles publisher is set to given publisher
	**/
	ComputerBook(int code, std::string title, int available, int rented, std::string publisher);

	/**
		Purpose: Setter function for private member
				 variable publisher.
		Precondition: ComputerBook object is instantiated
		Result: Private member variable publisher is
				set to given publisher value
	**/
	void setPublisher(std::string publisher);

	/**
		Purpose: Getter function for private member
				 variable publisher.
		Precondition: ComputerBook object is instantiated
		Result: Value of private member variable
				publisher is returned
	**/
	std::string getPublisher() const;

	// Implementations of pure virtual functions so 
	// this class will not be abstract
	/**
		Purpose: Display information about ComputerBook object
				 for function that Search a Book.
		Precondition: ComputerBook is instantiated
		Result: Output the category and the private member
				variables age, available, and rented
	**/
	void displaySearchedInfo() const;

	/**
		Purpose: Return the value of private member variable
				 code of ComputerBook object for function that
				 inserts templated nodes into Linked List
				 by ascending order of id.
		Precondition: ComputerBook is instantiated
		Result: Return the value of inherited private member variable code
	**/
	int getIdentification() const;

	/**
		Purpose: Denotes a ComputerBook object as being rented for
				 function to Rent a Book and Return a Book.
		Precondition: ComputerBook is instantiated
		Result: - The value of private member variable rented is increased by 1
				- The value of private member variable
				  available is decreased by 1
	**/
	void markRented();

	/**
		Purpose: Denotes a ComputerBook object as being returned
				for functions to Rent a Book and Return a Book.
		Precondition: ComputerBook is instantiated
		Result: - The value of private member variable
				  rented is decreased by 1
				- The value of private member variable
				  available is increased by 1
	**/
	void markReturned();

	/**
		Purpose: Output information of ComputerBook
				 object for function for Show Person Information.
		Precondition: ComputerBook is instantiated
		Result: Outputs the values of private member
				variable title, code, and publisher neatly
				formatted to terminal
	**/
	void displayInfoForPerson() const;

	/**
		Purpose: Output all information of ComputerBook object
				 for function for Show All Books.
		Precondition: ComputerBook is instantiated
		Result: Outputs the values of private member variables code,
				title with underscores removed, publisher, available,
				and rented neatly formatted to terminal
	**/
	void displayAllInfo() const;

	/**
		Purpose: Return title with underscores replaced by space.
		Precondition: ComputerBook is instantiated
		Result: Returns the inherited private member variable title
				with underscore replaced by space
	**/
	std::string get_formatted_title() const;

	// Private member variable
private:
	// Publisher of Computer Books
	std::string publisher;
};