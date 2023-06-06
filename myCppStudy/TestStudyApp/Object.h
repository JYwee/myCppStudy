#pragma once
#include "PosSturct.h"
#include "ConsoleScreen.h"

class Object
{
public:
	Object();
	~Object();

	

	Pos2D mPosition;

	void SetPosition(const Pos2D& pos) {
		mPosition = pos;
	}

	Pos2D GetPosition() const
	{
		return mPosition;
	}

	void AddPostion(const Pos2D& pos)
	{
		mPosition = mPosition + pos;
	}

	const bool IsEnableObj() const
	{
		return mIsEnable;
	}

	void SetEnableObj(bool state)
	{
		mIsEnable = state;
	}
	void Destory();

private:
	bool mIsEnable = true;
	

};

