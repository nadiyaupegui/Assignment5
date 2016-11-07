#ifndef DNODE_H
#define DNODE_H

#include <cstdlib>

template <class T>
class DNode
{
public:
    DNode();
    DNode(const T& d);
    ~DNode();
    T data;
    DNode* prev;
    DNode* next;
};

template <class T>
DNode<T>::DNode() : prev(NULL), next(NULL){}

template <class T>
DNode<T>::DNode(const T& d) : data(d), prev (NULL), next(NULL){}

template <class T>
DNode<T>::~DNode()
{
    delete prev;
    delete next;
}

#endif //DNODE_H
