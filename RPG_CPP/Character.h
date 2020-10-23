#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ScreenPrint.h"
class Character
{
protected: std::string Name;
protected: double HP;
protected: int MaxHP;
protected: double MP;
protected: int Lvl;
protected: double Attack;
protected: double Defense;
protected: double MaxDef = 20.0;
protected: double CritChance;
protected: double MaxCritChance = 80.0; //later change to 30-40% max
protected: bool IsDead;

public: Character(std::string _name, int _hp, int _lvl, int _attack, double _defense, double _critChance);

public: virtual void PrintCharacterProps() = 0;
public: void AttackSomeone(Character& enemy); //probably will not be used anymore
public: void AttackSomeone(Character& enemy, int damage);

public: virtual void CheckCondition();
public: virtual void Dead() = 0;
public: bool getIsDead();
public: std::string GetName();
public: void Heal(int heal_value);
public: int GetMaxHP();
public: virtual double GetWholeAttackValue();
public: virtual double GetWholeCritChance();
public: virtual double GetWholeDefenseValue();
protected: bool CheckIfCritical(); //should be in another class
public: double GetCritChance();
public: void SetName(std::string newName);
};

