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
    std::ostream& output(std::ostream& os) const;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const DNode<T> node)
{
    return node.output(os);
}
   
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

template <class T>
std::ostream& DNode<T>::output(std::ostream& os) const
{
    os<<data;
    return os;
}
#endif //DNODE_H
