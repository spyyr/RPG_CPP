#pragma once
#include "Character.h"
#include "Player.h"
#include "Human.h"
#include "Monster.h"
#include "ScreenPrint.h"
#include "MyRandom.h"

class Game
{
public: Player* playerPtr;

public: Game();
public: ~Game();

public: void Fight(Player& player, Monster& enemy);
public: void FightArena(Player& playerRef);
};

