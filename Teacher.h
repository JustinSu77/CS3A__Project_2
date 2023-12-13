/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Teacher.h for Project #2
**/
#pragma once
#include "Person.h"

class Teacher : public Person
{
	public:
		/**
			Purpose: Default constructor
			Precondition: Teacher object is constructed with no arguments
			Postcondition: Sets the elements of private member variable code array to -1 
		**/
		Teacher();

		/**
			Purpose: Constructor with 6 arguments.
			Precondition: Teacher object is constructed with 6 arguments
			Postcondition:  - Calls constructor of parent class with 3 arguments
							- Sets the first element of private member variable code array to given first_code
							- Sets the second element of private member variable code array to given second_code
							- Sets the third element of private member variable code array to given third_code
		**/
		Teacher(int id, std::string name, int count, int first_code, int second_code, int third_code);

		/**
			Purpose: Set element at given index to given book_code.
			Precondition: Polymorphic Person object is instantiated
			Input: - index as the index to set given book_code at in private member variable code array
				   - book_code as the book code of Book rented
			Input Requirement: - Given index is an integer
							   - Given book_code is an integer
			Postcondition: - If given index is less than 0 or greater
							 than size of code array, notify and exit program
						   - Otherwise set the element in code array at given index to given book_code
		**/
		void setCodeAtIndex(int index, int book_code);

		/**
			Purpose: Getter function for private member variable code array.
			Precondition: Polymorphic Person object is instantiated
			Input: index as the index to return element at
			Input Requirement: Given index is an integer
			Postcondition: - If given index is less than 0 or greater
							 than size of code array, notify and exit program
						   - Otherwise return the element in code array at given index
		**/
		int getCodeAtIndex(int index) const;
		
		 
		// Implementation of the pure virtual function in Parent class
	 

		/**
			Purpose: Return value of id for templated function that
					 inserts Person child object into Linked List.
			Precondition: Polymorphic Person object is instantiated
			Postcondition: Value of id is returned
		**/
		int getIdentification() const;

		/**
			Purpose: Output number of books Person child object has rented for function to Rent a Book.
			Precondition: Polymorphic Person object is instantiated
			Postcondition: Outputs values of private member variable name
						   and count of Person object rented to terminal
		**/
		void displayRentInfo() const;

		/**
			Purpose: Return the maximum number of books Person child object can have.
			Precondition: Polymorphic Person object is instantiated
			Postcondition: Size of the private member variables code array of Child classes is returned
		**/
		int getMaxBooksToRent() const;

		/**
			Purpose: Check if private member variable code array has given book_code value.
			Precondition: Polymorphic Person object is instantiated
			Input: book_code as the book code to check
			Input Requirement: Given book_code should be an integer
			Postcondition: Returns true if Child has given book_code in their code array
						   Otherwise return false
		**/
		bool hasRentedBookWithGivenCode(int book_code) const;

		/**
			Purpose: Add given book_code to code array and increment count by 1.
			Precondition: Polymorphic Person object is instantiated
			Input: book_code as the book code to add to code array
			Input Requirement: Given book_code should be an integer
			Postcondition: Add given book_code to element with value of -1
						   If book_code is added successfully, increment count by 1
		**/
		void rentBook(int book_code);

		/**
			Purpose: Set given book_code in code_array and decrement count by 1.
			Precondition: Polymorphic Person object is instantiated
			Input: book_code as the book code to set to -1 in code array
			Input Requirement: Given book_code should be an integer
			Postcondition: Set given book_code to element with value of -1
						   If book_code is removed successfully, decrement count by 1
		**/
		void returnBook(int book_code);
	 
	private:
		int code[3];
};

