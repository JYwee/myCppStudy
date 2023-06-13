#pragma once
#include "ConsoleObject.h"

class Apple
	:public ConsoleObject
{
public:
	Apple();
	~Apple();

	void Tick(float _Time);
	void rePosition(const int4& pos);

	bool isActive = true;
};

