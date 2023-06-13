#pragma once
#include <iostream>
#include <list>
#include <Windows.h>
#include "PosFloat4.h"

class Object
{
public:
	Object();
	virtual ~Object();

	void SetPos(PosFloat4& position);
	PosFloat4 GetPos() const {
		return mPos;
	}

	void AddPos(const PosFloat4& position);

	void Input()

private:
	PosFloat4 mPos;
	char mRenderChar = ' ';
	bool mIsEnable = true;
};

