#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include "DList.h"
#include <string>
using namespace std;

class Faculty : public Person
{
public:
    Faculty();
    ~Faculty();
    void setID(const unsigned int& n);
    void setLevel(const std::string& str);
    void addAdvisee(const unsigned int& n);
    void removeAdvisee(const unsigned int& n);
    void setDept(const std::string& str);

    const DList<unsigned int>* getAdvisees() const;
    const std::string getDept() const;

    void operator=(const Faculty f);
    bool operator==(const Faculty f);
    bool operator<(const Faculty f);
    bool operator>(const Faculty f);

private:
    DList<unsigned int>* advisees; //Maybe a doubly linked list instead? idk
    std::string dept;

};
#endif //FACULTY_H
