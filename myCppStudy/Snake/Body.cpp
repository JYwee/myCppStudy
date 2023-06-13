#include "Body.h"
#include "ConsoleEngineCore.h"
#include "createManager.h"

Body::Body() 
{
	
}

Body::~Body() 
{
}

void Body::Tick(float _Time)
{
	if (mIsRespawn)
	{
		//ConsoleEngineCore::CreateObject<Body>();
		rePosition();
			
	}
}

void Body::rePosition()
{
	
	int4 tmpPos;
	tmpPos.X = rand() % ConsoleEngineCore::Screen.ScreenScale().X;
	tmpPos.Y = rand() % ConsoleEngineCore::Screen.ScreenScale().Y;
	int max = ConsoleEngineCore::Screen.ScreenScale().X * ConsoleEngineCore::Screen.ScreenScale().Y;

	std::list<ConsoleObject*> obj = ConsoleEngineCore::GetObjects();
	std::list<ConsoleObject*>::iterator Start = obj.begin();
	std::list<ConsoleObject*>::iterator End = obj.end();

	bool offFlag = false;
	for (; Start != End; ++Start)
	{
		if (offFlag)
		{
			break;
		}
		
		while((*Start)->GetPos() == tmpPos)
		{
			if (obj.size() == max+1)
			{
				ConsoleEngineCore::EngineOff();
				offFlag = true;
				break;
			}
			else {
				Start = obj.begin();
			}
			tmpPos.X = rand() % ConsoleEngineCore::Screen.ScreenScale().X;
			tmpPos.Y = rand() % ConsoleEngineCore::Screen.ScreenScale().Y;
		}
	}

	SetPos(tmpPos);
	SetChar('A');
	SetIsRespawn(false);
}

