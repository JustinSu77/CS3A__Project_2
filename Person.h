/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Person.h for Project #2
**/
#pragma once
#include <iostream>

// Person Class
class Person
{
	// Public member functions
public:
	/**
		Purpose: Default constructor.
		Preconditon: Person object is constructed with no arguments
		Result: - Private member variable id is set to 0
				- Private member variable name is set to empty string
				- Private member variable count is set to 0
	**/
	Person();

	/**
		Purpose: Constructor with 3 arguments.
		Precondition: Person object is constructed with 3 arguments
		Result: - Private member variable id is set to given id
				- Private member variable name is set to given name
				- Private member variable count is set to 0
	**/
	Person(int id, std::string name, int count);

	/**
		Purpose: Setter function for private member variable id.
		Precondition: Person object is instantiated
		Result: Private member variable id is set to given id
	**/
	void setId(int id);

	/**
		Purpose: Setter function for private member variable name.
		Precondition: Person object is instantiated
		Result: Private member variable name is set to given name
	**/
	void setName(std::string name);

	/**
		Purpose: Setter function for private member variable count.
		Precondition: Person object is instantiated
		Result: Private member variable count is set to given count
	**/
	void setCount(int count);

	/**
		Purpose: Getter function for private member variable id.
		Precondition: Person object is instantiated
		Result: Value of private member variable id is returned
	**/
	int getId() const;

	/**
		Purpose: Getter function for private member variable name.
		Precondition: Person object is instantiated
		Return: Value of private member variable string is returned
	**/
	std::string getName() const;

	/**
		Purpose: Getter function for private member variable count.
		Precondition: Person object is instantiated
		Return: Value of private member variable count is returned
	**/
	int getCount() const;

	// Virtual functions for polymorphism so derived 
	// classes of this class will have same functions 
	// but unique outputs
	/**
		Purpose: Return value of id for templated function that
				 inserts Person child object into Linked List.
		Precondition: Polymorphic Person object is instantiated
		Return: Value of id is returned
	**/
	virtual int getIdentification() const = 0;

	/**
		Purpose: Getter function for private member variable
				 code array.
		Precondition: Polymorphic Person object is instantiated
		Input: index as the index to return element at
		Input Requirement: Given index is an integer
		Return: - If given index is less than 0 or greater
					 than size of code array, notify and exit program
				- Otherwise return the element in code
				  array at given index
	**/
	virtual int getCodeAtIndex(int index) const = 0;

	/**
		Purpose: Output number of books Person child object has
				 rented for function to Rent a Book.
		Precondition: Polymorphic Person object is instantiated
		Return: Outputs values of private member variable name
				and count of Person object rented to terminal
	**/
	virtual void displayRentInfo() const = 0;

	/**
		Purpose: Return the maximum number of books
				 Person child object can have.
		Precondition: Polymorphic Person object is instantiated
		Return: Size of the private member variables code
				array of Child classes is returned
	**/
	virtual int getMaxBooksToRent() const = 0;

	/**
		Purpose: Check if private member variable code array
				 has given book_code value.
		Precondition: Polymorphic Person object is instantiated
		Input: book_code as the book code to check
		Input Requirement: Given book_code should be an integer
		Return: - Returns true if Child has given book_code in their code array
				- Otherwise return false
	**/
	virtual bool hasRentedBookWithGivenCode(int book_code) const = 0;

	/**
		Purpose: Add given book_code to code array and increment count by 1.
		Precondition: Polymorphic Person object is instantiated
		Input: book_code as the book code to add to code array
		Input Requirement: Given book_code should be an integer
		Return: - Add given book_code to element with value of -1
				- If book_code is added successfully,
				  increment count by 1
	**/
	virtual void rentBook(int book_code) = 0;

	/**
		Purpose: Set given book_code in code_array and
				 decrement count by 1.
		Precondition: Polymorphic Person object is instantiated
		Input: book_code as the book code to set to -1 in code array
		Input Requirement: Given book_code should be an integer
		Return: - Set given book_code to element with value of -1
				- If book_code is removed successfully,
				  decrement count by 1
	**/
	virtual void returnBook(int book_code) = 0;

	// Public member variables
private:
	// id of person
	int id;
	// name of person
	std::string name;
	// number of books person rented
	int count;
};