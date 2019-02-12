#include<iostream>
#include "ClassDefinitions.h"
using namespace std;

class Tile
{
private:
    // A reference to the base program; Through this we can access any class instances we need, like Output
    Program* referenceToProgram;
public:
    Tile(Program* program);
};