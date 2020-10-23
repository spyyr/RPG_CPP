#include "Player.h"

Player::Player(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance) :Human(_name, _hp, _mp, _lvl, _defense, _critChance){}
Player::Player(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance, int _exp, int _gold) : Human(_name, _hp, _mp, _lvl, _defense, _critChance, _exp, _gold) {}

void Player::Dead()
{
	ScreenPrint::Print(this->GetName() + " died! \nThis is the end of your story", 4, 1, true, true);
	this->IsDead = true;
}
