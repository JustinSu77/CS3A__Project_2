/**
	Name: Justin Su
	Date: 11/28/2023
	Assignment Title: Project #2
	Purpose: Node.h for Project #2
**/
#ifndef NODE_H
#define NODE_H

// Templated Node class
	template<typename T>
	class Node
	{
		public:
			Node();
			Node(T data, Node* node);
			void setData(T data);
			void setLink(Node* nextNode);
			T getData() const;
			Node<T>* getLink() const;
		private:
			T data;
			Node* link;
	};

	template <typename T>
	Node<T>::Node()
	{
		data = NULL;
		link = nullptr;
	}

	template <typename T>
	Node<T>::Node(T data, Node* nextNode) : data(data), link(nextNode)
	{

	}

	template<typename T>
	void Node<T>::setData(T data)
	{
		this->data = data;
	}

	template<typename T>
	void Node<T>::setLink(Node* nextNode)
	{
		this->link = nextNode;
	}

	template<typename T>
	T Node<T>::getData() const
	{
		return data;
	}

	template<typename T>
	Node<T>* Node<T>::getLink() const
	{
		return link;
	}
#endif
 


 




