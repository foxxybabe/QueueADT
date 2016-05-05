#ifndef NODE_H
#define NODE_H


#include <iostream>

using namespace std;

template<class T>
class Node
{
protected://
	T data;
	Node* next;//pointer to next node
	Node* previous;

public:
	Node();
	void setdata(T);
	void setnext(Node*);
	void setprevious(Node*);
	T getdata();
	Node* getnext();
	Node* getprevious();//only used for headptr, points to last node in list
};
template <class T>
Node<T>::Node(){}

template <class T>
void Node<T>::setdata(T z)
{
	data = z;
}
template <class T>

void Node<T>::setnext(Node* newnode)
{
	next = newnode;
}
template <class T>
void Node<T>::setprevious(Node* newnode)
{
	previous = newnode;
}
template <class T>
T Node<T>::getdata()
{
	return data;
}
template <class T>
Node<T>* Node<T>::getnext()
{
	return next;
}
template <class T>
Node<T>* Node<T>::getprevious()
{
	return previous;
}


#endif