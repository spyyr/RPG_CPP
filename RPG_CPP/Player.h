#pragma once
#include "Human.h"

class Player :
    public Human
{
public: Player(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance);
public: Player(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance, int _exp, int _gold);
public: void SetName(std::string newName) = delete;
public: void Dead() override;
};

