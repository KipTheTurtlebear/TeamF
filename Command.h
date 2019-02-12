#include<string>
#include "ClassDefinitions.h"
#include <vector>
using namespace std;

// The base class for any command
class Command
{
private:
    // A reference to the base program; Through this we can access any class instances we need, like Output
    Program* referenceToProgram;

public:
    Command(Program* program);

    virtual void Run(vector<string> arguments) = 0;
};