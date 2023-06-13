#pragma once
#include <iostream>
#include "PosFloat4.h"

class ConsoleScreen
{
public :
	static const int Xline = 40;
	static const int Yline = 20;

	ConsoleScreen();
	~ConsoleScreen();

	void Init(char baseChar);

	void SetPixel(const PosFloat4& pos, const char ch);

	void Clear() ;

	bool IsScreenOut(const PosFloat4& pos);

	void Print() const;


private :
	char mBaseChar = ' ';
	char ArrScreen[Yline][Xline + 1] = {};
};

