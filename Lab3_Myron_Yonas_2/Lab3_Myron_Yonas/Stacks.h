/*
copy insert, delete and listlength functions from linkedlist class and convert to pop,push,and isempty function.
Only changes to the functions to make them pop and push is set position of insertion/deletion to 1.
isemtpy changed to return 1 or 0 whether the list is empty or not.
*/

#ifndef STACKS_H
#define STACKS_H
#include <iostream>
#include "List.h"

using namespace std;


template<class T>
class Stack:protected linkedlist<T>
{
	linkedlist<T>* listptr;
public:
	Stack();
	void push(T);//also take in user input of position in list they want to insert, stack overide to insert to top of list only(dont use position input)
	void pop();//accept position to delete 
	int listlength();//ovveride in stack for isempty()
	void print();
	T peek();
};
template<class T>
Stack<T>::Stack()
{
	listptr = new linkedlist<T>;
}
template<class T>
void Stack<T>::push(T z)//stack push
{
	insert(z, 1);
}
template <class T>
void Stack<T>::pop()
{
	if (headptr->getnext() != NULL)
	{
		deletenode(1);
	}

}
template<class T>
int Stack<T>::listlength()
{
	if (length == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
template<class T>
void Stack<T>::print()
{
	while (headptr->getnext())
	{
		cout << headptr->getnext()->getdata() << "-->";
		pop();
	}
	cout << "NULL" << endl;

}

template<class T>
T Stack<T>::peek()
{
	return headptr->getnext()->getdata();
}

#endif
