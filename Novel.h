/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Novel.h for Project #2
**/
#pragma once
#include "Book.h"
#include <iomanip>

// Novel class inherits from Book class
class Novel : public Book
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: Novel object is constructed with 0 arguments
			Postcondition: - Calls default constructor for parent class to set inherited private					   member variables to default values
						   - Private member variable publish_date is set to 0 
		**/
		Novel();

		/**
			Purpose: Constructor with 5 arguments.
			Precondition: Novel object is constructed with 5 arguments
			Postcondition: - Calls parent class constructor with 4 arguments to set inherited private				   member variables to given corresponding values
						   - Set private member variable publish_date to given publish_date
		**/
		Novel(int code, std::string title, int available, int rented, int publish_date);

		/**
			Purpose: Setter function for private member variable publish_date.
			Precondition: Novel object is instantiated
			Postcondition: Set private member variable publish_date to given publish_date
		**/
		void set_publish_date(int publish_date);

		/**
			Purpose: Getter function for private member variable publish_date.
			Precondition: Novel object is instantiated
			Postcondition: Return the value of private member variable publish_date
		**/
		int get_publish_date() const;
		
		// Implementations of pure virtual functions so this class will not be abstract
		/**
			Purpose: Display information about Novel object
					 for function that Search a Book.
			Precondition: Novel is instantiated
			Postcondition: Output the category and the private member
						   variables publish_date, available, and rented
		**/
		virtual void displaySearchedInfo() const;

		/**
			Purpose: Return the value of private member variable code of Novel object
					 for function that inserts templated nodes into Linked List
					 by ascending order of id.
			Precondition: Novel is instantiated
			Postcondition: Return the value of inherited private member variable code
		**/
		virtual int getIdentification() const;

		/**
			Purpose: Denotes a Novel object as being rented for
					 function to Rent a Book and Return a Book.
			Precondition: Novel is instantiated
			Postcondition: - The value of private member variable rented is increased by 1
						   - The value of private member variable available is decreased by 1
		**/
		virtual void markRented();

		/**
			Purpose: Denotes a Novel object as being returned for function
					 for Rent a Book and Return a Book.
			Precondition: Novel is instantiated
			Postcondition: - The value of private member variable rented is decreased by 1
						   - The value of private member variable available is increased by 1
		**/
		virtual void markReturned();

		/**
			Purpose: Output information of Novel object for function
					 for Show Person Information
			Precondition: Novel is instantiated
			Postcondition: Outputs the values of private member
						   variable title, code, and publish_date neatly
						   formatted to terminal
		**/
		virtual void displayInfoForPerson() const;

		/**
			Purpose: Output all information of Novel object
					 for function for Show All Books.
			Precondition: Novel is instantiated
			Postcondition: Outputs the values of private member variables code,
						   title with underscores removed, publish_date, available,
						   and rented neatly formatted to terminal
		**/
		virtual void displayAllInfo() const;

		/**
			Purpose: Return title with underscores replaced by space.
			Precondition: Novel is instantiated
			Postcondition: Returns the inherited private member variable title
						   with underscore replaced by space
		**/
		virtual std::string get_formatted_title() const;
		
	// Private member variables
	private:
		int publish_date;
};