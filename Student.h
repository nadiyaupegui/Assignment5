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

    const unsigned int getAdvisor() const;
    const double getGPA() const ;
    const std::string getMajor() const;
    

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
#endif //STUDENT_H
