#pragma once
#include "Character.h"
class Monster :
	public Character
{
protected: int ExpYield;
protected: int GoldYield; //could be random from range, dependent on enemy level

public: Monster(std::string _name, int _hp, int _lvl, int _attck, double _defense, int _expYield);
public: void PrintCharacterProps() override;
public: void Dead() override;
public: int GetExpYield();
};
