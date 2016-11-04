#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "Person.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

Student::Student() : Person(), advisor(0), gpa(-1){major = "";} //Why is major not setting with shortcut?

Student::~Student(){}

void Student::setID(const unsigned int n){ID = n;}

void Student::setLevel(const std::string str){level = str;}

void Student::setAdvisor(const unsigned int n){advisor = n;}

void Student::setGPA(const double n)
{
    if((n >= 0) && (n <= 4))
    {
	gpa = n;
    }
    else
    {
	cout << "Error Student::setGPA. Invalid GPA given." << endl;
	exit(1);
    }
}

void Student::setMajor(const std::string str) {major = str;}

const unsigned int Student::getAdvisor() const{return advisor;}

const double Student::getGPA() const{return gpa;}

const std::string Student::getMajor() const{return major;}

void Student::operator=(const Student s)
{
    name = s.name;
    ID = s.ID;
    level = s.level;
    advisor = s.advisor;
    gpa = s.gpa;
    major = s.major;
}

bool Student::operator==(const Student s){return (ID == s.ID);}

bool Student::operator<(const Student s){return (ID < s.ID);}

bool Student::operator>(const Student s) {return (ID > s.ID);}

#endif //STUDENT_CPP
