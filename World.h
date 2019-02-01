#include "ClassDefinitions.h"
#include<iostream>
using namespace std;

class World
{
private:
    Program* referenceToProgram; // A reference to the base program; Through this we can access any class instances we need, like Output
public:
    World(Program* program)
    {
        referenceToProgram = program; // Establish our reference to the main program
    }
};
