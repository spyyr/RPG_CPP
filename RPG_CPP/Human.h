#pragma once
#include "Character.h"
#include <map>
#include <array>
#include "IWeapon.h"
class Human : public Character
{
protected: int MP;
protected: int MaxMP;
protected: int Exp;
protected: int LvlExpBound;
protected: int EqAddAttack;
protected: unsigned int Gold;
protected: static const std::map<int, int> LevelingExpScheme;
protected: std::array<IItem*, 2> HandsEq = {};

public: Human(std::string _name, int _hp, int _mp, int _lvl, double _defense);
public: Human(std::string _name, int _hp, int _mp, int _lvl, double _defense, int _exp, int _gold);
public: void PrintCharacterProps() override;
public: void CheckCondition() override;
public: void Dead() override;
public: void GotExp(int _givenExpPoints);
public: void LevelUp();
public: void Equip(IItem* itemToEquip);
protected: int CalculateEqAttack();
public: IItem* GetHandsEquipment(short index);
public: int GetEqAddAttack();
};

