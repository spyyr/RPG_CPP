#include "HealthPotion.h"

HealthPotion::HealthPotion(std::string _name, int _price, int _healingValue):IPotion(_name, _price)
{
	this->healingValue = _healingValue;
}

bool HealthPotion::PotionAction(Character& CharacterRef)
{
	ScreenPrint::Print("Health Potion used", 6, 1, false, true);
	CharacterRef.Heal(this->healingValue);
	return true;
}

void HealthPotion::PrintItemProps()
{
	this->PrintBasicItemProps();
}

std::unique_ptr<IItem> HealthPotion::clone() const
{
	return std::make_unique<HealthPotion>(*this);
}

HealthPotion* HealthPotion::cpy()
{
	return nullptr;
}
