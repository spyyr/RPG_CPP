#pragma once
#include "Character.h"
#include "Human.h"
#include "Monster.h"
#include "MyRandom.h"


Character::Character(std::string _name, int _hp, int _lvl, int _attack, double _defense, double _critChance)
{
	this->Name = _name;
	this->HP = _hp;
	this->MaxHP = _hp;
	this->Lvl = _lvl;
	this->Attack = _attack;
	this->Defense = _defense;
	this->CritChance = _critChance;
	this->IsDead = false;
}

void Character::AttackSomeone(Character& enemy) //attack should be done in another method, best in class game
{		
	Character::AttackSomeone(enemy, 0);
}

void Character::AttackSomeone(Character& enemy, int damage) //every calculation from this method should be moved to methods in game class
{	
	std::cout << this->Name << " attacks " << enemy.GetName() << " for " << damage << '\n';
	std::cout << "Damage Dealt to " << enemy.Name << ": " << damage * (100 - enemy.GetWholeDefenseValue()) * 0.01 << '\n';
	enemy.HP -= damage * (100 - enemy.GetWholeDefenseValue()) * 0.01;
	enemy.CheckCondition();
}

void Character::CheckCondition()
{
	if (this->HP < 0)
		this->Dead();
}
bool Character::getIsDead()
{
	return this->IsDead;
}
std::string Character::GetName() { return this->Name; }
void Character::Heal(int heal_value)
{
	if ((this->HP + heal_value) > MaxHP)
		this->HP = MaxHP;
	else
		this->HP += heal_value;
}
int Character::GetMaxHP() { return this->MaxHP; }

double Character::GetWholeAttackValue()
{
	return this->Attack;
}

double Character::GetWholeCritChance()
{
	return this->CritChance;
}

double Character::GetWholeDefenseValue()
{
	return this->Defense;
}

bool Character::CheckIfCritical()
{
	int tmp = MyRandom::GenerateRandomNumber(0, 100);
	if (this->CritChance >= tmp)
		return true;	
	else
		return false;
}

double Character::GetCritChance()
{
	return this->CritChance;
}

void Character::SetName(std::string newName)
{
	this->Name = newName;
}
  