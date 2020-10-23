#include "IItem.h"

IItem::IItem(std::string _name, int _price)
{
	this->Name = _name;
	this->Price = _price;
	this->IsStackable = false;
}

void IItem::PrintBasicItemProps()
{
	std::cout << typeid(*this).name() << "\nItem name: " << this->Name << '\n' <<
		"Price: " << this->Price << '\n';
	system("Pause");
}

std::string IItem::GetItemName()
{
	return this->Name;
}

void IItem::SetName(std::string name)
{
	this->Name = name;
}

bool IItem::GetIsStackable()
{
	return this->IsStackable;
}
