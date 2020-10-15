#pragma once
#include <iostream>
#include <Windows.h>
static class ScreenPrint
{
private: static int PreviousColor;
private: static HANDLE hConsole;
public: static void Print(std::string messageToPrint, short colorNumber, short newLines, bool clearScreen, bool colorChangeOnce);
public: static void ClearScreen();
public: static void ChangeTextColor(short colorNumber);
};



