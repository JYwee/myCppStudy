#pragma once
#include "Object.h"

class ConsoleScreen;
class int4;
//class Object;

class Player : public Object
{
public:
	Player();
	~Player();

	void Input(ConsoleScreen* _Sreen);
	bool IsCanPassWay(int4 wallPostion);
};

