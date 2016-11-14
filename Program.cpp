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
}

Program::UserInterface(int n){
  if(n == 1)//print all students
  {}
  else if (n == 2)//print all faculty
  {}
  else if (n == 3)//find and display student
  {}
  else if (n == 4)//find and display faculty
  {}
  else if (n == 5)//print name and info of faculty advisor
  {}
  else if (n == 6)//print name and info for student advisees
  {}
  else if (n == 7)//add new student
  {}
  else if (n == 8)//delete studnet
  {}
  else if (n == 9)//add new faculty
  {}
  else if (n == 10)//delete faculty
  {}
  else if (n == 11)//Change Students advisor
  {}
  else if (n == 12)//remove advises from faculty
  {}
  else if (n == 13)//rollback
  {}
  else if(n ==14)//exit
  {}
}
