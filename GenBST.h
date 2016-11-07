#ifndef GENBST_H
#define GENBST_H

#include "TreeNode.h"

template <class T>
class GenBST
{
public:
    GenBST();
    ~GenBST();
    //Maybe include constructor that takes in root?
    void insert (const T& d);
    bool search(const T& value);
    bool remove(const T& value);
    void print(const TreeNode<T>* node); 

private:
    TreeNode<T>* root;
};

template <class T>
GenBST<T>::GenBST(){root = NULL;}

template <class T>
GenBST<T>::~GenBST(){}

template <class T>
void GenBST<T>::insert (const T& d)
{
    TreeNode<T>* node = new TreeNode(d);
    TreeNode<T>* parent;
    if (root == NULL)
	root = node;
    else
    {
	TreeNode<T>* curr = root;
	while (true)
	{
	    parent = curr;
	    if (d < curr -> data)
	    {
		curr -> left;
		if (curr == NULL)
		{
	  	    parent-> left = node;
		    break;
		}
	    }
	    else if (d > curr -> data)
   	    {
		curr -> right;
		if (curr == NULL)
		{
		    parent -> right = node;
		    break;
		}
  	    }
	}
}

template <class T>
bool GenBST<T>::search(const T& value){}

template <class T>
bool GenBST<T>::remove(const T& value){}


template <class T>
void GenBST<T>::print(const TreeNode<T>* node)
{
    if (node == NULL)
	return;
	
    print(node -> left);
    cout << node -> data << endl;
    print (node -> right);
}

#endif //GENBST_H
