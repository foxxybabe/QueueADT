#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class linkedlist
{
protected://
	Node<T>* headptr;
	
public:
	int length;
	void printlist();
	void append(T);//adds to end of list,
	int locate(T);//return position, accept data
	void deletelist();
	linkedlist();
	virtual void insert(T, int);//also take in user input of position in list they want to insert, stack ovveride to insert to top of list only(dont use position input)
	virtual void deletenode(int);//accept position to delete 
	virtual int listlength();//ovveride in stack for isempty()
};
template <class T>
linkedlist<T>::linkedlist()
{
	headptr = new Node<T>;//creat a headnode and set headptr to point to the headnode
	length = 0;
	

}

/*printlist()
set temp to headptr
if temp->next ==NUll    (no data node)
	
else				(there is datanode)
	point temp to first datanode
	do
		print node data
		point temp to next node
		while temp != NULL   (there exist a node that follows)
	End Loop
	print "NULL"
end if
end method
*/
template <class T>
void linkedlist<T>::printlist()
{
	Node<T>* temp = headptr;//temporary pointer

	if (temp->getnext() == NULL)//if only one node in list(the head node/no data node)
	{
	}
	else//else if list has more than one node
	{
		temp = temp->getnext();//skip reading out head node;
		do
		{
			cout << temp->getdata() << "-->";
			temp = temp->getnext();
		} while (temp != NULL);
		cout << "NULL" << endl;
	}
}

/*append()
set z to parameter value
set newnode point to a new node
set node data to z
set node.next point to NULL
set temp point to headnode

if headnode points to a data node
	while data node points to other data node
		set temp point to next data node
	end loop

	set data node point to the new data node
	increment list length
else
	set headnode point to new data node
	increment list length
end if

end method
*/
template <class T>
void linkedlist<T>::append(T z)
{
	Node<T>* newnode = new Node<T>();//create a new node with constructor
	newnode->setdata(z);
	newnode->setnext(NULL);//set pointer to null since its new end of list

	Node<T>* temp = headptr;//temp pointer

	if (temp != NULL)//if nodes already in list
	{
		while (temp->getnext() != NULL)
		{
			temp = temp->getnext();//move temp pointer to last node
		}
		temp->setnext(newnode);//sets last node to point to new node
		length++;
	}
	else//if no other nodes in list, set new node as first thing in list
	{
		headptr->setnext(newnode);
		length++;
	}
}
/*insert()
set z to 1st par 
set input to 2nd par
set newnode point to a newnode
set newnode data to z
set prev point to headnode
set current point to headnode
set position to 0

if headnode points to a datanode
	while current node points to a datanode and position < input
		set prev to current
		set current point to net node
		increment position
	end loop
	if position == 0
		set current node point to newnode
		set newnode point to NULL
		increment list length
	else if current node points to null position +1 == input
		set current node point to newnode
		set newnode point to null
		increment list length
	else if position > input
		prompte user attempt failed 
	else
		set previous node point to newnode
		set newnode point to current node
		increment list length
	end if

else 
	set headptr point to newnode
	set newnode point to null
	increment list length
end if

end method

*/
template <class T>
void linkedlist<T>::insert(T z, int input)
{
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
		headptr->setnext( newnode);
		newnode->setnext(NULL);
		length++;
	}
}

/*deletenode()
set input to par value
set prev to headptr
set current to headptr
set position to 0

if headnode points to !Null
	while current node.next !=Null and position < input
		prev=current
		set current point to next node
		increment psition
	end loop
	if position == 0
		set previous node point to node after current
		decrement list length
		delete current node
	else if current node points to NULL and position == input
		set previous node point to NULL
		decrement list length
		delete current node
	else if position < input
		prompt user operation failed
	else
		set previous node point to node after current
		decrement list length
		delete current node
	end if
else
	prompt user list is empty
end if

end method
		
*/
template <class T>
void linkedlist<T>::deletenode(int input)
{
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
	else
	{
		cout << "List is empty, nothing to delete." << endl;
	}
}

/*locate()
set z to par value
set temp to headptr
set position to 0
while node data != z and position < length
	set temp point to next node
	increment position
end loop
if temp->data ==z
	return position
else
	return -1
end if
return -1
end method
*/
template <class T>
int linkedlist<T>::locate(T z)
{
	Node<T>* temp = headptr;

	int position = 0;
	while ((temp->getdata() != z) && (position<length))
	{
		temp = temp->getnext();
		position++;
	}
	if (temp->getdata() == z)
	{
		return position;
	}
	else
	{
		return -1;
	}
	return -1;//returns -1 if not found
 }


template <class T>
int linkedlist<T>::listlength()
{
	return length;
}
/*deletelist()
set current point to first datanode or null if no datanode
while current != NULL
	set headnode point to succeeding datanode
	set datanode point to NULL
	delete current datanode
	set current point to the next datanode
end loop
end method

*/
template <class T>
void linkedlist<T>::deletelist()
{
	Node<T>* current = headptr->getnext();

	while (current != NULL)
	{
		headptr->setnext(current->getnext());
		current->setnext(NULL);
		free(current);
		current = headptr->getnext();
	}
}


#endif