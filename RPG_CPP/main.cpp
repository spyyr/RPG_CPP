#include <array>
#include "Game.h"
#include "Potions/HealthPotion.h"

int main()
{
	Game* gamu = new Game();
	gamu->playerPtr->PrintCharacterProps();
	Weapon* wpn = new Weapon("Test1", 100, 1.0, 2.0);
	Weapon* wpn2 = new Weapon("Test2", 200, 2.0, 3.0);
	Armor* arm = new Armor("Arm1", 100, 1.0);
	HealthPotion* hpptn = new HealthPotion("Health Potion TEST", 11, 15);
	Monster* mnstr = gamu->GetMonsterFromVector(2);
	mnstr->AttackSomeone(*gamu->playerPtr, 10);

	gamu->playerPtr->AddToBackpack(wpn);
	gamu->playerPtr->AddToBackpack(wpn2);
	gamu->playerPtr->AddToBackpack(arm);
	gamu->playerPtr->PrintCharacterProps();
	hpptn->PotionAction(*gamu->playerPtr);
	gamu->playerPtr->PrintCharacterProps();
	//gamu->playerPtr->PrintBackpack();
	delete mnstr;
	delete hpptn;
	delete wpn, wpn2, arm;

	//gamu->playerPtr->PrintBackpack();
	
	//gamu->FightArena(*(gamu->playerPtr));

	delete gamu;

	//SetConsoleCursorPosition(ScreenPrint::GethConsole(), { 15,15 });	

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