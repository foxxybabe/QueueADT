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
class Stack:public linkedlist<T>
{
	linkedlist<T>* listptr;
public:
	Stack();
	void insert(T, int);//also take in user input of position in list they want to insert, stack overide to insert to top of list only(dont use position input)
	void deletenode(int);//accept position to delete 
	int listlength();//ovveride in stack for isempty()
	void print();
	T peek();
};
template<class T>
Stack<T>::Stack()
{
	listptr = new linkedlist<T>;
}
template <class T>
void Stack<T>::print()//print and delete nodes from stack top
{
	while (headptr->getnext())
	{
		cout << headptr->getnext()->getdata() << "-->";
		deletenode(1);
	}
	cout << "NULL" << endl;

}
template<class T>
void Stack<T>::insert(T z, int input)//stack push
{
	input = 1;//adds to top of stack (not 0 because that is the head node)
	Node<T>* newnode = new Node<T>();
	newnode->setdata(z);
	Node<T>* prev = headptr;//temp ptr
	Node<T>* current = headptr;// temp ptr
	int position = 0;

	if (headptr->getnext() != NULL)
	{
		while (current->getnext() != NULL && position < input)
		{
			prev = current;
			current = current->getnext();
			position++;
		}
		if (position == 0)
		{
			current->setnext(newnode);
			newnode->setnext(NULL);
			length++;
		}
		else if ((current->getnext() == NULL) && (position + 1 == input))
		{
			current->setnext(newnode);
			newnode->setnext(NULL);
			length++;
		}
		else if (position < input)
		{
			cout << "Out of bounds, cannot add." << endl;
		}
		else
		{
			prev->setnext(newnode);
			newnode->setnext(current);
			length++;
		}
	}
	else
	{
		headptr->setnext(newnode);
		newnode->setnext(NULL);
		length++;
	}
}
template <class T>
void Stack<T>::deletenode(int input)
{
	input = 1;//stack always removes from top of list, so input set to 1
	Node<T> *prev = headptr;
	Node<T> *current = headptr;//temp nodes

	int position = 0;

	if (headptr->getnext() != NULL)
	{
		while (current->getnext() != NULL && position < input)//move current and prev pointers to position
		{
			prev = current;
			current = current->getnext();
			position++;
		}
		if (position == 0)
		{
			prev->setnext(current->getnext());
			length--;
			delete current;
		}
		else if ((current->getnext() == NULL) && (position == input))
		{
			prev->setnext(NULL);
			length--;
			delete current;
		}
		else if (position < input)
		{
			cout << "Out of bounds, can not delete." << endl;
		}
		else
		{
			prev->setnext(current->getnext());
			length--;
			delete current;
		}
	}
	/*else
	{
		cout << "Stack is empty, nothing to delete." << endl;
	}*/
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
T Stack<T>::peek()
{
	return headptr->getnext()->getdata();
}


#endif
