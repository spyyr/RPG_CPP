#pragma once
#include "Character.h"
#include <map>
#include <array>
#include "Weapon.h"
#include "Armor.h"
class Human : public Character
{
protected: int MP;
protected: int MaxMP;
protected: int Exp;
protected: int LvlExpBound;
protected: double EqAddAttack;
protected: double EqAddCritChance;
protected: double EqAddDefense;
protected: unsigned int Gold;
protected: static const std::map<int, int> LevelingExpScheme;
protected: std::array<IItem*, 2> HandsEq = {};
protected: IItem* ArmorChest;
protected: std::vector<IItem*> Backpack;
protected: int MaxBackpackItems = 20;

public: Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance);
public: Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance, int _exp, int _gold);
public: void PrintCharacterProps() override;
public: void CheckCondition() override;
public: void Dead() override; //this method should be generic for human dying, not only for player's character
public: void GotExp(int _givenExpPoints);
public: void GotGold(int _givenGold);
public: void LevelUp();
public: int GetLevel();
public: void Equip(IItem* itemToEquip);
protected: int CalculateEqAttack();
public: IItem* GetHandsEquipment(short index);
public: double GetEqAddAttack();
public: double GetEqAddCritChance();
public: double GetWholeAttackValue() override;
public: double GetWholeCritChance() override;
public: double GetEqAddDefense();
public: Armor* GetArmorChest();
public: bool AddToBackpack(IItem* item);
public: bool RemoveFromBackpack(int index);
public: void PrintBackpack();
};

