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
	int attackValue;
	attackValue = this->Attack;
	std::cout << this->Name << " attacks " << enemy.GetName() << " for " << attackValue << '\n';
	std::cout << "Damage Dealt to " << enemy.Name << ": " << this->Attack * (100 - enemy.Defense) * 0.01 << '\n';
	enemy.HP -= attackValue * (100-enemy.Defense)*0.01;
	enemy.CheckCondition();
}

void Character::AttackSomeone(Character& enemy, int damage)
{
	int attackValue = this->Attack + damage;
	int tmp = (MyRandom::GenerateRandomNumbers(1, 0, 100))->at(0);
	if (this->CritChance >= tmp)
	{
		attackValue *= 2;
		std::cout << "Critical attack! Damage x2" << '\n';
	}
	std::cout << this->Name << " attacks " << enemy.GetName() << " for " << attackValue << '\n';
	std::cout << "Damage Dealt to " << enemy.Name << ": " << attackValue * (100 - enemy.Defense) * 0.01 << '\n';
	enemy.HP -= attackValue * (100 - enemy.Defense) * 0.01;
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
	  