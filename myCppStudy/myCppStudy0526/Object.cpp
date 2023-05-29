#include "Object.h"
#include "ConsoleScreen.h"
#include "GameManger.h"


Object::Object()
{
}

Object::~Object()
{
}

void Object::Destory()
{

	GameManger::GetInstance()->getScreen()->SetPixel(GetPos(), '*');
	//나중에 오브젝트 아이디 vector나 자료구조 find 만들어서 삭제 추가 해야함.
		
}


