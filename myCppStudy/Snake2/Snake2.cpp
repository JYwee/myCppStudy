// Snake.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ConsoleEngineCore.h"
#include "Snake.h"
#include "Apple.h"
#include "createManager.h"
#include <Windows.h>

createManager* createManager::mInstance = nullptr;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(0));



	createManager::GetInstance()->mSnake = ConsoleEngineCore::CreateObject<Snake>();
	createManager::GetInstance()->mSnakeBodyList.push_back(createManager::GetInstance()->mSnake);

	createManager::GetInstance()->mApple = ConsoleEngineCore::CreateObject<Apple>();
	
	//createManager::GetInstance()->mBody->SetPos({ -1,-1 });
	//createManager::GetInstance()->mBody->SetChar('A');

	std::list<ConsoleObject*> Objects = ConsoleEngineCore::GetObjects();





	// 이 함수만은 무조건 존재해야 합니다.
	ConsoleEngineCore::EngineStart(int4{ 3, 3 });




	ConsoleEngineCore::Destory();
	createManager::GetInstance()->DestoryInstance();


}
