#ifndef SHOP.H

#include "ClassDefinitions.h"
#include<iostream>
#include <vector>

using namespace std;

class Shop
{
private:
    // A reference to the base program; Through this we can access any class instances we need, like Output
    Program* referenceToProgram;
    
    bool  hasMoney(int);          // Check if hero has enough money
    bool  hasItem(int);           // Check if hero has item already
    void  showMenu();             // Display Menu
    void  getInput();             // Placeholder if special input required
    void  giveItem(int);          // Give item to hero.  NOTE: Check w/ Hero class how managed.
public:
    Shop(Program* program);
    Shop();
    ~Shop();
    
    void  open();                 // Opens Shop and controls flow until closed.
    int   initAdd(vector<int>&);  // Handle intial item add to shop.
                                  // NOTE: Double check w/ item class & config how user defined items are managed.

};

#endif // SHOP.H
