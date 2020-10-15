#include "Human.h"

const std::map<int, int> Human::LevelingExpScheme = {
	{1,20},
	{2,50},
	{3, 100},
	{4, 200},
	{5, 400},
	{6, 1000}
};

Human::Human(std::string _name, int _hp, int _mp, int _lvl, double _defense) :Character(_name, _hp, 1, 7, _defense)
{	
	this->MP = _mp;	
	this->MaxMP = _mp;
	this->LvlExpBound = LevelingExpScheme.at(_lvl);
	if (_lvl == 1)
		this->Exp = 0;
	else
	{
		this->Exp = LevelingExpScheme.at(_lvl - 1);
		for (int i = 1; i < _lvl; i++)
		{
			this->LevelUp();
		}		
	}
	this->EqAddAttack = 0;
	this->Gold = 0;
	this->Exp = 0;
}

Human::Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, int _exp, int _gold):Human(_name, _hp, _mp, _lvl, _defense)
{
	this->Exp = _exp;
	this->Gold = _gold;
}

void Human::PrintCharacterProps() 
{
	std::cout << "Name: " << this->Name << '\n' <<
		"HP: " << this->HP << '/' << this->MaxHP << '\n' <<
		"MP: " << this->MP << '/' << this->MaxMP << '\n' <<
		"Attack: " << this->Attack << " + (" << this->EqAddAttack << ")" << '\n' <<
		"Defense: " << this->Defense << '\n' <<
		"Lvl: " << this->Lvl << '\n' <<
		"Exp: " << this->Exp << '/' << this->LvlExpBound << '\n' <<
		"Gold: " << this->Gold << '\n' << '\n';
}

void Human::CheckCondition()
{
	Character::CheckCondition();
	if (this->Exp > this->LvlExpBound)
		this->LevelUp();
}

void Human::Dead() 
{
	system("cls");	
	std::cout << this->Name << " died!" << '\n'
		<< "This is the end of your story... \n";
	this->IsDead = true;
}

void Human::GotExp(int _givenExpPoints)
{
	this->Exp += _givenExpPoints;
}

void Human::LevelUp()
{
	std::cout << "Level UP!" << " " << this->Lvl << "->" << (this->Lvl) + 1 << '\n';
	this->Lvl++;
	this->Attack += 2;
	this->Heal(10);
	this->MaxHP += 10; //change healing and hp maxing to distinct methods, same with MP 
	this->MP += 5;
	this->MaxMP += 5;
	
	if (this->Defense + 1 <= this->MaxDef)
		this->Defense += 1;
	else
		this->Defense = this->MaxDef;

	this->LvlExpBound = this->LevelingExpScheme.at(this->Lvl);
}

void Human::Equip(IItem* itemToEquip)
{
	std::string EqType = typeid(*itemToEquip).name();	
	if (EqType == "class IWeapon")
		this->EqAddAttack += static_cast<IWeapon*>(itemToEquip)->GetAttack();
	
	this->HandsEq[0] = itemToEquip;
}

int Human::CalculateEqAttack()
{
	return 0;
}

IItem* Human::GetHandsEquipment(short index)
{
	if (this->HandsEq[index] == NULL)
		return this->HandsEq[0];// nullptr;
	else
	{		
		return HandsEq[index];// this->HandsEq[index];
	}
}

int Human::GetEqAddAttack()
{
	return this->EqAddAttack;
}
