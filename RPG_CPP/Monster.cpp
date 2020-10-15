#include "Monster.h"

Monster::Monster(std::string _name, int _hp, int _lvl, int _attck, double _defense, int _expYield) :Character(_name, _hp, _lvl, _attck, _defense)
{
	this->ExpYield = _expYield;
	this->GoldYield = 3;
}
void Monster::PrintCharacterProps() 
{
	std::cout << "Name: " << this->Name << '\n' <<
		"HP: " << this->HP << '/' << this->MaxHP << '\n' <<
		"Attack: " << this->Attack << '\n' <<
		"Defense: " << this->Defense << '\n' <<
		"Lvl: " << this->Lvl << '\n' << '\n';
}

void Monster::Dead() 
{
	system("cls");
	std::cout << this->Name << " is dead!. You got " << this->ExpYield << " exp points!'\n'";
	this->IsDead = true;
}

int Monster::GetExpYield() { return this->ExpYield; }
