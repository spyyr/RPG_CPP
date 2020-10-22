#include "IItem.h"

IItem::IItem(std::string _name, int _price)
{
	this->Name = _name;
	this->Price = _price;
}

std::string IItem::GetItemName()
{
	return this->Name;
}

void IItem::SetName(std::string name)
{
	this->Name = name;
}
