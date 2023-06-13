#include "Apple.h"
#include "ConsoleEngineCore.h"

Apple::Apple()
{

}
Apple::~Apple()
{
}

void Apple::Tick(float _Time) {
	if (isActive)
	{
		int4 tmp;

		tmp.X = rand() % (ConsoleEngineCore::Screen.ScreenScale().X);
		tmp.Y = rand() % (ConsoleEngineCore::Screen.ScreenScale().Y);

		rePosition(tmp);
	}
}

void Apple::rePosition(const int4& pos)
{
	SetPos(pos);
}
