#include <array>
#include "Game.h"

int main()
{
	Game* gamu = new Game();
	gamu->playerPtr->PrintCharacterProps();
	gamu->FightArena(*(gamu->playerPtr));
	delete gamu;
	//playerPtr->GetHandsEquipment(0)->PrintItemProps();

	//FightArena(*playerPtr);	

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