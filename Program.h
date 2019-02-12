#include "ClassDefinitions.h"
#include "Parser.h"
#include "Input.h"
#include "Output.h"
#include "World.h"

using namespace std;

class Program
{
public:
    Parser* parser;
    Input* input;
    Output* output;
    World* world;

    Program()
    {
        parser = new Parser(this);
        output = new Output(this);
        world = new World(this);
        input = new Input(this);
    }
};