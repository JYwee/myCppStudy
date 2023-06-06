#include "ConsoleScreen.h"
#include <iostream>

ConsoleScreen::ConsoleScreen()
{

}

ConsoleScreen::~ConsoleScreen()
{
	//this->DestoryInstance();
}

void ConsoleScreen::Init(const char baseChar)
{
	for (int y = 0; y < Yline; ++y)
	{

		for (int x = 0; x < Xline; ++x)
		{

			if (x == Xline - 1 || x==0
				|| y == 0 || y == Yline -1)
			{
				mScreenArray[y][x] = '#';
			}
			else {
				mScreenArray[y][x] = mBaseChar;
			}
		}
		mScreenArray[y][Xline] = 0;
	}
}

void ConsoleScreen::PrintScreen() const
{
	for (int i = 0; i < Yline; ++i) 
	{
		printf_s(mScreenArray[i]);
		printf_s("\n");
	}
	
}

void ConsoleScreen::ClearScreen()
{
	system("cls");
}

bool ConsoleScreen::IsInsideScreen(const Pos2D& pos) const
{
	return false;
}

void ConsoleScreen::SetPixel(Pos2D& postion, const char chPixel)
{
	mScreenArray[postion.pos_Y][postion.pos_X] = chPixel;
}
