#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "Person.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

Student::Student() : Person(), advisor(0), gpa(-1){major = "";} //Why is major not setting with shortcut?

Student::Student(const unsigned int n) : Person(), advisor(0), gpa(-1) 
{
    major = "";
    ID = n;
}

Student::~Student(){}

void Student::setID(const unsigned int n){ID = n;}

void Student::setLevel(const std::string& str){level = str;}

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

void Student::setMajor(const std::string& str) {major = str;}

unsigned int Student::getAdvisor() const{return advisor;}

double Student::getGPA() const{return gpa;}

std::string Student::getMajor() const{return major;}

ostream& Student::output(ostream& os) const
{
	os<<ID<<"\n"<<name<<"\n"<<level<<"\n"<<advisor<<"\n"<<gpa<<"\n"<<major;
	return os;
}

void Student::operator=(Student s)
{
    name = s.name;
    ID = s.ID;
    level = s.level;
    advisor = s.advisor;
    gpa = s.gpa;
    major = s.major;
}

bool Student::operator==(Student s){return (ID == s.ID);}

bool Student::operator!=(Student s){return (ID != s.ID);}

bool Student::operator<(Student s){return (ID < s.ID);}

bool Student::operator>(Student s) {return (ID > s.ID);}

#endif //STUDENT_CPP
