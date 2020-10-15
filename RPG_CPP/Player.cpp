#include "Player.h"

Player::Player(std::string _name, int _hp, int _mp, int _lvl, double _defense) :Human(_name, _hp, _mp, _lvl, _defense){}
Player::Player(std::string _name, int _hp, int _mp, int _lvl, double _defense, int _exp, int _gold) : Human(_name, _hp, _mp, _lvl, _defense, _exp, _gold) {}