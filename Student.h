#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student : public Person
{
public:
    Student();
    Student(const unsigned int n);
    ~Student();
    void setID(const unsigned int n);
    void setLevel(const std::string& str);
    void setAdvisor(const unsigned int n);
    void setGPA(const double n);
    void setMajor(const std::string& str);

    unsigned int getAdvisor() const;
    double getGPA() const ;
    std::string getMajor() const;
    

    void operator=(Student s);
    bool operator==(Student s);
    bool operator!=(Student s);
    bool operator<(Student s);
    bool operator>(Student s);

private:
    unsigned int advisor;
    double gpa;
    std::string major;
};

ostream& operator<<(ostream& os, Student s)
{
	os<<s.name<<"\n"<<s.ID<<"\n"<<s.level<<"\n"<<s.advisor<<"\n"<<s.gpa<<"\n"<<s.major;
}

#endif //STUDENT_H
