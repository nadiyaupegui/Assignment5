#include "Person.h"
#include "Faculty.h"
#include "GenList.h"
#include "DNode.h"
#include "DList.h"
#include "TreeNode.h"
#include "GenBST.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    GenBST<int>* test = new GenBST<int>(); 
    test -> insert(8);
    test -> insert(6);
    test -> insert(15);
    test -> insert(5);
    test -> insert(7);
    test -> insert(13);
    test -> insert(17);
    test -> insert(12);
    
    cout << "Tree 1" << endl; 
    test -> print(test -> getRoot());

    cout << "Remove 10" << endl;
    test -> remove(10);
    
    cout << "Tree 2" << endl;
    test -> print(test -> getRoot());
    
    return 0;
}
