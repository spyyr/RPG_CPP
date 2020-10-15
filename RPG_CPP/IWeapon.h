#pragma once
#include "IItem.h"
class IWeapon :
    public IItem
{
protected: double Attack;
//protected: ? SpecialPower; //special power of weapon which is used in calculating dmg dealt to enemy in attach method. So far type not found
public: IWeapon(std::string itemName, int itemPrice, double AttackValue);
public: void PrintItemProps() override;
public: double GetAttack();
};

