#pragma once
#include "IPotion.h"
class HealthPotion :
    public IPotion
{
protected: int healingValue;
public: HealthPotion(std::string _name, int _price, int _healingValue);
public: bool PotionAction(Character& CharacterRef) override;
public: void PrintItemProps() override;
public: std::unique_ptr<IItem> clone() const override;
public: HealthPotion* cpy() override;
};

