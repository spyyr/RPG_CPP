#include <array>
#include "Game.h"

int main()
{
	Game* gamu = new Game();
	gamu->playerPtr->PrintCharacterProps();
	//gamu->FightArena(*(gamu->playerPtr));
	//gamu->playerPtr->GetArmorChest()->PrintItemProps();
	Weapon* wpn = new Weapon("Test1", 100, 1.0, 2.0);
	Weapon* wpn2 = new Weapon("Test2", 200, 2.0, 3.0);
	Armor* arm = new Armor("Arm1", 100, 1.0);

	gamu->playerPtr->AddToBackpack(wpn);
	gamu->playerPtr->AddToBackpack(wpn2);
	gamu->playerPtr->AddToBackpack(arm);

	gamu->playerPtr->PrintBackpack();

	delete wpn, wpn2, arm;

	gamu->playerPtr->PrintBackpack();
	gamu->playerPtr->RemoveFromBackpack(1);
	
	gamu->FightArena(*(gamu->playerPtr));

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