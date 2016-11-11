//Class to handle Stack Empty exception

#include <string>
class StackEmpty
{
public:
    StackEmpty(const string& e):err(e){}
    std::string getError() {return err;}

private:
    std::string err;
};
