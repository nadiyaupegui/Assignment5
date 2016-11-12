#ifndef FACULTY_CPP
#define FACULTY_CPP

#include "Person.h"
#include "Faculty.h"
#include "DList.h"
#include <string>
using namespace std;

Faculty::Faculty() : Person()
{
    advisees = new DList<unsigned int>();
}

Faculty::Faculty(const unsigned int n) : Person()
{
    ID = n;
    advisees = new DList<unsigned int>();
}

Faculty::~Faculty()
{
    delete advisees;
}

void Faculty::setID(const unsigned int n){ID = n;}

void Faculty::setLevel(const std::string& str){level = str;}

void Faculty::addAdvisee(const unsigned int n){advisees -> addFront(n);}

void Faculty::removeAdvisee(const unsigned int n){advisees -> remove(n);} 

void Faculty::setDept(const std::string& str){dept = str;}

DList<unsigned int>* Faculty::getAdvisees() const{return advisees;} 

std::string Faculty::getDept() const{return dept;}

void Faculty::operator=(Faculty f)
{
    name = f.name;
    ID = f.ID;
    level = f.level;
    dept = f.dept;
    advisees = f.advisees;
}

bool Faculty::operator==(Faculty f){return (ID == f.ID);}

bool Faculty::operator!=(Faculty f){return (ID != f.ID);}

bool Faculty::operator<(Faculty f){return (ID < f.ID);}

bool Faculty::operator>(Faculty f){return (ID > f.ID);}

friend ostream& operator<<(ostream& os, Faculty f)
{
    os<<f.name<<"\n"<<f.ID<<"\n"<<f.level<<"\n"<<f.dept<<"\n"<<f.advisees->getSize()<<f.advisees;
    return os;
}
#endif //FACULTY_CPP
