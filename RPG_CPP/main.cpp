#include <Windows.h>
//#include "Human.h"
#include "Player.h"
#include "Monster.h"
#include "IItem.h"
#include <array>
#include "MyRandom.h"

void FightTest(Human& player, Monster& enemy)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);		
	Sleep(500);
	bool PlayerTurn = 1;
	while (player.getIsDead() == false && enemy.getIsDead() == false)
	{		
		SetConsoleTextAttribute(hConsole, 3);
		std::cout << "Fight " << player.GetName() << " vs " << enemy.GetName() << '\n';
		SetConsoleTextAttribute(hConsole, 15);
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
	system("cls");
	if (player.getIsDead() == false)
	{
		player.GotExp(enemy.GetExpYield());
		player.GotGold(enemy.GetGoldYield());
		player.CheckCondition();
	}
}

void FightArena(Human& humanRef)
{	
	int afterFightHealValue = 0;
	std::array<Monster *, 3> monsterArray{ 
		new Monster("Mouse", 20, 1, 2, 1.0, 1.0, 5),
		new Monster("Dog", 30, 2, 4, 2.0, 3.0, 10),
		new Monster("Wolf", 40, 3, 7, 3.0, 5.0, 15) };

	IWeapon* LvlWeapon = new IWeapon("Mighty Sword", 55, 7);
	
	bool sw = false;
	Monster* monsterPtr = new Monster(*monsterArray[0]);
	for (Monster* item : monsterArray)
	{
		for (int i = 0; i < 5; i++)
		{			
			monsterPtr = new Monster(*item);
			FightTest(humanRef, *monsterPtr);
			if (humanRef.getIsDead() == true)
				return;
			afterFightHealValue = floor(monsterPtr->GetMaxHP() * 0.1);
			std::cout << "You will be healed for " << afterFightHealValue << '\n';
			humanRef.Heal(afterFightHealValue);
			if (humanRef.GetLevel() == 3 && sw == false)
			{
				humanRef.Equip(LvlWeapon);
			}				
			humanRef.PrintCharacterProps();
		}
	}
	for (Monster* item : monsterArray)
	{
		delete item;
	}
	delete monsterPtr;
}

int main()
{
	Player* playerPtr = new Player("Janek", 55, 20, 2, 3, 100.0, 30, 150);	
	IWeapon* MyWeapon = new IWeapon("Bloodthirster", 35, 4);	
	playerPtr->Equip(MyWeapon);
	playerPtr->GetHandsEquipment(0)->PrintItemProps();

	FightArena(*playerPtr);

	delete MyWeapon;
	delete playerPtr;	

	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//// you can loop k higher to see more color choices
	////LPCWSTR w = L"Title test";
	////
	////SetConsoleTitle(w);
	//for (int k = 0; k < 16; k++)
	//{
	//	// pick the colorattribute k you want
	//	SetConsoleTextAttribute(hConsole, k);		
	//	std::cout << k << " I want to be nice today!" << std::endl;
	//}
	//system("PAUSE");
}