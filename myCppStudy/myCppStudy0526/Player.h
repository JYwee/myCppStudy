#pragma once
#include "Object.h"

class ConsoleScreen;
struct int4;
//class Object;

class Player : public Object
{
public:
	Player();
	~Player();

	void Input(ConsoleScreen* _Sreen);
	bool IsCanPassWay(const int4& playerPosition, const int4& wallPostion) const;
};

