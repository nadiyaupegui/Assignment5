
#include "GenBST.h"
#include "TreeNode.h"
#include "GenStack.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "Database.h"
#include "Program.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Program::Program(){}

Program::~Program(){}

Program::printMenu(){
  cout<<"What would you like to do?"<<endl;
  cout<<"(1) \t Print Students"<<endl;
  cout<<"(2) \t Print Faculty"<<endl;
  cout<<"(3) \t Find Student and show information"<<endl;
  cout<<"(4) \t Find Faculty and show information"<<endl;
  cout<<"(5) \t Print Student's Advisor Info"<<endl;
  cout<<"(6) \t Print Faculty Advisee Info"<<endl;
  cout<<"(7) \t Add New Student"<<endl;
  cout<<"(8) \t Delete Student"<<endl;
  cout<<"(9) \t Add New Faculty"<<endl;
  cout<<"(10) \t Delete Faculty"<<endl;
  cout<<"(11) \t Change Student's advisor"<<endl;
  cout<<"(12) \t Remove an advisee from a faculty member"<<endl;
  cout<<"(13) \t Rollback"<<endl;
  cout<<"(14) \t Exit"<<endl;
}

Program::UserInterface(int n){
  if(n == 1)//print all students
  {registrar->printAllStudents();}
  else if (n == 2)//print all faculty
  {registrar->printAllFaculty();}
  else if (n == 3)//find and display student
  {
    cout<<"Please enter Student ID"<<endl;
    int sid;
    cin>>sid;
    registrar->printStudentInfo(sid);
  }
  else if (n == 4)//find and display faculty
  {
    cout<<"Please enter Faculty ID"<<endl;
    int fid;
    cin>>fid;
    registrar->printFacultyInfo(fid);
  }
  else if (n == 5)//print name and info of faculty advisor given student ID
  {
    cout<<"Please enter Student ID"<<endl;
    int sid;
    cin>>sid;
    printAdvisor(sid);
  }
  else if (n == 6)//print name and info for student advisees
  {
    cout<<"Please enter Faculty ID"<<endl;
    int fid;
    cin>>fid;
    printAdvisees(fid);
  }
  else if (n == 7)//add new student
  {
    int sid;
    cin>>sid;
    Student s(sid);
    registrar->addStudent(s);
  }
  else if (n == 8)//delete studnet
  {
    int sid;
    cin>>sid;
    registrar->deleteStudent(sid);
    //need to remove student from advisee list of faculty
  }
  else if (n == 9)//add new faculty
  {
    int fid;
    cin>>fid;
    Faculty f(fid);
    registrar->addFaculty(f);
  }
  else if (n == 10)//delete faculty
  {
    cout<<"What is the id number of the faculty you would like to delete?"<<endl;
    int fid;
    cin>>fid;
    cout<<"What is the id number of the faculty who will take over their advisees?"<<endl;
    int subid;
    cin>>subid;
    registrar->adoptOrphans(fid,subid);
    registrar->deleteFaculty(fid);
  }
  else if (n == 11)//Change Students advisor
  {
    cout<<"Please enter Student ID"<<endl;
    int sid;
    cin>>sid;
    //print individual student information
    cout<<"Please enter new faculty ID or enter 1 to view of all existing Faculty"<<endl;
    int fid;
    cin>>fid;
    if(fid == 1){
      registrar->printAllFaculty();
      cout<<"PLease enter new faculty ID for advisor"<<endl;
      cin>>fid;
    }
      registrar->changeAdvisor(sid,fid);
      registrar->removeAdvisee(fid,sid);
    //fix this later
  }
  else if (n == 12)//remove advises from faculty
  {
    cout<<"What is the ID number of the faculty you would like to remove?"<<endl;
    int fid;
    cin>>fid;
    registrar->printAdvisees(fid);
    cout<<"what is the ID number of the student you would like to remove?"<<endl;
    int sid;
    cin>>sid;
    registrar->removeAdvisee(fid,sid);
    cout<<"What is the ID number of the student's new faculty advisor? Enter 1 to delete the student."<<endl;
    int nid;
    cin>>nid;
    if(nid==1)
      registrar->deleteStudent();
    else
      registrar->changeAdvisor(sid,nid);
  }
  else if (n == 13)//rollback
  {
    registrar->rollback();
  }
  else if(n ==14)//exit
  {
    registrar->save();
    exit(1);
  }
}
