#include <string>

enum class ItemType
{
	//Boat allows passing water
	//Tool allows breaking obstacles
	//Bino allows vision of 2 squares instead of 1
	//power allows energy increase
	boat,tool,bino,power
};

class Item
{
private:
	std::string name;		//objects in game description
	ItemType type;			//object type as enum
	int energyQty;			//Works both ways, if tool, decreses energy consumption by this amount, if power, increases heros energy by this amount.
	int cost;				//how much money is needed to purchase.

public:
	//Constructors
	Item();

	//Getters
	std::string getName(void);
	ItemType getType(void);
	int getEnergyQty(void);
	int getCost(void);

	//Setters
	void setName(std::string value);
	void setType(ItemType value);
	void setEnergyQty(int value);
	void setCost(int value);

};