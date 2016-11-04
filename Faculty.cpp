#ifndef FACULTY_CPP
#define FACULTY_CPP

#include "Person.h"
#include "Faculty.h"
#include <string>
using namespace std;

Faculty::Faculty(){}

Faculty::~Faculty(){}

void Faculty::setID(const unsigned int n){}

void Faculty::setLevel(const std::string str){}

void Faculty::setAdvisees(const unsigned int n){}

void Faculty::setDept(const std::string str){}

const int* Faculty::getAdvisees() const{}

const std::string Faculty::getDept() const{}

void Faculty::operator=(const Faculty f){}

bool Faculty::operator==(const Faculty f){}

bool Faculty::operator<(const Faculty f){}

bool Faculty::operator>(const Faculty f){}

#endif //FACULTY_CPP
