#include "ConsoleScreen.h"

ConsoleScreen::ConsoleScreen() {

}

ConsoleScreen::~ConsoleScreen() {

}

void ConsoleScreen::SetPixel(const PosFloat4& pos, const char ch)
{
	
}

void ConsoleScreen::Init(char baseChar) {

}

void ConsoleScreen::SetPixel(const PosFloat4& pos, const char ch) {

}

void ConsoleScreen::Clear() {

	system("cls");

	for (int y = 0; y < Yline; ++y)
	{
		for (int x = 0; x < Xline; ++x)
		{
			ArrScreen[y][x] = mBaseChar;
		}
		ArrScreen[y][Xline] = 0;
	}

}

bool ConsoleScreen::IsScreenOut(const PosFloat4& pos)
{

}

void ConsoleScreen::Print() const {
	printf_s
}


