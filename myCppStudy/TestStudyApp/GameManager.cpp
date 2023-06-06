#include "GameManager.h"
#include "ConsoleScreen.h"
#include "Snake.h"


GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	if (mSnake != nullptr) {
		delete mSnake;
		mSnake = nullptr;
	}
	//this->DestoryInstance();
}

bool GameManager::Init()
{
	ConsoleScreen::GetInstance()->Init(' ');
	
	mSnake = new Snake;
	mSnake->Init();

	std::list<Pos2D>::iterator startIter = mSnake->mSnakeBody.begin();
	std::list<Pos2D>::iterator endIter = mSnake->mSnakeBody.end();

	for (; startIter != endIter; ++startIter)
	{
		ConsoleScreen::GetInstance()->SetPixel(*startIter, '*');
	}

	return true;
}

bool GameManager::Input()
{
	Pos2D movePos = mSnake->GetDirection();

	char key = (char)_getch();

	switch (key)
	{
	case 'a': {
		movePos = LEFT;
		mSnake->SetDirection(LEFT);
		break;
	}
	case 'd': {
		movePos = RIGHT;
		mSnake->SetDirection(RIGHT);
		break;
	}
	case 'w': {
		movePos = UP;
		mSnake->SetDirection(UP);
		break;

	}
	case 's': {
		movePos = DOWN;
		mSnake->SetDirection(DOWN);
		break;

	}
	case 27: {
		GameManager::GetInstance()->SetGameState(false);
		
		break;
	}
	}

	mSnake->AddPostion(movePos);
	//if(f)

	return true;
}

bool GameManager::Run()
{

	return false;
}
