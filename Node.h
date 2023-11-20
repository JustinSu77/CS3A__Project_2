#pragma once
template<typename T>
class Node
{
public:
	Node();
	Node(T data, Node* nextNode);
	void setData(T data);
	void setLink(Node* nextNode);
	T getData() const;
	Node* getLink() const;
private:
	T data;
	Node* link;
};

template <typename T>
Node<T>::Node()
{
	data = NULL;
	link = NULL;
}

template <typename T>
Node<T>::Node(T data, Node* nextNode)
{
	this->data = data;
	this->link = nextNode;
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
	return nullptr;
}

 


 




