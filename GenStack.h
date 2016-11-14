//Template Stack class
#ifndef GENSTACK_H
#define GENSTACK_H

#include "DNode.h"
#include "DList.h"
#include <iostream>
#include <cstdlib>
#include "StackEmpty.h"

template <class T>
class GenStack
{
public:

    GenStack(); 
    GenStack(int c); //Takes capacity of array
    ~GenStack();

    void setCap(const unsigned int n);
    void push(const T data);
    void pop();
    T peek() const; //Returns top element of stack
    int getSize() const;
    int getCap() const;
    bool empty() const;
    

private:
    DList<T>* list; //Array for stack
    unsigned int capacity;
};

//Default constructor: Sets capacity to 10
template <class T>
GenStack<T>::GenStack():capacity(5)
{
    list = new DList<T>();
}

//Takes in intial capacity as input
template <class T>
GenStack<T>::GenStack(int c): capacity(c)
{
    list = new DList<T>();
}

//Destructor
template <class T>
GenStack<T>::~GenStack()
{
    delete list;
}

template <class T>
void GenStack<T>::setCap(const unsigned int n)
{
    if (n <= 0)
    {
	cout << "Invalid capacity value given." << endl;
	exit(1);
    }
    capacity = n;
}

//Pushes element onto stack
template <class T>
void GenStack<T>::push(const T data)
{
    if (getSize() == capacity)
    {
        list -> removeBack();
    }

    list -> addFront(data);
}

//Pops element off of stack
template <class T>
void GenStack<T>::pop()
{
    if(empty())
    {
	cout << "Stack empty. Cannot pop element." << endl;
	exit(1);
    }
    else
    {
        list -> removeFront();
    }
}

//Returns top element of stack
template <class T>
T GenStack<T>::peek() const
{
    if (empty())
    {	    
        cout << "Stack empty. Cannot peek element." << endl;
 	exit(1);
    }

    return list -> front();
}

//Returns size of stack      
template <class T>
int GenStack<T>::getSize() const {return (list -> getSize());}

//Returns capacity of array
template <class T>
int GenStack<T>::getCap() const {return capacity;}

//Returns true if stack is empty
template <class T>
bool GenStack<T>::empty() const
{
    return (list -> getSize() == 0);
}

#endif //GENSTACK_H
