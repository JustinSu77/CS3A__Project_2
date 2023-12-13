/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: ChildenBook.h for Project #2
**/
#pragma once
#include "Book.h"
#include <iomanip>

// ChildrenBook class inherits from Book class
class ChildrenBook : public Book
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: ChildrenBook is constructed with no arguments
			Result: Private member variable age is set to 0
		**/
		ChildrenBook();

		/**
			Purpose: Constructor with 5 arguments.
			Precondition: ChildrenBook object is constructed 
						  with 5 arguments
			Result: - Private member variable code is set to given code
				    - Private member variable title is set to given title
				    - Private member variable available is 
					  set to given available
					- Private member variable rented is 
					  set to given rented
		**/
		ChildrenBook(int code, std::string title, int available, int rented, int age);

		/**
			Purpose: Setter for private member variable age.
			Precondition: ChildrenBook is instantiated
			Result: Private member variable age is set to given age
		**/
		void setAge(int age);

		/**
			Purpose: Getter for private member variable age.
			Precondition: ChildrenBook is instantiated
			Result: The value of private member variable age is returned
		**/
		int getAge() const;
		
		// Implementation for inherited pure virtual functions 
		// for polymorphism so derived classes of this class 
		// will have same functions but unique outputs
		/**
			Purpose: Display information about ChildrenBook object 
					 for function that Search a Book.
			Precondition: ChildrenBook is instantiated
			Result: Output the category and the private member 
					variables age, available, and rented 
		**/

		void displaySearchedInfo() const;
		
		/**
			Purpose: Return the value of private member variable code 
					 of ChildrenBook object for function that inserts 
					 templated nodes into Linked List by 
				     ascending order of id.
			Precondition: ChildrenBook is instantiated
			Result: Return the value of inherited 
			        private member variable code
		**/
		int getIdentification() const;

		/**
			Purpose: Denotes a ChildrenBook object as being rented for 
					 function to Rent a Book and Return a Book.
			Precondition: ChildrenBook is instantiated
			Result: - The value of private member variable 
			          rented is increased by 1
					- The value of private member variable 
					  available is decreased by 1
		**/
		 void markRented();

		/**
			Purpose: Denotes a ChildrenBook object as being returned for 
					 function for Rent a Book and Return a Book.
			Precondition: ChildrenBook is instantiated
			Result: - The value of private member variable 
			          rented is decreased by 1
					- The value of private member variable 
					  available is increased by 1
		**/
		void markReturned();

		/**
			Purpose: Output information of ChildrenBook object for function 
					 Show Person Information.
			Precondition: ChildrenBook is instantiated
			Result: Outputs the values of private member 
				    variable title, code, and age neatly 
					formated to terminal
		**/
		void displayInfoForPerson() const;

		/**
			Purpose: Output all information of ChildrenBook object 
					 for function for Show All Books.
			Precondition: ChildrenBook is instantiated
			Result: Outputs the values of private member variables code, 
					title with underscores removed, age, available, and rented
		**/
		void displayAllInfo() const;

		/**
			Purpose: Return title with underscores replaced by space.
			Precondition: ChildrenBook is instantiated
			Result: Returns the inherited private member 
					variable title with underscore replaced by space
		**/
		std::string get_formatted_title() const;
	
	// Private member variables
	private:
		// age for Children Books
		int age;
};