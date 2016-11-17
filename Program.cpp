
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

Program::Program(){
  registrar = new Database("tranUpeguiStudent.txt","tranUpeguiFacult.txt");
}

Program::~Program(){}

void Program::printMenu(){
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
  int choice;
  cin>>choice;
  if(0<choice<15){}
  else{
    cout<<"invalid choice"<<endl;
    choice = 14;
  }
  UserInterface(choice);
}

void Program::UserInterface(int n){
  if(n == 1)//print all students
  {registrar->printAllStudents();}

  else if (n == 2)//print all faculty
  {registrar->printAllFaculty();}

  else if (n == 3)//find and display student
  {
    cout << "Please enter Student ID: " << endl;  
    int sid;
    cin>>sid;
    registrar->printStudentInfo(sid);
  }

  else if (n == 4)//find and display faculty
  {
    cout<<"Please enter Faculty ID: "<<endl;
    int fid;
    cin>>fid;
    registrar->printFacultyInfo(fid);
  }

  else if (n == 5)//print name and info of faculty advisor given student ID
  {
    cout<<"Please enter Student ID: "<<endl;
    int sid;
    cin>>sid;
    registrar->printAdvisor(sid);
  }

  else if (n == 6)//print name and info for student advisees
  {
    cout<<"Please enter Faculty ID: "<<endl;
    int fid;
    cin>>fid;
    registrar->printAdvisees(fid);
  }
  else if (n == 7)//add new student
  {
    cout<<"Please enter student name:"<<endl;
    std::string name;
    cin>>name;

    cout << "Please enter student major:" << endl;
    std::string major;
    cin>>major;

    cout << "Please enter student year:" << endl;
    std::string level;
    cin >> level;

    cout << "Please enter student GPA:" << endl;
    double gpa;
    cin >>gpa;

    cout << "Please enter student Advisor: " << endl;
    int advisor;
    cin >> advisor;

    Student s;
    s.setName(name);
    s.setMajor(major);
    s.setLevel(level);
    s.setGPA(gpa);
    s.setAdvisor(advisor);

    cout << "1" << endl;

    if(registrar -> addStudent(s))
    {
	cout << "Your student was added. Their ID number is " << s.getID() << "." << endl; 
    };
    
  }

  else if (n == 8)//delete studnet
  {
    cout << "Please enter student ID:" << endl;
    int sid;
    cin>>sid;
    
    if(registrar->deleteStudent(sid));
    {
	cout << "Your student was successfully deleted." << endl;
    }
  }

  else if (n == 9)//add new faculty
  {
    cout<<"Please enter faculty name:"<<endl;
    std::string name;
    cin>>name;

    cout << "Please enter faculty department:" << endl;
    std::string dept;
    cin>>dept;

    cout << "Please enter faculty title:" << endl;
    std::string level;
    cin >> level;

    cout << "Please enter number of faculty advisees:" << endl;
    int num;
    cin >> num;

    Faculty f;
    f.setName(name);
    f.setDept(dept);
    f.setLevel(level);
  
    if (num >= 0)
    {
	for (int i = 0; i++; i < num)
    	{
	    cout << "Please enter ID of student advisee #" << i <<":" << endl;
  	    int id;
 	    cin >> id;
	    f.addAdvisee(id);
	}
    }

    if(registrar->addFaculty(f))
    {
	cout << "Your faculty member was added. Their ID is " << f.getID() << "." << endl;
    }
  }

  else if (n == 10)//delete faculty
  {
    cout<<"What is the ID number of the faculty you would like to delete?"<<endl;
    int fid;
    cin>>fid;

    cout<<"What is the ID number of the faculty who will take over their advisees?"<<endl;
    int subid;
    cin>>subid;

    registrar->adoptOrphans(fid,subid);
    registrar->deleteFaculty(fid);
  }

  else if (n == 11)//Change Students advisor
  {
    cout<<"Please enter Student ID:"<<endl;
    int sid;
    cin>>sid;

    //print individual student information
    cout<<"Please enter new faculty ID or enter 1 to view of all existing faculty:"<<endl;
    int fid;
    cin>>fid;

    if(fid == 1){
      registrar->printAllFaculty();
      cout<<"Please enter new faculty ID for advisor:"<<endl;
      cin>>fid;
    }
    if(registrar->changeAdvisor(sid,fid))
    {
        cout << "The student's advisor was changed successfully." << endl;
    }
  }
 
 else if (n == 12)//remove advises from faculty
  {
    cout<<"What is the ID number of the faculty whose advisee you would like to remove?"<<endl;
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
      registrar->deleteStudent(sid);
    else
      registrar->changeAdvisor(sid,nid);
  }

  else if (n == 13)//rollback
  {
    registrar->rollBack();
  }

  else if(n ==14)//exit
  {
    registrar->save();
    cout<<"Goodnight Everybody!"<<endl;
    exit(1);
  }

  printMenu();
}
