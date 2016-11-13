#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <cstdlib> //for exit
#include "DNode.h"
#include "GenList.h"
using std::cout;
using std::endl;

template <class T> 
class DList : public GenList<T>

{
public:
    DList();
    ~DList();
    bool empty() const;
    const T front() const;
    const T back() const;
    void addFront(const T& d);
    void addBack(const T& d);
    void removeFront();
    void removeBack();
    void remove(const T& key);
    int search(const T& key) const;
    unsigned int getSize() const;
    ostream& output(ostream& os);
    void operator=(const DList<T>* copy);
    friend class DNode<T>;

private:
    DNode<T>* head;
    DNode<T>* tail;
    unsigned int size;
};

template <class T>
ostream& operator<<(ostream& os, DList<T>* list)
{
	return list->output(os);
}

template <class T>
DList<T>::DList() : size(0)
{
    head = new DNode<T>();
    head = NULL;

    tail = new DNode<T>();
    tail = NULL;
}

template <class T>
DList<T>::~DList()
{
    while(!empty())
    {
	removeFront();
    }
    delete head;
    delete tail;
}

template <class T>
bool DList<T>::empty() const {return size == 0;}

template <class T>
const T DList<T>::front() const 
{
    if (empty())
    {
	cout << "Error DList::front(). Empty list." << endl;
	exit(1);
    }
    return (head -> data);
}

template <class T>
const T DList<T>::back() const
{
    if(empty())
    {
	cout << "Error DList::back(). Empty list." << endl;
	exit(1);
    }
    return (tail -> data);
}

template <class T>
void DList<T>::addFront(const T& d)
{
    DNode<T>* node = new DNode<T>(d);
    if (empty())
    {
	tail = node;
    }
    else
    {
	head -> prev = node;
	node -> next = head;
    }
    head = node;
    size++;
}

template <class T>
void DList<T>::addBack(const T& d)
{

    DNode<T>* node = new DNode<T>(d);
    if (empty())
    {
	head = node;
    }
    else
    {
	tail -> next = node;
	
	node -> prev = tail;
    }	
    tail = node;
    size++;
}

template <class T>
void DList<T>::removeFront()
{
    if(empty())
    {
	cout << "Error DList()::removeFront(). Empty list." << endl;
	exit(1);
    }

    DNode<T>* oldFront = head;
    if (head == tail)
    {
	tail = NULL;
    }
    else
    {
	(head -> next) -> prev = NULL;
    }
    head = head -> next;
    oldFront -> next = NULL;
    delete oldFront;
    size--;
}

template <class T>
void DList<T>::removeBack()
{
    if(empty())
    {
        cout << "Error DList()::removeBack(). Empty list." << endl;
        exit(1);
    }

    DNode<T>* oldBack = tail;
    if (head == tail)
    {
        head = NULL;
    }

    else
    {
        (tail -> prev) -> next = NULL;
    }

    tail = tail -> prev;
    oldBack -> prev = NULL;
    delete oldBack;
    size--;

}

template <class T>
void DList<T>::remove(const T& key)
{

    if (empty())
    {
	cout << "Error DList::Remove(). Empty List." << endl;
	exit(1);
    }

    DNode<T>* current = head;
    while (current -> data != key)
     {
	current = current -> next;
	if (current == NULL)
	{
	    return;
	}
    }

    if (current == head)
    {
 	head = current -> next;
    }

    else 
    {
	current -> prev -> next = current -> next;
    }

    if (current == tail)
    {
	tail = current -> prev;
    }
    else
    {
	current -> next -> prev = current -> prev;
    }

	current -> next = NULL;
	current -> prev = NULL;
	size--;
}

template <class T>
int DList<T>::search(const T& key) const
{
    if (empty())
    {
	cout << "Error DList::search(). Empty list." << endl;
	exit(1);
    }

    DNode<T>* current = head; 
    for (int i = 0; i < size; ++i)
    {
	if(current -> data == key)
	{
	    return i;
	}	

	current = current -> next;
    }
    return -1;
}

template <class T>
unsigned int DList<T>::getSize() const {return size;}


template <class T>
void DList<T>::operator=(const DList<T>* copy)
{
    DList<T>* temp = new DList<T>();

     while (!empty())
    {
	removeBack();
    } 

    while (!copy.empty())
    {
	addFront(copy -> back());
	temp -> addFront(copy -> back());
	copy -> removeBack();
    }
	
	
    copy = temp;
    temp = NULL;
    delete temp;
}

template <class T>
ostream& DList<T>::output(ostream& os)
{
    DList<T>* temp = new DList<T>();
    while (!empty())
    {
	 os<<head->data<<"\n";
	 temp -> addFront(front());
	 removeFront();
    }
    while(!temp->empty())
    {
	addFront(temp->front());
	temp->removeFront();
    }
	return os;
}
#endif //DLIST_H
