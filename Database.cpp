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

void Database::printAllStudents() const {printStudents(masterStudent -> getRoot());}

void Database::printStudents(const TreeNode<Student>* node) const
{
     if (node == NULL)
	return;
     cout << "ID: " << node -> data.getID() << endl;
     cout << "Name: " << node -> data.getName() << endl;
     cout << "Year: " << node -> data.getLevel() << endl;
     cout << "Major: " << node -> data.getMajor() << endl;
     cout << "GPA: " << node -> data.getGPA() << endl;
     cout << "Advisor ID: " << node -> data.getAdvisor() << endl;
     printStudents(node -> left);
     printStudents(node -> right);
}
void Database::printAllFaculty() const {printFaculty(masterFaculty -> getRoot());}

void Database::printFaculty(const TreeNode<Faculty>* node) const
{
   if (node == NULL)
	return;

    
        cout << "ID: " << node -> data.getID() << endl;
        cout << "Name: " << node -> data.getName() << endl;
        cout << "Level: " << node -> data.getLevel() << endl;
        cout << "Department: " << node -> data.getDept() << endl;
	cout << "Advisees: " << endl;
	cout << node -> data.getAdvisees();    printFaculty(node -> left);
    printFaculty(node -> right);
}

void Database::printStudentInfo(const unsigned int n) const
{
    if(!goodSID(n))
    {
	cout << "Invalid student ID number given." << endl;
	return;
    }
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
    if(!goodFID(n))
    {
	cout << "Invalid faculty ID number given." << endl;
	return;
    }
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
	cout << node -> data.getAdvisees();
    }
    node = NULL;
    delete node;
}

void Database::printAdvisor(const unsigned int n) const
{
    if(!goodSID(n))
    {
	cout << "Invalid student ID number given." << endl;
	return;
    }
	
    if(!existsStudent(n))
    {
	cout << "Student ID given does not exist." << endl;
	return;
    }

    Student s(n);
    int c = masterStudent -> search(s) -> data.getAdvisor();
    cout << "Advisor Info for Student ID " << n << ":" << endl;
    printFacultyInfo(c);
}

void Database::printAdvisees(const unsigned int n) const
{
    if(!goodFID(n))
    {
	cout << "Invalid faculty ID number given." << endl;
	return;
    }
	
    if(!existsFaculty(n))
    {
	cout << "Faculty ID given does not exist." << endl;
	return;
    }
	
    Faculty f(n);
    DList<unsigned int>* list = masterFaculty -> search(f) -> data.getAdvisees();
    cout << "Advisees' Info for Faculty ID " << n << ":" << endl;
    int size = list -> getSize();
    for (int i = 0; i < size; ++i)
    {
	printStudentInfo(list -> front());
	list -> addBack(list -> front());
	list -> removeFront();
    }  
}

void Database::adoptOrphans(const unsigned int n,const unsigned int m){
	//reassigns all of faculty n's advisees to faculty m
	if(!goodFID(n))
    	{
		cout << "Invalid faculty ID number given." << endl;
		return;
    	}
	
    if(!existsFaculty(n))
    {
	cout << "Faculty ID given does not exist." << endl;
	return;
    }
	Faculty f(n);
	Faculty sub(m);
	DList<unsigned int>* list = masterFaculty -> search(f)-> data.getAdvisees();
	int size = list-> getSize();
	Student s;
	for (int i = 0; i<size; ++i)
	{
		s.setID(list->front());
		masterStudent->search(s)->data.setAdvisor(m);
		masterFaculty -> search(sub)->data.addAdvisee(list->front());
		list->addBack(list->front());
		list->removeFront();
	}
}

bool Database::addStudent(Student s)
{
    if(masterStudent -> getSize() == 1000000)
    {
	cout << "Max capacity of database reached. Cannot add student." << endl;
	return false;
    }
    
    rollBackStudent -> push(*masterStudent);
    rollBackFaculty -> push(*masterFaculty);

    unsigned int n = (masterStudent -> getMax().getID() + 1) % 1000000 + 2000000;
    while (true)
    {
        s.setID(n);
        if(masterStudent -> search(s) == NULL)
    	{
	    masterStudent -> insert(s);
	    return true;
    	}
        (n += 1) % 1000000 + 2000000;
    }
}

