#ifndef PROGRAM_H
#define PROGRAM_H
#include "GenBST.h"
#include "GenStack.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
using namespace std;
class Program{
  public:
    Program();
    ~Program();
    void printMenu();
    void UserInterface(int n);
  private:
    Database* registrar;
};

#endif
