/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Node.h for Project #2
**/
#ifndef NODE_H
#define NODE_H

// Templated Node class
// Use T as template data type
template<class T>
class Node
{
	// Public member functions
public:
	/**
		Purpose: Default constructor.
		Precondition: Node object is constructed with no arguments
		Postcondition: - Private member variable data is set to value
						 of default constructor of data type T
					   - Private member variable link is set to NULL
	**/
	Node();

	/**
		Purpose: Constructor with 2 arguments.
		Precondition: Node object is constructed with 2 arguments
		Postcondition: - Private member variable is set to given data
					   - Private member variable link is set to given nextNode
	**/
	Node(T data, Node<T>* nextNode);

	/**
		Purpose: Setter function for private member variable data.
		Precondition: Node object is instantiated
		Postcondition: Private member variable data is set to given data
	**/
	void setData(T data);

	/**
		Purpose: Setter function for private member variable link.
		Precondition: Node object is instantiated
		Postcondition: Private member variable link is set to given nextNode
	**/
	void setLink(Node<T>* nextNode);

	/**
		Purpose: Getter function for private member variable data.
		Precondition: Node object is instantiated
		Postcondition: Value of private member variable data is returned
	**/
	T getData() const;

	/**
		Purpose: Getter function for private member variable link.
		Precondition: Node object is instantiated
		Postcondition: Value of private member variable link is returned
	**/
	Node<T>* getLink() const;
	// Private member variables
private:
	// data with type of template T
	T data;
	// link as pointer of this class to next node
	Node* link;
};

template <class T>
Node<T>::Node()
{
	// Set private member variable to value of default constructor of data type T
	data = T();
	// Set private member variable link to NULL
	link = NULL;
}

// Set value of private member variable data to given data
// Set value of private member variable nextNode to given nextNode 
template <class T>
Node<T>::Node(T data, Node<T>* nextNode) : data(data), link(nextNode)
{

}

template<class T>
void Node<T>::setData(T data)
{
	// Set value of private member variable data to given data
	this->data = data;
}

template<class T>
void Node<T>::setLink(Node<T>* nextNode)
{
	// Set value of private member variable link to given nextNode
	this->link = nextNode;
}

template<class T>
T Node<T>::getData() const
{
	// Return the value of private member variable data
	return data;
}

template<class T>
Node<T>* Node<T>::getLink() const
{
	// Return the value of private member variable link
	return link;
}
#endif