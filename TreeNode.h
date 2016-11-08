#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>

template <class T>
class TreeNode
{
public:
    TreeNode();
    TreeNode(const T& d);
    ~TreeNode();
    
    T data; 
    TreeNode<T>* left;
    TreeNode<T>* right;
};
template <class T>
TreeNode<T>::TreeNode()
{
    left = NULL;
    right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(const T& d)
{
    left = NULL;
    right = NULL;
    data = d;
}

template <class T>
TreeNode<T>::~TreeNode()
{
    delete left;
    delete right;
}

#endif //TREENODE_H
