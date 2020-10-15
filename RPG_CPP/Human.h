#pragma once
#include "Character.h"
#include <map>
#include <array>
#include "Weapon.h"
class Human : public Character
{
protected: int MP;
protected: int MaxMP;
protected: int Exp;
protected: int LvlExpBound;
protected: double EqAddAttack;
protected: double EqAddCritChance;
protected: unsigned int Gold;
protected: static const std::map<int, int> LevelingExpScheme;
protected: std::array<IItem*, 2> HandsEq = {};

public: Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance);
public: Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, double _critChance, int _exp, int _gold);
public: void PrintCharacterProps() override;
public: void CheckCondition() override;
public: void Dead() override;
public: void GotExp(int _givenExpPoints);
public: void GotGold(int _givenGold);
public: void LevelUp();
public: int GetLevel();
public: void Equip(IItem* itemToEquip);
protected: int CalculateEqAttack();
public: IItem* GetHandsEquipment(short index);
public: int GetEqAddAttack();
public: int GetEqAddCritChance();
public: double GetWholeAttackValue() override;
};