bool Database::deleteStudent(const unsigned int n)
{
    if(!goodSID(n))
    {
	cout << "Invalid student ID number given." << endl;
	return false;
    }

    rollBackStudent -> push(*masterStudent);
    rollBackFaculty -> push(*masterFaculty);

    Student s(n);
    return (masterStudent -> remove(s));  
}

bool Database::addFaculty(Faculty f)
{
    if (masterFaculty -> getSize() == 1000000)
    {
	cout << "Max capacity of database reached. Cannot add facutly." << endl;
	return false;
    }

    rollBackStudent -> push(*masterStudent);
    rollBackFaculty -> push(*masterFaculty);

    unsigned int n = (masterFaculty -> getMax().getID() + 1) % 1000000 + 4000000;
    while (true)
    {
        f.setID(n);
        if(masterFaculty -> search(f) == NULL)
    	{
	    masterFaculty -> insert(f);
	    return true;
    	}
        (n += 1) % 1000000 + 4000000;
    }
}

bool Database::deleteFaculty(const unsigned int n)
{
    if(!goodFID(n))
    {
	cout << "Invalid faculty ID number given." << endl;
	return false;
    }

    rollBackStudent -> push(*masterStudent);
    rollBackFaculty -> push(*masterFaculty);

    Faculty f(n);
    return (masterFaculty -> remove(f));
}

bool Database::changeAdvisor(const unsigned int sid, const unsigned int fid)
{
    if(!goodSID(sid))
    {
	cout << "Invalid student ID number given." << endl;
	return false;
    }
    if(!goodFID(fid))
    {
	cout << "Invalid faculty ID number given." << endl;
	return false;
    }
    if (!existsStudent(sid))
    {
	cout << "Student ID given not in database." << endl;
	return false;
    }
    if (!existsFaculty(fid))
    {
	cout << "Faculty ID given not in database." << endl;
	return false;
    }

    rollBackStudent -> push(*masterStudent);
    rollBackFaculty -> push(*masterFaculty);   

    Student s(sid);
    int a = masterStudent -> search(s) -> data.getAdvisor();
    
    masterStudent -> search(s) -> data.setAdvisor(fid);

    if (a != 0)
    {
        Faculty oldAd(a);
        masterFaculty -> search(oldAd) -> data.removeAdvisee(sid);
    }

    Faculty newAd(fid);
    masterFaculty -> search(newAd) -> data.addAdvisee(sid);
    return true;
} 

bool Database::removeAdvisee(const unsigned int fid, const unsigned int sid)
{
    if(!goodSID(sid))
    {
	cout << "Invalid student ID number given." << endl;
	return false;
    }
    if(!goodFID(fid))
    {
	cout << "Invalid faculty ID number given." << endl;
	return false;
    }
    if (!existsStudent(sid))
    {
	cout << "Student ID given not in database." << endl;
	return false;
    }
    if (!existsFaculty(fid))
    {
	cout << "Faculty ID given not in database." << endl;
	return false;
    }
	
    rollBackStudent -> push(*masterStudent);
    rollBackFaculty -> push(*masterFaculty);

    Faculty f(fid);
    masterFaculty -> search(f) -> data.removeAdvisee(sid);
    
    Student s(sid);
    masterStudent -> search(s) -> data.setAdvisor(0);
} 

void Database::rollBack()
{
    *masterStudent = rollBackStudent -> peek();
    *masterFaculty = rollBackFaculty -> peek();

    rollBackStudent -> pop();
    rollBackFaculty -> pop(); 
}

//Helper methods

bool Database::goodSID(unsigned int n) const
{
    return ((n >= 2000000) && (n < 3000000));
}

bool Database::goodFID(unsigned int n) const
{
    return ((n >= 4000000) && (n < 5000000));
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

void Database::save()
{
	masterFaculty->saveTree();
	masterStudent->saveTree();
}

#endif //DATABASE_CPP
