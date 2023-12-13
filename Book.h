/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Book.h for Project #2
**/
#pragma once
#include <iostream>
#include <algorithm>

// Book class
class Book
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor.
			Precondition: Book object is constructed with no arguments
			Result: - Private member variable code is set to 0
						   - Private member variable title to empty string
						   - Private member variable available is set to 0
						   - Private member variable rented is set to 0
		**/
		Book();

		/**
			Purpose: Constructor with 4 arguments.
			Precondition: Book object is constructed with 4 arguments
			Result: - Private member variable code is set to given code
				    - Private member variable title is set to given title
				    - Private member variable available is set to given available
				    - Private member variable rented is set to given rented
		**/
		Book(int code, std::string title, int available, int rented);

		/**
			Purpose: Setter function for private member variable code.
			Precondition: Book object is instantiated
			Result: Set private member variable code to given code
		**/
		void setCode(int code);
		
		/**
			Purpose: Setter function for private member variable title.
			Precondition: Book object is instantiated
			Result: Set private member variable title to given title
		**/
		void setTitle(std::string title);

		/**
			Purpose: Setter function for private member variable available.
			Precondition: Book object is instantiated
			Result: Set private member variable available to given available
		**/
		void setAvailable(int available);

		/**
			Purpose: Setter function for private member variable rented.
			Precondition: Book object is instantiated
			Result: Set private member variable rented to given rented
		**/
		void setRented(int rented);

		/**
			Purpose: Getter function for private member variable code.
			Precondition: Book object is instantiated
			Result: Return value of private member variable code
		**/
		int getCode() const;

		/**
			Purpose: Getter function for private member variable title.
			Precondition: Book object is instantiated
			Result: Return value of private member variable title
		**/
		std::string getTitle() const;

		/**
			Purpose: Getter function for private member variable available.
			Precondition: Book object is instantiated
			Result: Return value of private member variable available
		**/
		int getAvailable() const;
		
		/**
			Purpose: Getter function for private member variable rented.
			Precondition: Book object is instantiated
			Result: Return value of private member variable rented
		**/
		int getRented() const;

		// Pure virtual functions so child class can have their own implementation
		/**
			Purpose: Display necessary information of Book objects 
					 to for task Search a Book.
			Precondition: Book object is instantiated
			Result: Values of private member variables title, unique private member variable, 
			        available, and rented of polymorphic Book objects are 
					outputted to terminal neatly formatted
		**/

		// Virtual functions for polymorphism so derived classes of this class 
		// will have same functions but unique outputs
		virtual void displaySearchedInfo() const = 0;

		/**
			Purpose: Return book code to allow templated function that 
					 inserts templated nodes into Linked List by ascending order of id.
			Precondition: Book object is instantiated
			Result: Private member variable book code is returned
		**/
		virtual int getIdentification() const = 0;

		/**
			Purpose: Used in functions to Rent a Book and Return a Book
			Precondition: Book object is instantiated
			Result: - Private member variable available is decreased by 1
			        - Private member variable rented is increased by 1
		**/
		virtual void markRented() = 0;

		/**
		   Purpose: Used in functions to Rent a Book and Return a Book
		   Precondition: Book object is instantiated
		   Result: - Private member variable available is increased by 1
				   - Private member variable rented is decreased by 1
	   **/
		virtual void markReturned() = 0;

		/**
			Purpose: Used in function to Show Person Information
			Precondition: Book object is instantiated
			Result: Values of private member variable title, code, and 
				    unique private member variable are neatly 
				    formatted to terminal
		**/
		 
		virtual void displayInfoForPerson() const = 0;

		/**
			Purpose: Used in function to Show All Books
			Precondition: Book object is instantiated
			Result: Values of private member variable code, formatted title,
			        unique private member variable, available, and 
					rented are neatly formatted to terminal
		**/
		virtual void displayAllInfo() const = 0;

		/**
			Purpose: Used in function to Show All Books to display 
			         title without underscores.
			Precondition: Book object is instantiated
			Result: Private member variable title has 
			        its underscores removed and is returned
		**/
		virtual std::string get_formatted_title() const = 0;
   
	// Private member variables
	private:
		// Book code
		int code;
		// title of book
		std::string title;
		// Count for number of instance of this class to be rented
		int available;
		// Count for number of instance of this class rented
		int rented;
};

