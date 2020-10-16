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
public: static std::vector<Monster*> monsterVector;		

public: Game();
public: ~Game();

public: void Fight(Player& player, Monster& enemy);
public: void FightArena(Player& playerRef);
private: double CalculateDamage(Character& characterRef);
public: bool CheckIfCritical(Character* characterToCheck);
};

