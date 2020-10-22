#pragma once
#include "IItem.h"
class Armor :
    public IItem //there should be enum with specified types of armor like helmet, boots, chestplate. Then in Human::Equip method should, item should be equipped to designated place on body
{
public: Armor(std::string _name, int _price, double ArmorValue);
protected: double ArmorValue;
public: void PrintItemProps() override;
public: double GetArmorValue();
public: std::unique_ptr<IItem> clone() const override;
public: Armor* cpy() override;
};

