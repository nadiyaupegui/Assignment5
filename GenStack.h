//Template Stack class
#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <cstdlib>
#include "StackEmpty.h"

template <class T>
class GenStack
{
public:

    GenStack(); 
    GenStack(int s); //Takes capacity of array
    ~GenStack();

    void push(const T& data);
    void pop() throw (StackEmpty);
    T& peek() const throw (StackEmpty); //Returns top element of stack
    int getSize() const;
    int getCap() const;
    bool empty() const;
    

private:

    T* arr; //Array for stack
    int top;
    int capacity;
    void increaseCap(); //Automatically doubles array size if out of room
};

//Default constructor: Sets capacity to 10
template <class T>
GenStack<T>::GenStack():capacity(10), top(-1)
{
    arr = new T[capacity];
}

//Takes in intial capacity as input
template <class T>
GenStack<T>::GenStack(int c): capacity(c), top(-1)
{
    arr = new T[capacity];
}

//Destructor
template <class T>
GenStack<T>::~GenStack()
{
    delete [] arr;
}

//Pushes element onto stack
template <class T>
void GenStack<T>::push(const T& data)
{
    if (getSize() == capacity)
    {
        increaseCap();
    }

    arr[++top] = data;
}

//Pops element off stack
//Throws StackEmpty if stack is empty
template <class T>
void GenStack<T>::pop() throw (StackEmpty)
{
    if(empty())
    {
	throw (StackEmpty("Error: Cannot pop from an empty stack.")); 
    }
    else
    {
        --top;
    }
}

//Returns top element of stack
template <class T>
T& GenStack<T>::peek() const throw (StackEmpty)
{
    if (empty())
    {	    
        cout << "It made the throw block" << endl;
 	throw (StackEmpty("Error: Cannot peek from an empty stack."));
    }

    return arr[top];
}

//Returns size of stack      
template <class T>
int GenStack<T>::getSize() const{ return (top + 1);}

//Returns capacity of array
template <class T>
int GenStack<T>::getCap() const {return capacity;}

//Returns true if stack is empty
template <class T>
bool GenStack<T>::empty() const
{
    return (top < 0);
}

//Increases the size of stack array
template <class T>
void GenStack<T>::increaseCap()
{
    capacity *= 2;
    T* temp = new T[capacity];
    for (int i = 0; i < (capacity / 2); ++i)
    {
        temp[i] = arr[i];
    }

    T* old = arr;
    arr = temp;
    temp = NULL;
    old = NULL;
    delete temp;
    delete old;
}

#endif //GENSTACK_H
