#include<iostream>
#include "Program.h"
using namespace std;
//a comment
class Input
{
private:
    // A reference to the base program; Through this we can access any class instances we need, like Output
    Program* referenceToProgram;
public:
    Input(Program* program);
};
