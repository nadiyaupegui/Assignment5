#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
public:
    Person();
    ~Person();
    void setName(const std::string str);
    virtual void setID(const unsigned int n) = 0;
    virtual void setLevel(const std::string str) = 0;
    const std::string getName() const;
    const unsigned int getID() const;
    const std::string getLevel()const;

private:
    std::string name;
    unsigned int ID; 
    std::string level;
};

#endif //PERSON_H
