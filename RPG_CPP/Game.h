#pragma once
#include "Character.h"
#include "Player.h"
#include "Human.h"
#include "Monster.h"
#include "ScreenPrint.h"
#include "MyRandom.h"
#include <vector>

class Game
{
public: Player* playerPtr;
private: static std::vector<Monster*> monsterVector;		
private: static std::vector<Weapon*> weaponVector;

public: Game();
public: ~Game();

public: void Fight(Player& player, Monster& enemy);
public: void FightArena(Player& playerRef);
private: double CalculateDamage(Character& characterRef);
public: bool CheckIfCritical(Character* characterToCheck);
public: static Monster* GetMonsterFromVector(int index);
};

