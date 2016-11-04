#ifndef FACULTY_CPP
#define FACULTY_CPP

#include "Person.h"
#include "Faculty.h"
#include <string>
using namespace std;

Faculty::Faculty() : Person()
{
    //Need to declare whatever advisees is
}

Faculty::~Faculty(){}

void Faculty::setID(const unsigned int n){}

void Faculty::setLevel(const std::string str){}

void Faculty::setAdvisees(){} //This method needs work depending on how we store advisees

void Faculty::setDept(const std::string str){dept = str;}

const int* Faculty::getAdvisees() const{return advisees;} //This also needs work

const std::string Faculty::getDept() const{return dept;}

void Faculty::operator=(const Faculty f)
{
    name = f.name;
    ID = f.ID;
    level = f.level;
    dept = f.dept;
    //Need to set advisees arrays equal to the other array
}

bool Faculty::operator==(const Faculty f){return (ID == f.ID);}

bool Faculty::operator<(const Faculty f){return (ID < f.ID);}

bool Faculty::operator>(const Faculty f){return (ID > f.ID);}

#endif //FACULTY_CPP
