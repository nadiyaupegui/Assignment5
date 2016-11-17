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
    bool setGPA(const double n);
    void setMajor(const std::string& str);

    unsigned int getAdvisor() const;
    double getGPA() const ;
    std::string getMajor() const;
    ostream& output(ostream& os) const;

    void operator=(Student s);
    bool operator==(Student s);
    bool operator!=(Student s);
    bool operator<(Student s);
    bool operator>(Student s);
    friend ostream& operator<<(ostream& os, Student s)
    {
	return s.output(os);
    }

private:
    unsigned int advisor;
    double gpa;
    std::string major;
};


#endif //STUDENT_H
