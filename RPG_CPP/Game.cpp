#include "Game.h"

std::vector<Monster*> Game::monsterVector = {  };

Game::Game()
{
	this->playerPtr = new Player("Janek", 55, 20, 2, 3, 20.0, 30, 150);
	Weapon* MyWeapon = new Weapon("Bloodthirster", 35, 4, 0.5);
	playerPtr->Equip(MyWeapon);
	playerPtr->GetHandsEquipment(0)->PrintItemProps();	
	
	Game::monsterVector.push_back(new Monster("Mouse", 20, 1, 2, 1.0, 1.0, 5));
	Game::monsterVector.push_back(new Monster("Dog", 30, 2, 4, 2.0, 3.0, 10));
	Game::monsterVector.push_back(new Monster("Wolf", 40, 3, 7, 3.0, 5.0, 15));

	delete MyWeapon;
}

Game::~Game()
{
	//delete MyWeapon;
	for (Monster* item : monsterVector)
	{
		delete item;
	}
	delete playerPtr;
}

void Game::FightArena(Player& playerRef)
{
	int afterFightHealValue = 0;

	Weapon* LvlWeapon = new Weapon("Mighty Sword", 55, 7, 1.0);

	bool sw = false;
	Monster* monsterPtr = new Monster(*monsterVector[0]);
	for (Monster* item : monsterVector)
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

	delete monsterPtr;
	delete LvlWeapon;
}

double Game::CalculateDamage(Character& characterRef)
{
	if (Game::CheckIfCritical(&characterRef))
	{
		ScreenPrint::Print("Critical hit! Damage x2", 4, 1, 0, 1);
		return characterRef.GetWholeAttackValue() * 2;
	}
	else
		return characterRef.GetWholeAttackValue();
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
		player.AttackSomeone(enemy, this->CalculateDamage(player));
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
		enemy.AttackSomeone(player, this->CalculateDamage(enemy));

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

bool Game::CheckIfCritical(Character* ptrCharacterToCheck)
{
	int randomNumber = MyRandom::GenerateRandomNumber(0, 100);
	std::string CharacterClass = typeid(*ptrCharacterToCheck).name();
	double characterCritChance = ptrCharacterToCheck->GetCritChance();

	if (CharacterClass == "class Player" || CharacterClass == "class Human")
	{
		characterCritChance += static_cast<Human*>(ptrCharacterToCheck)->GetEqAddCritChance();
	}
	if (characterCritChance <= 0)
		return false;

	if (characterCritChance >= randomNumber)
		return true;
	else
		return false;
}


