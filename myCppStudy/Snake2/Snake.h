#pragma once
#include "ConsoleObject.h"

class Snake
	:public ConsoleObject
{
public:
	Snake();
	~Snake();

	void Tick(float _Time);
	
	int4 GetDirection() const
	{
		return mDirection;
	}

	void SetDirection(const int4& dir)
	{
		mDirection = dir;
	}

private:

	int4 mDirection = { 0, 0 };

};

