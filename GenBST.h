#ifndef GENBST_H
#define GENBST_H

#include "TreeNode.h"

template <class T>
class GenBST
{
public:
    GenBST();
    GenBST(const T d);
    ~GenBST();

    bool empty() const;
    unsigned int getSize() const;
    const TreeNode<T>* getRoot() const;

    void insert (const T d);
    bool search(const T d) const;
    TreeNode<T>* getSuccessor(TreeNode<T>* d);
    bool remove(const T d);
    void print(const TreeNode<T>* node) const; 
    void deleteTree(TreeNode<T>* node);

private:
    TreeNode<T>* root;
    unsigned int size;
};

template <class T>
GenBST<T>::GenBST():size(0) 
{
    root = new TreeNode<T>();
    root = NULL;
}

template <class T>
GenBST<T>::GenBST(const T d)
{
    TreeNode<T>* node = new TreeNode<T>(d);
    root = node;
    size = 1;
}

template <class T>
GenBST<T>::~GenBST()
{
    deleteTree(root); 
}

template <class T>
bool GenBST<T>::empty() const {return size == 0;}

template <class T>
unsigned int GenBST<T>::getSize() const {return size;}

template <class T>
const TreeNode<T>* GenBST<T>::getRoot() const{return root;}

template <class T>
void GenBST<T>::insert(const T d)
{
    TreeNode<T>* node = new TreeNode<T>(d);
    TreeNode<T>* parent;
    size++;

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
		curr = curr -> left;
		if (curr == NULL)
		{
	  	    parent-> left = node;
		    break;
		}
	    }
	    else if (d > curr -> data)
   	    {
		curr = curr -> right;
		if (curr == NULL)
		{
		    parent -> right = node;
		    break;
		}
  	    }
	}
    }
}

template <class T>
bool GenBST<T>::search(const T d) const
{
    TreeNode<T>* curr = root;
    if (root == NULL)
        return false;
    else
    {
        while (d != curr -> data)
        {
            if (d < curr -> data)
            {
                curr -> left;
                if (curr == NULL)
                {
                    return false;
                }
            }
            else if (d > curr -> data)
            {
                curr -> right;
                if (curr == NULL)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

template <class T>
TreeNode<T>* GenBST<T>::getSuccessor(TreeNode<T>* node)
{
	TreeNode<T>* sp = node;
	TreeNode<T>* succ = node -> right;
	TreeNode<T>* curr = node -> right -> left;

	while (curr != NULL)
	{
	    	sp = succ;
	    	succ = curr;
		curr = curr -> left;
	}
	
	if(succ != node -> right)
	{
	    sp -> left = succ -> right;
	    succ -> left = node -> left;
	    succ -> right = node -> right;
	
	}
	else
	{
	    succ -> left = node -> left;
	}
	
	node -> left = NULL;
 	node -> right = NULL;
	
	return succ;
}


template <class T>
bool GenBST<T>::remove(const T d)
{
    //Checks for empty tree
    if (root == NULL)
    {
	return false;
    }	

    TreeNode<T>* curr = root;
    TreeNode<T>* parent = root;
    bool isLeft = true;
   
    //Finds node to delete, or returns false if not found
    while (true) 
    {
    	parent = curr;
    	if (curr == NULL)
	{
	    return false; //No obect was found
	}

  	else if (d < curr -> data)
	{
   	    curr = curr -> left;	
 	    isLeft = true;
	}
	else if (d > curr -> data)
	{
	    curr = curr -> right;
	    isLeft = false;
	}

        else if (d == curr -> data)
	{
	    break;
	}
    }

    //Removal of node with no children
    if ((curr -> left == NULL) && (curr -> right == NULL))
    {
	if (curr == root)
	    root = NULL;
	else if (isLeft)
	    parent -> left = NULL;
	else
	    parent -> right = NULL;
    }
 
    //Removal of node with left child
    else if (curr -> right == NULL)
    {
        if (curr == root)	
   	    root = curr -> left;
        else if(isLeft)
	    parent -> left = curr -> left;
        else
	    parent -> right = curr -> left;
    }

    //Removal of node with right child
    else if (curr -> left == NULL)
    {
        if (curr == root)
            root = curr -> right;
        else if(isLeft)
            parent -> left = curr -> right;
        else
            parent -> right = curr -> right;
    }

    //Removal of node with two children
    else 
    {
	TreeNode<T>* succ = getSuccessor(curr);

	if(curr == root)
	    root = succ;
	else if(isLeft)
	    parent -> left = succ;
	else
	    parent -> right = succ;
    }
       
    delete curr;
    size--;
    
    return true;
}

template <class T>
void GenBST<T>::print(const TreeNode<T>* node) const
{
    if (node == NULL)
	return;
        
    cout << node -> data << endl;
    print(node -> left);
    print(node -> right);
}

template <class T>
void GenBST<T>::deleteTree(TreeNode<T>* node)
{
    if (node -> left != NULL)
    	deleteTree(node -> left);
    if (node -> right != NULL)
    	deleteTree(node -> right);
    delete node;
}
#endif //GENBST_H
