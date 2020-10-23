#include "IPotion.h"

IPotion::IPotion(std::string _name, int _price): IItem(_name, _price)
{
	this->IsStackable = true;
}
