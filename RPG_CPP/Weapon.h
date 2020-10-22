#pragma once
#include "IItem.h"
class Weapon :
    public IItem
{
protected: double Attack;
protected: double AdditionalCritChance;
//protected: ? SpecialPower; //special power of weapon which is used in calculating dmg dealt to enemy in attach method. So far type not found
public: Weapon(std::string itemName, int itemPrice, double AttackValue, double _additionalCritChance);
public: void PrintItemProps() override;
public: double GetAttack();
public: double GetAdditionalCritChance();
public: std::unique_ptr<IItem> clone() const override;
public: Weapon* cpy() override;
};

