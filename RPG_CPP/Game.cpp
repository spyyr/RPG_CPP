#include "Game.h"

Game::Game()
{
	this->playerPtr = new Player("Janek", 55, 20, 2, 3, 20.0, 30, 150);
	Weapon* MyWeapon = new Weapon("Bloodthirster", 35, 4, 0.5);
	playerPtr->Equip(MyWeapon);
	playerPtr->GetHandsEquipment(0)->PrintItemProps();
	delete MyWeapon;
}

Game::~Game()
{
	//delete MyWeapon;
	delete playerPtr;
}

void Game::FightArena(Player& playerRef)
{
	int afterFightHealValue = 0;
	std::array<Monster*, 3> monsterArray{
		new Monster("Mouse", 20, 1, 2, 1.0, 1.0, 5),
		new Monster("Dog", 30, 2, 4, 2.0, 3.0, 10),
		new Monster("Wolf", 40, 3, 7, 3.0, 5.0, 15) };

	Weapon* LvlWeapon = new Weapon("Mighty Sword", 55, 7, 1.0);

	bool sw = false;
	Monster* monsterPtr = new Monster(*monsterArray[0]);
	for (Monster* item : monsterArray)
	{
		for (int i = 0; i < 5; i++)
		{
			monsterPtr = new Monster(*item);
			this->Fight(playerRef, *monsterPtr);
			if (playerRef.getIsDead() == true)
				return;
			afterFightHealValue = floor(monsterPtr->GetMaxHP() * 0.1);
			std::cout << "You will be healed for " << afterFightHealValue << '\n';
			playerRef.Heal(afterFightHealValue);
			if (playerRef.GetLevel() == 3 && sw == false)
			{
				playerRef.Equip(LvlWeapon);
			}
			playerRef.PrintCharacterProps();
		}
	}
	for (Monster* item : monsterArray)
	{
		delete item;
	}
	delete monsterPtr;
	delete LvlWeapon;
}

void Game::Fight(Player& player, Monster& enemy)
{
	HANDLE hConsole = ScreenPrint::GethConsole();
	Sleep(500);
	bool PlayerTurn = 1;
	while (player.getIsDead() == false && enemy.getIsDead() == false)
	{
		ScreenPrint::Print("Fight " + player.GetName() + " vs " + enemy.GetName(), 3, 1, 1, 1);
		SetConsoleTextAttribute(hConsole, 2);
		player.AttackSomeone(enemy, player.GetEqAddAttack());
		if (enemy.getIsDead())
		{
			system("Pause");
			break;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			enemy.PrintCharacterProps();
		}
		SetConsoleTextAttribute(hConsole, 4);
		enemy.AttackSomeone(player);

		if (player.getIsDead())
		{
			system("Pause");
			break;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			player.PrintCharacterProps();
		}
		system("PAUSE");
		system("cls");
	}
	SetConsoleTextAttribute(hConsole, 15);
	//system("cls");
	if (player.getIsDead() == false)
	{
		player.GotExp(enemy.GetExpYield());
		player.GotGold(enemy.GetGoldYield());
		player.CheckCondition();
	}
}


