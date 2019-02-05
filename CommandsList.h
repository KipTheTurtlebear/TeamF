#include "ClassDefinitions.h"
#include<map>
#include<string>
using namespace std;

class CommandsList
{
private:
    // A reference to the base program; Through this we can access any class instances we need, like Output
    Program* referenceToProgram;
public:
    // The dictionary of all possible commands
    map<string, Command> listOfCommands;

    CommandsList(Program* program);
};
