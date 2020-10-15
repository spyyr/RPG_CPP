#pragma once
#include "Human.h"

class Player :
    public Human
{
public: Player(std::string _name, int _hp, int _mp, int _lvl, double _defense);
public: Player(std::string _name, int _hp, int _mp, int _lvl, double _defense, int _exp, int _gold);
};

