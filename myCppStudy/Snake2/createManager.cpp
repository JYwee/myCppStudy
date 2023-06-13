#include "createManager.h"

//createManager createManager::mManager = nullptr;
//const int4 int4::Down = { 0, 1 };

createManager::createManager()
	: mSnake(nullptr),
	 mApple(nullptr)
{
}

createManager::~createManager()
{
	/*if (mBody != nullptr)
	{
		delete mBody;
		mBody = nullptr;
	}
	if (mHead != nullptr)
	{
		delete mHead;
		mHead = nullptr;
	}*/
}
