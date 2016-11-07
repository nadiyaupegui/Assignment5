#ifndef FACULTY_CPP
#define FACULTY_CPP

#include "Person.h"
#include "Faculty.h"
#include "DList.h"
#include <string>
using namespace std;

Faculty::Faculty() : Person()
{
    //Need to declare whatever advisees is
}

Faculty::~Faculty(){}

void Faculty::setID(const unsigned int n){ID = n;}

void Faculty::setLevel(const std::string str){level = str;}

void Faculty::addAdvisee(const unsigned int n){advisees -> addFront(n);}

void Faculty::removeAdvisee(const unsigned int n){advisees -> remove(n);} //This method needs work depending on how we store advisees

void Faculty::setDept(const std::string str){dept = str;}

const DList<unsigned int>* Faculty::getAdvisees() const{return advisees;} //This also needs work

const std::string Faculty::getDept() const{return dept;}

void Faculty::operator=(const Faculty f)
{
    name = f.name;
    ID = f.ID;
    level = f.level;
    dept = f.dept;
    advisees = f.advisees;
}

bool Faculty::operator==(const Faculty f){return (ID == f.ID);}

bool Faculty::operator<(const Faculty f){return (ID < f.ID);}

bool Faculty::operator>(const Faculty f){return (ID > f.ID);}

#endif //FACULTY_CPP
