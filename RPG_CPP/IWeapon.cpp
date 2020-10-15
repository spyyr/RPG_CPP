#include "IWeapon.h"

IWeapon::IWeapon(std::string itemName, int itemPrice, double AttackValue) : IItem(itemName, itemPrice) 
{
	this->Attack = AttackValue;
}

void IWeapon::PrintItemProps()
{
	std::cout << "Weapon name: " << this->Name << '\n' <<
		"Item price: " << this->Price << '\n' <<
		"Attack: " << this->Attack << '\n' << '\n';
}

double IWeapon::GetAttack()
{
	return this->Attack;
}
