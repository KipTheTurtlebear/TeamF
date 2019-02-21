#ifndef WORLD
#define WORLD
#include<iostream>
#include "ClassDefinitions.h"
using namespace std;

class World
{
private:
    Program* referenceToProgram; // A reference to the base program; Through this we can access any class instances we need, like Output
    Tile * map;
public:
    World(Program* program)
    {
        referenceToProgram = program; // Establish our reference to the main program
    }
   // Tile * GetTileAtLoc(int x, int y);
    World * GenerateWorld(int szX, int szY, int seed, Program * program);
    

};
#endif
