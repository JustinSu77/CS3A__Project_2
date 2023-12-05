/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Student.h for Project #2
**/
#pragma once
#include "Person.h"
#include <iostream>

// Student class inherits Person class
class Student : public Person
{
	// Public member functions
	public:
		/**
			Purpose: Default constructor:
			Precondition: Student object is constructed with no arguments
			Postcondition: Set all elements of code array to -1
		**/
		Student();

		/**
			Purpose: Constructor with 5 arguments.
			Precondition: Student object is constructed with 5 arguments
			Postcondition: - Calls constructor of parent class with 3 arguments 
						     to set private member variables id, name, and count
						   - Set first element of private member variable code to first_code
						   - Set second element of private member variable code to second_code
		**/
		Student(int id, std::string name, int count, int first_code, int second_code);

		void setCodeAtIndex(int index, int book_code);
		/**
			Purpose: Return the element at given index
			Precondition: Polymorphic Person object is instantiated
			Input: index as the index to return element at
			Input Requirement: Given index is an integer
			Postcondition: - If given index is less than 0 or greater
						 than size of code array, notify and exit program
					   - Otherwise return the element in code array at given index
		**/
		int getCodeAtIndex(int index) const;
		
		// Pure virtual functions to be implemented in child classes as 
		// the behaviors are different depending on which Child class calls it

		virtual void displayInfo() const;

		/**
			Purpose: Return value of id for templated function that
					 inserts Person child object into Linked List.
			Precondition: Polymorphic Person object is instantiated
			Postcondition: Value of id is returned
		**/
		virtual int getIdentification() const;

		/**
			Purpose: Output number of books Person child object has rented for function to Rent a Book.
			Precondition: Polymorphic Person object is instantiated
			Postcondition: Outputs values of private member variable name
						   and count of Person object rented to terminal
		**/
		virtual void displayRentInfo() const;

		/**
			Purpose: Return the maximum number of books Person child object can have.
			Precondition: Polymorphic Person object is instantiated
			Postcondition: Size of the private member variables code array of Child classes is returned
		**/
		virtual int getMaxBooksToRent() const;

		/**
			Purpose: Check if private member variable code array has given book_code value.
			Precondition: Polymorphic Person object is instantiated
			Input: book_code as the book code to check
			Input Requirement: Given book_code should be an integer
			Postcondition: Returns true if Child has given book_code in their code array
						   Otherwise return false
		**/
		virtual bool hasRentedBookWithGivenCode(int book_code) const;

		/**
			Purpose: Add given book_code to code array and increment count by 1.
			Precondition: Polymorphic Person object is instantiated
			Input: book_code as the book code to add to code array
			Input Requirement: Given book_code should be an integer
			Postcondition: Add given book_code to element with value of -1
						   If book_code is added successfully, increment count by 1
		**/
		virtual void rentBook(int book_code);

		/**
			Purpose: Set given book_code in code_array and decrement count by 1.
			Precondition: Polymorphic Person object is instantiated
			Input: book_code as the book code to set to -1 in code array
			Input Requirement: Given book_code should be an integer
			Postcondition: Set given book_code to element with value of -1
						   If book_code is removed successfully, decrement count by 1
		**/
		virtual void returnBook(int book_code);
		 
	// Private member variable
	private:
		int code[2];
};

