#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "GenBST.h"
#include "TreeNode.h"
#include "GenStack.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "Database.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Database::Database() : studentFile(""), facultyFile("")
{
    rollBackStudent = new GenStack<GenBST<Student> >();
    rollBackFaculty = new GenStack<GenBST<Faculty> >();
    masterStudent = new GenBST<Student>();
    masterFaculty = new GenBST<Faculty>();
}

Database::Database(std::string sFile, std::string fFile) : studentFile(sFile), facultyFile(fFile)
{
    rollBackStudent = new GenStack<GenBST<Student> >();
    rollBackFaculty = new GenStack<GenBST<Faculty> >();
    masterStudent = new GenBST<Student>();
    masterFaculty = new GenBST<Faculty>();
}

Database::~Database()
{
    delete rollBackStudent;
    delete rollBackFaculty;
    delete masterFaculty;
    delete masterStudent;
}

void Database::printStudents(const TreeNode<Student>* node) const
{
     if (node == NULL)
	return;

     cout << node -> data << endl;
     printStudents(node -> left);
     printStudents(node -> right);
}

void Database::printFaculty(const TreeNode<Faculty>* node) const
{
   if (node == NULL)
	return;

    cout << node -> data << endl;
    printFaculty(node -> left);
    printFaculty(node -> right);
}

void Database::printStudentInfo(const unsigned int n) const
{
    TreeNode<Student>* node = new TreeNode<Student>();
    Student s(n);
    node = masterStudent -> search(s);
    if (node == NULL)
    {
	cout << "No student with ID number "<< n << " found in database." << endl;
    }
    else
    {
	cout << "ID: " << node -> data.getID() << endl;
        cout << "Name: " << node -> data.getName() << endl;
	cout << "Year: " << node -> data.getLevel() << endl;
	cout << "Major: " << node -> data.getMajor() << endl;
        cout << "GPA: " << node -> data.getGPA() << endl;
	cout << "Advisor ID: " << node -> data.getAdvisor() << endl;
    }
    node = NULL;
    delete node;
}

void Database::printFacultyInfo(const unsigned int n) const
{
    TreeNode<Faculty>* node = new TreeNode<Faculty>();
    Faculty f(n);
    node = masterFaculty -> search(f);
    if (node == NULL)
    {
        cout << "No faculty member with ID number "<< n << " found in database." << endl;
    }
    else
    {
        cout << "ID: " << node -> data.getID() << endl;
        cout << "Name: " << node -> data.getName() << endl;
        cout << "Level: " << node -> data.getLevel() << endl;
        cout << "Department: " << node -> data.getDept() << endl;
	cout << "Advisees: " << endl;
	cout << node -> data.getAdvisees() << endl;
    }
    node = NULL;
    delete node;
}

void Database::printAdvisor(const unsigned int n) const
{
    //Need to check if student ID is ok
    Student s(n);
    int c = masterStudent -> search(s) -> data.getAdvisor();
    cout << "Advisor Info for Student ID " << n << ":" << endl;
    printFacultyInfo(c);
}

void Database::printAdvisees(const unsigned int n) const
{
    //Need to check if faculty ID si ok
    Faculty f(n);
    DList<unsigned int>* list = masterFaculty -> search(n) -> data.getAdvisees();
    cout << "Advisees' Info for Faculty ID " << n << ":" << endl;
    int size = list -> getSize();
    for (int i = 0; i < size; ++i)
    {
	printStudentInfo(list -> front());
	list -> addBack(list -> front());
	list -> removeFront();
    }  
}

bool Database::addStudent(Student s)
{
    //Assuming there is no ID to begin with
    unsigned int n = masterStudent -> getMax().getID() + 1; //Do modular arithmentic;
    while (true)
    {
        s.setID(n);
        if(masterStudent -> search(s) == NULL)
    	{
	    masterStudent -> insert(s);
	    return true;
    	}
        n += 1; //Do modular arithmentic
    }
}

bool Database::deleteStudent(const unsigned int n)
{
    //Check if student number is good
    Student s(n);
    return (masterStudent -> remove(s));  
}

bool Database::addFaculty(Faculty f)
{
    //Assuming there is no ID to begin with
    unsigned int n = masterFaculty -> getMax().getID() + 1; //Do modular arithmentic;
    while (true)
    {
        f.setID(n);
        if(masterFaculty -> search(f) == NULL)
    	{
	    masterFaculty -> insert(f);
	    return true;
    	}
        n += 1; //Do modular arithmentic
    }
}

bool Database::deleteFaculty(const unsigned int n)
{
    //Check if faculty number is good
    Faculty f(n);
    return (masterFaculty -> remove(f));
}

bool Database::changeAdvisor(const unsigned int sid, const unsigned int fid)
{
    Student s(sid);
    int a = masterStudent -> search(s) -> data.getAdvisor();
    
    //Check that fid is in database
    masterStudent -> search(s) -> data.setAdvisor(fid);

    if (a != 0)
    {
        Faculty oldAd(a);
        masterFaculty -> search(oldAd) -> data.removeAdvisee(sid);
    }

    Faculty newAd(fid);
    masterFaculty -> search(newAd) -> data.addAdvisee(sid);
} 

bool Database::removeAdvisee(const unsigned int fid, const unsigned int sid)
{
    //Check that adviess and faculty numbers are in database
    Faculty f(fid);
    masterFaculty -> search(f) -> data.removeAdvisee(sid);
    
    Student s(sid);
    masterStudent -> search(s) -> data.setAdvisor(0);
} 

void Database::rollBack()
{
    //Lots to do with this...
}

//Helper methods

bool Database::goodSID(unsigned int n){return n < 3000000;}

bool Database::goodFID(unsigned int n)
{
    return ((n >= 3000000) && (n < 5000000));
}

bool Database::existsStudent(unsigned int n) const
{
    Student s(n);
    TreeNode<Student>* node = masterStudent -> search(s);
    if (node == NULL)
    {
	return false;
    }
    return true;
}

bool Database::existsFaculty(unsigned int n) const
{
    Faculty f(n);
    TreeNode<Faculty>* node = masterFaculty -> search(f);
    if (node == NULL)
    {
        return false;
    }
    return true;
}

#endif //DATABASE_CPP
