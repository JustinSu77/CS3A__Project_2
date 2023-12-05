/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: ChildenBook.h for Project #2
**/

#pragma once
#include "Book.h"
#include <iomanip>

// ChildrenBook class inherits from Book
class ChildrenBook : public Book
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: ChildrenBook is constructed with no arguments
			Postcondition: Private member variable age is set to 0
		**/
		ChildrenBook();

		/**
			Purpose: Constructor with 5 arguments.
			Precondition: ChildrenBook object is constructed with 5 arguments
			Postcondition: - Private member variable code is set to given code
						   - Private member variable title is set to given title
						   - Private member variable available is set to given available
						   - Private member variable rented is set to given rented
		**/
		ChildrenBook(int code, std::string title, int available, int rented, int age);

		/**
			Purpose: Setter for private member variable age.
			Precondition: ChildrenBook is instantiated
			Postcondition: Private member variable age is set to given age
		**/
		void setAge(int age);

		/**
			Purpose: Getter for private member variable age.
			Precondition: ChildrenBook is instantiated
			Postcondition: The value of private member variable age is returned
		**/
		int getAge() const;
		
		// Implementations of pure virtual functions so this class will not be abstract
		/**
			Purpose: Display information about ChildrenBook object 
					 for function that Search a Book.
			Precondition: ChildrenBook is instantiated
			Postcondition: Output the category and the private member 
						   variables age, available, and rented 
		**/
		virtual void displaySearchedInfo() const;
		
		/**
			Purpose: Return the value of private member variable code of ChildrenBook object 
					 for function that inserts templated nodes into Linked List 
					 by ascending order of id.
			Precondition: ChildrenBook is instantiated
			Postcondition: Return the value of inherited private member variable code
		**/
		virtual int getIdentification() const;

		/**
			Purpose: Denotes a ChildrenBook object as being rented for 
					 function to Rent a Book and Return a Book.
			Precondition: ChildrenBook is instantiated
			Postcondition: - The value of private member variable rented is increased by 1
						   - The value of private member variable available is decreased by 1
		**/
		virtual void markRented();

		/**
			Purpose: Denotes a ChildrenBook object as being returned for function for Rent a Book	   and Return a Book.
			Precondition: ChildrenBook is instantiated
			Postcondition: - The value of private member variable rented is decreased by 1
						   - The value of private member variable available is increased by 1
		**/
		virtual void markReturned();

		/**
			Purpose: Output information of ChildrenBook object for function 
					 for Show Person Information
			Precondition: ChildrenBook is instantiated
			Postcondition: Outputs the values of private member 
						   variable title, code, and age neatly formated to terminal
		**/
		virtual void displayInfoForPerson() const;

		/**
			Purpose: Output all information of ChildrenBook object 
					 for function for Show All Books.
			Precondition: ChildrenBook is instantiated
			Postcondition: Outputs the values of private member variables code, 
						   title with underscores removed, age, available, and rented
		**/
		virtual void displayAllInfo() const;

		/**
			Purpose: Return title with underscores replaced by space.
			Precondition: ChildrenBook is instantiated
			Postcondition: Returns the inherited private member 
						   variable title with underscore replaced by space
		**/
		virtual std::string get_formatted_title() const;
	
	// Private member variables
	private:
		int age;
};

