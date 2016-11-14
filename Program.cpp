Program::Program(){}

Program::~Program(){}

Program::printMenu(){
  cout<<"What would you like to do?"<<endl;
  cout<<"(1) \t Print Students"<<endl;
  cout<<"(2) \t Print Faculty"<<endl;
  cout<<"(3) \t Find Student"<<endl;
  cout<<"(4) \t Find Faculty"<<endl;
  cout<<"(5) \t Print Student's Advisor Info"<<endl;
  cout<<"(6) \t Print Faculty Advisee Info"<<endl;
  cout<<"(7) \t Add New Student"<<endl;
  cout<<"(8) \t Delete Student"<<endl;
  cout<<"(9) \t Add New Faculty"<<endl;
  cout<<"(10) \t Delete Faculty"<<endl;
  cout<<"(11) \t Change Student's advisor"<<endl;
  cout<<"(12) \t Remove an advisee from a faculty member"<<endl;
  cout<<"(13) \t Rollback"<<endl;
  cout<<"(14) \t Exit"


Program::UserInterface(int n){
  if(n == 1)//print all students
  {registrar->printAllStudents();}
  else if (n == 2)//print all faculty
  {registrar->printAllFaculty();}
  else if (n == 3)//find and display student
  {}
  else if (n == 4)//find and display faculty
  {}
  else if (n == 5)//print name and info of faculty advisor
  {}
  else if (n == 6)//print name and info for student advisees
  {}
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
    //assign all the variables and see if the advisees work.
    registrar->deleteStudent(sid);
  }
  else if (n == 9)//add new faculty
  {
    int fid;
    cin>>fid;
    Faculty f(fid);
    registrar->addFaculty(f);
  }
  else if (n == 10)//delete faculty

    int fid;
    cin>>fid;
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
    if(registrar->existsFaculty(fid)&&registrar->existsStudent(sid)){
      registrar->changeAdvisor(sid,fid);
    }
    //fix this later
  }
  else if (n == 12)//remove advises from faculty
  {
    //iterate through list of advisees
      //print student info
      //request faculty input
      //reassign
  }
  else if (n == 13)//rollback
  {}
  else if(n ==14)//exit
  {}
}
