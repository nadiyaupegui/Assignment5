#ifndef PERSON_CPP
#define PERSON_CPP

#include "Person.h"
#include <string>
using namespace std;

Person::Person(): name(""), ID(0), level("") {}

Person::~Person(){}

void Person::setName(const std::string str){name = str;}

const std::string Person::getName() const{return name;} 

const unsigned int Person::getID() const{return ID;}

const std::string Person::getLevel()const{return level;}

#endif //PERSON_CPP

