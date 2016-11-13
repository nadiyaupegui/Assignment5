#ifndef DATABASE_H
#define DATABASE_H

#include "GenBST.h"
#include "GenStack.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
using namespace std;

class Database
{
public:
    Database();
    Database(std::string sFile, std::string fFile);
    ~Database();

    void printStudents(const TreeNode<Student>* node) const; //Must be sorted by ascending order
    void printFaculty(const TreeNode<Faculty>* node) const; //Must be sorted by ascending order
    void printStudentInfo(const unsigned int n) const; //Finds and displays student info given ID
    void printFacultyInfo(const unsigned int n) const; //Finds and displays student info given ID
    void printAdvisor(const unsigned int n) const; //Print the name and info of advisor
    void printAdvisees(const unsigned int n) const; //Prints ALL advisees of given faculty ID

    bool addStudent(Student s); //Adds a student and must create a new ID for them
    bool deleteStudent(const unsigned int n); //Deletes student given ID MUST CHECK ADVISEES OF FACULTY
    bool addFaculty(); //Adds a new faculty member, and must create a new ID for them
    bool deleteFaculty(const unsigned int n); //Deletes a faculty member given ID
    bool changeAdvisor(const unsigned int sid, const unsigned int fid); //Change student advisor to new faculty member 
    bool removeAdvisee(const unsigned int fid, const unsigned int sid); //Removes an advisee of a faculty member 
    void rollBack(); //Should roll back trees to last instances of it

private:
    GenBST<Student>* masterStudent;
    GenBST<Faculty>* masterFaculty;
    GenStack<GenBST<Student> >* rollBackStudent;
    GenStack<GenBST<Faculty> >* rollBackFaculty;   
    std::string studentFile;
    std::string facultyFile;

    //Helper methods
    bool goodSID(unsigned int n);
    bool goodFID(unsigned int n);
};

#endif //DATABASE_H
