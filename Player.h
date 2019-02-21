#include <string>
#include <vector>
#include "Item.h"


class Player
{
private:
	std::string name;
	int energy;
	int money;
	std::pair<int,int> coordinates;
	std::vector<Item> inventory;

public:
	//Constructor
	Player();

	//Getters
	int getMoney(void);
	int getEnergy(void);
	std::pair<int, int> getCoordinates(void);
	int getXCoordinate(void);
	int getYCoordinate(void);

	//Setters
	void setMoney(int value);
	void setEnergy(int value);
	void setCoordinates(std::pair<int, int> value);
	void setXCoordinate(int value);
	void setYCoordinate(int value);

	//Inventory control. If using an item, true means success, false means the item did not exist in inventory
	//If adding an item true means the item was successfully added, false means it failed for some reason.
	bool useItem(int id);
	bool useItem(std::string name);
	bool addItemToInventory(Item item);



};