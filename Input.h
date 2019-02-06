#include<iostream>
#include "ClassDefinitions.h"
using namespace std;

class Input
{
private:
    // A reference to the base program; Through this we can access any class instances we need, like Output
    Program* referenceToProgram;
    //we can use the direction keys and immediately update or collect text from the console emulator
    int mode;
    char ** text;
    Input(); // no copying me
public:
    Input(Program* program);
    ~Input();
    void getInput();

}
