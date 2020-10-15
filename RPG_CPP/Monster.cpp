#include "Monster.h"

const std::map<int, int> Monster::GoldYieldLevelDependentScheme = {
	{1,3},
	{2,7},
	{3, 11},
	{4, 16},
	{5, 21},
	{6, 27}
};

Monster::Monster(std::string _name, int _hp, int _lvl, int _attck, double _defense, double _critChance, int _expYield) :Character(_name, _hp, _lvl, _attck, _defense, _critChance)
{
	this->ExpYield = _expYield;
	this->GoldYield = this->GoldYieldLevelDependentScheme.at(_lvl);
}
void Monster::PrintCharacterProps() 
{
	std::cout << "Name: " << this->Name << '\n' <<
		"HP: " << this->HP << '/' << this->MaxHP << '\n' <<
		"Attack: " << this->Attack << '\n' <<
		"Defense: " << this->Defense << '\n' <<
		"Crit chance: " << this->CritChance << '%' << '\n' <<
		"Lvl: " << this->Lvl << '\n' <<
		"Gold Yield after kill: " << this->GoldYield <<'\n' << '\n';
}

void Monster::Dead() 
{
	//system("cls");
	std::cout << this->Name << " is dead!. You got " << this->ExpYield << " exp points " <<
		" and " << this->GoldYield << " Gold points!'\n'";
	this->IsDead = true;
}

int Monster::GetExpYield() { return this->ExpYield; }

int Monster::GetGoldYield()
{
	return this->GoldYield;
}
