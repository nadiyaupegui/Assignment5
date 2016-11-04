#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>
using namespace std;

class Faculty : public Person
{
public:
    Faculty();
    ~Faculty();
    void setID(const unsigned int n);
    void setLevel(const std::string str);
    void setAdvisees(const unsigned int n);
    void setDept(const std::string str);

    const int* getAdvisees() const;
    const std::string getDept() const;

    void operator=(const Faculty f);
    bool operator==(const Faculty f);
    bool operator<(const Faculty f);
    bool operator>(const Faculty f);

private:
    int* advisees;
    std::string dept;

};
#endif //FACULTY_H
