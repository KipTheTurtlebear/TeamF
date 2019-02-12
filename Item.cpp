#include "Item.h"

using namespace std;

Item::Item() : name("Default Item"), type(ItemType::power), energyQty(0), cost(0) {}

string Item::getName(void)
{
	return name;
}

ItemType Item::getType(void)
{
	return type;
}

int Item::getEnergyQty(void)
{
	return energyQty;
}

int Item::getCost(void)
{
	return cost;
}

void Item::setName(string value)
{
	name = value;
}

void Item::setType(ItemType value)
{
	type = value;
}

void Item::setEnergyQty(int value)
{
	energyQty = value;
}

void Item::setCost(int value)
{
	cost = value;
}