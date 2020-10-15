#pragma once
#include <string>
#include <iostream>
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
protected: bool IsDead;

public: Character(std::string _name, int _hp, int _lvl, int _attack, double _defense);

public: virtual void PrintCharacterProps() = 0;
public: void AttackSomeone(Character& enemy);
public: void AttackSomeone(Character& enemy, int damage);

public: virtual void CheckCondition();
public: virtual void Dead() = 0;
public: bool getIsDead();
public: std::string GetName();
public: void Heal(int heal_value);
public: int GetMaxHP();
};

