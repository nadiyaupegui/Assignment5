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
    Faculty(const unsigned int n);
    ~Faculty();
    void setID(const unsigned int n);
    void setLevel(const std::string& str);
    void addAdvisee(const unsigned int n);
    void removeAdvisee(const unsigned int n);
    void setDept(const std::string& str);

    DList<unsigned int>* getAdvisees() const;
    std::string getDept() const;
    ostream& output(ostream& os);
    void operator=(Faculty f);
    bool operator==(Faculty f);
    bool operator!=(Faculty f);
    bool operator<(Faculty f);
    bool operator>(Faculty f);
    friend ostream& operator<<(ostream& os, Faculty f)
    {
        return f.output(os);
    }
private:
    DList<unsigned int>* advisees; //Maybe a doubly linked list instead? idk
    std::string dept;

};


#endif //FACULTY_H
