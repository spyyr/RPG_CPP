#pragma once
#include "Character.h"
#include <map>

class Monster :
	public Character
{
protected: int ExpYield;
protected: int GoldYield; //could be random from range, dependent on enemy level
protected: static const std::map<int, int> GoldYieldLevelDependentScheme;

public: Monster(std::string _name, int _hp, int _lvl, int _attck, double _defense, double _critChance, int _expYield);
public: void PrintCharacterProps() override;
public: void Dead() override;
public: int GetExpYield();
public: int GetGoldYield();
};
