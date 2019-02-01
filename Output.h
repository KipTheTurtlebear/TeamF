#include <iostream>
#include <ncurses.h>
#include <list>
#include "ClassDefinitions.h"
using namespace std;

#define GRASS           ' '
#define TRAIL           '.'
#define WATER           '~'
#define MOUNTAIN        '^'
#define PLAYER          '$'

#define GRASS_PAIR      1
#define WATER_PAIR      GRASS_PAIR+1
#define MOUNTAIN_PAIR   WATER_PAIR+1
#define PLAYER_PAIR     MOUNTAIN_PAIR+1
#define BORDER_PAIR     PLAYER_PAIR+1
#define TEXT_PAIR       BORDER_PAIR+1
#define INPUT_PAIR      TEXT_PAIR+1
#define TXTBOX_PAIR     INPUT_PAIR+1 

#define MAX_MESSAGES    12        // These two values will determine the size
#define MIN_MESSAGE_LENGTH 80     // of the text window on-screen, as well as 
                                  // the size of the message buffer
class Output
{
private:
    Program* referenceToProgram; // A reference to the base program; Through this we can access any class instances we need, like Output
    int x=0, y=0;
    int txtX=0, txtY=0;
    int inputLen=0;
    WINDOW * txt;   // Text output, when messages are printed they go to this window
    list <char*> messageBuffer;
    string inputCh;   // Current input chars, before user hits enter

    void UpdateMap();
    void PrintBorder(int,int);
    void InitCurses();
    void PrintText();
public:
    Output(Program* program)
    {
        referenceToProgram = program; // Establish our reference to the main program
        InitCurses();
    }

    void Print(string stringToPrint);   // Call this to print a message on-screen in the proper window
    void Cleanup();                       // This is to clean up when closing the program
    void InputChar(char * c);           // When user wants to type input, call this
};                                      // Example: User presses the 'a' key, so call InputChar('a');
                                        // Code in here will send a string to the parser and  
                                        // print to the screen when enter is pressed
