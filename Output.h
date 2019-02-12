#include<iostream>
#include "Program.h"
using namespace std;

class Output
{
private:
    // A reference to the base program; Through this we can access any class instances we need, like Output
    Program* referenceToProgram;
public:
    Output(Program* program)
    {
        // Establish our reference to the main program
        referenceToProgram = program;
    }

    void Print(string stringToPrint)
    {
        cout << stringToPrint.c_str() << endl;
    }
};