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

Database::Database()
{
    rollBackStudent = new GenStack<GenBST<Student> >();
    rollBackFaculty = new GenStack<GenBST<Faculty> >();
    masterStudent = new GenBST<Student>();
    masterFaculty = new GenBST<Faculty>();
}

Database::Database(std::string studentFile, std::string facultyFile){}

Database::~Database()
{
    delete rollBackStudent;
    delete rollBackFaculty;
    delete masterFaculty;
    delete masterStudent;
}

void Database::printStudents() const{}

void Database::printFaculty() const{}

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
	cout << "Name: " << node -> data.getName() << endl;
	cout << "ID: " << node -> data.getID() << endl;
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
        cout << "Name: " << node -> data.getName() << endl;
        cout << "ID: " << node -> data.getID() << endl;
        cout << "Level: " << node -> data.getLevel() << endl;
        cout << "Department: " << node -> data.getDept() << endl;
	cout << "Advisees: " << endl;
	//node -> data.getAdvisees.print();
	// Need to make the print method and overload the << operator
    }
    node = NULL;
    delete node;
}

void Database::printAdvisor(const unsigned int n) const
{
    Student s(n);
    int c = masterStudent -> search(s) -> data.getAdvisor();
    cout << "Faculty Info for Student ID " << n << ":" << endl;
    printFacultyInfo(c);
}

void Database::printAdvisees(const unsigned int n) const{}

bool Database::addStudent(){}

bool Database::deleteStudent(const unsigned int n){}

bool Database::addFaculty(){}

bool Database::deleteFaculty(const unsigned int n){}

bool Database::changeAdvisor(const unsigned int sid, const unsigned int fid){} 

bool Database::removeAdvisee(const unsigned int fid, const unsigned int sid){} 

void Database::rollBack(){}

//Helper methods

bool Database::goodSID(unsigned int n){return n < 3000000;}

bool Database::goodFID(unsigned int n){return ((n >= 3000000) && (n < 5000000));}

#endif //DATABASE_CPP
