#include "Player.h"

using namespace std;

//Default constructor with initilizer lists 
Player::Player() : name("Hero1"), energy(0), money(0), inventory(0) {}

//Gets the players energy amount
//Returns an int representing players energy amount
int Player::getEnergy(void)
{
	return energy;
}

//Gets how much money the player has
//Returns an int representing the players money
int Player::getMoney(void)
{
	return money;
}

//Gets the players coordinates as an X,Y pair.
//Returns a std::pair<int,int> 
std::pair<int, int> Player::getCoordinates(void)
{
	return coordinates;
}

//Gets the players X coordinate.
//Returns an int representing the players X coordinate.
int Player::getXCoordinate(void)
{
	coordinates.first;
}

//Gets the players Y coordinate.
//Returns an int representing the players Y coordinate.
int Player::getYCoordinate(void)
{
	coordinates.second;
}

//Sets the players energy level
//Takes an int representing the players energy level.
void Player::setEnergy(int value)
{
	energy = value;
}

//Sets the players money level
//Takes an int representing the players money level.
void Player::setMoney(int value)
{
	money = value;
}

//Sets the players X,Y coordinate pair
//Takes a std::pair<int,int> representing the players X,Y Coordinates
void Player::setCoordinates(std::pair<int, int> value)
{
	coordinates.first = value.first;
	coordinates.second = value.second;
}

//Sets the players X coordinate
//Takes an int represnting the players X coordinate
void Player::setXCoordinate(int value)
{
	coordinates.first = value;
}

//Sets the players Y coordinate
//Takes an int represnting the players Y coordinate
void Player::setYCoordinate(int value)
{
	coordinates.second = value;
}