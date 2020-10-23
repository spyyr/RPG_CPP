#include "Armor.h"

Armor::Armor(std::string _name, int _price, double ArmorValue):IItem(_name, _price)
{
	this->ArmorValue = ArmorValue;
	this->IsStackable = false;
}

void Armor::PrintItemProps()
{
	std::cout << "Weapon name: " << this->Name << '\n' <<
		"Item price: " << this->Price << '\n' <<
		"Armor: " << this->ArmorValue << '\n' << '\n';
}

double Armor::GetArmorValue()
{
	return this->ArmorValue;
}

std::unique_ptr<IItem> Armor::clone() const
{
	return std::make_unique<Armor>(*this);
}

Armor* Armor::cpy()
{
	return new Armor(*this);
}
