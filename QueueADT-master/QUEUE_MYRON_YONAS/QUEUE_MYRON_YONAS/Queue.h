/*
copy insert, delete and listlength functions from linkedlist class and convert to pop,push,and isempty function.
Only changes to the functions to make them pop and push is set position of insertion/deletion to 1.
isemtpy changed to return 1 or 0 whether the list is empty or not.
*/

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "List.h"

using namespace std;


template<class T>
class Queue :public linkedlist<T>
{
	linkedlist<T>* listptr;
public:
	Queue();
	void insert(T, int);//also take in user input of position in list they want to insert, Queue overide to insert to top of list only(dont use position input)
	void deletenode(int);//accept position to delete 
	int listlength();//ovveride in Queue for isempty()
	void front();
	void rear();
	void print();
};
template<class T>
Queue<T>::Queue()
{
	listptr = new linkedlist<T>;
}
/*
template insert function(to add to end of list)
if list isnt empty:
	create temp node ptr that equals to headptr's previous pointer, which always points to the last node
	set new node data
	set temp node ptr to point to new node, and new node to point to null
	length++
else if list empty
	set new node to null 
	set headptr's next pointer to new node instead of null
	lenght++

*/
template<class T>
void Queue<T>::insert(T z, int input)//Queue push
{
	Node<T>* newnode = new Node<T>();
	if (headptr->getnext() != NULL)
	{
		Node<T>* temp=headptr->getprevious();
		newnode->setdata(z);
		newnode->setnext(NULL);
		headptr->setprevious(newnode);
		temp->setnext(newnode);
		length++;
	}
	else
	{
		headptr->setprevious(newnode);
		headptr->setnext(newnode);
		newnode->setdata(z);
		newnode->setnext(NULL);
		length++;
	}
}
/*
To delete node at beginning of list:
set temp node ptr to point to headptr's next node
set headptr next ptr to point to temp's next node
delete temp
length--

*/
template <class T>
void Queue<T>::deletenode(int input)
{
	Node<T>*temp = headptr->getnext();
	headptr->setnext(temp->getnext());
	delete temp;
	length--;

	
}
template<class T>
int Queue<T>::listlength()
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
/*
display first node in queue
access headptr's next nodes's data

*/
template<class T>
void Queue<T>::front()
{
	
	cout << headptr->getnext()->getdata() << endl;
}
/*
display last node in queue
access headptr's previous node(last node in queue) data
(headptr->getprevious() always points to the last node in the queue
*/
template<class T>
void Queue<T>::rear()
{
	cout << headptr->getprevious()->getdata() << endl;
}
/*
display data of nodes until end of list
delete node being displayed 
*/
template <class T>
void Queue<T>::print()//print and delete nodes from stack top
{
	while (headptr->getnext())
	{
		cout << headptr->getnext()->getdata() << "-->";
		deletenode(1);
	}
	cout << "NULL" << endl;

}
#endif
