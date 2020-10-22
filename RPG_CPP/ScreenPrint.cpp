#include "ScreenPrint.h"

int ScreenPrint::PreviousColor = 0;
HANDLE ScreenPrint::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void ScreenPrint::Print(std::string messageToPrint, short colorNumber, short newLines, bool clearScreen, bool colorChangeOnce)
{		
	if (clearScreen)
		ScreenPrint::ClearScreen();
	
	if (colorChangeOnce)
	{
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(hConsole, &info);
		ScreenPrint::PreviousColor = info.wAttributes;
		
	}	
	ScreenPrint::ChangeTextColor(colorNumber);
	std::cout << messageToPrint;
	for (unsigned short i = 0; i < newLines; i++)
	{
		std::cout << '\n';
	}
	
	if (colorChangeOnce)
		ScreenPrint::ChangeTextColor(ScreenPrint::PreviousColor);
 }

void ScreenPrint::ClearScreen()
{
	system("cls");
}

void ScreenPrint::ChangeTextColor(short colorNumber)
{
	SetConsoleTextAttribute(ScreenPrint::hConsole, colorNumber);
}

const HANDLE& ScreenPrint::GethConsole()
{
	return ScreenPrint::hConsole;
}
