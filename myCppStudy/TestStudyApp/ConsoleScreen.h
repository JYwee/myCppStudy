#pragma once

#include "SingletonType.h"
#include "PosSturct.h"



class ConsoleScreen : public SingletonType<ConsoleScreen>
{
public:
	static const int Xline = 40;
	static const int Yline = 20;
public:
	ConsoleScreen();
	~ConsoleScreen();

	void Init(const char baseChar);
	void PrintScreen() const;
	void ClearScreen();
	bool IsInsideScreen(const Pos2D& pos) const;
	void SetPixel(Pos2D &postion, const char chPixel);

private:
	char mBaseChar = ' ';
	char mScreenArray[Yline][Xline + 1] = {};
};

