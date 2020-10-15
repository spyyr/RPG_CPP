#include "Weapon.h"

Weapon::Weapon(std::string itemName, int itemPrice, double AttackValue, double _additionalCritChance) : IItem(itemName, itemPrice) 
{
	this->Attack = AttackValue;
	this->AdditionalCritChance = _additionalCritChance;
}

void Weapon::PrintItemProps()
{
	std::cout << "Weapon name: " << this->Name << '\n' <<
		"Item price: " << this->Price << '\n' <<
		"Attack: " << this->Attack << '\n' << '\n';
}

double Weapon::GetAttack()
{
	return this->Attack;
}

double Weapon::GetAdditionalCritChance()
{
	return this->AdditionalCritChance;
}
