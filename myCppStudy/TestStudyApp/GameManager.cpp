#include "GameManager.h"
#include "ConsoleScreen.h"
#include "Snake.h"
#include "Item.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	if (mSnake != nullptr) {
		delete mSnake;
		mSnake = nullptr;
	}
	if (mItem != nullptr) {
		delete mItem;
		mItem = nullptr;
	}
	//this->DestoryInstance();
}

bool GameManager::Init()
{
	ConsoleScreen::GetInstance()->Init(' ');
	
	mSnake = new Snake;
	mSnake->Init();

	mItem = new Item;

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
		if (mSnake->GetDirection() != RIGHT) {
			movePos = LEFT;
			mSnake->SetDirection(LEFT);
		}
		break;
	}
	case 'd': {
		if (mSnake->GetDirection() != LEFT) {
			movePos = RIGHT;
			mSnake->SetDirection(RIGHT);
		}
		break;
	}
	case 'w': {
		if (mSnake->GetDirection() != DOWN) {
			movePos = UP;
			mSnake->SetDirection(UP);
			
		}
		break;
	}
	case 's': {
		if (mSnake->GetDirection() != UP) {
			movePos = DOWN;
			mSnake->SetDirection(DOWN);
		}
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

void GameManager::SpawnItem()
{
	mItem->SetEnableObj(true);
	Pos2D spawnPos;
	spawnPos.pos_X = rand() % (ConsoleScreen::Xline - 2)+1;
	spawnPos.pos_Y = rand() % (ConsoleScreen::Yline - 2)+1;
	mItem->SetPosition(spawnPos);
	ConsoleScreen::GetInstance()->SetPixel(spawnPos,'A');
}



bool GameManager::Run()
{
	mConsoleScreen->GetInstance()->ClearScreen();

	if (IsPossibleMove()) {
		mSnake->MoveSnakeBody(mSnake->GetDirection());
	}
	else
	{

	}

	if (!mItem->IsEnableObj())
	{
		SpawnItem();
	}
	else {
		ConsoleScreen::GetInstance()->SetPixel(mItem->GetPosition(), 'A');
	}
	
	

	std::list<Pos2D>::iterator startIter = mSnake->mSnakeBody.begin();
	std::list<Pos2D>::iterator endIter = mSnake->mSnakeBody.end();

	for (; startIter != endIter; ++startIter)
	{
		ConsoleScreen::GetInstance()->SetPixel(*startIter, '*');
	}

	mConsoleScreen->GetInstance()->PrintScreen();

	return false;
}

bool GameManager::IsPossibleMove()
{
	Pos2D nextPos = mSnake->mSnakeBody.front() + mSnake->GetDirection();
	std::list<Pos2D>::iterator findIter = std::find(mSnake->mSnakeBody.begin(), mSnake->mSnakeBody.end(), nextPos);

	if(nextPos == mItem->GetPosition())
	{
		mItem->Destory();
		mItem->SetEnableObj(false);
		SpawnItem();
		mSnake->IsAddBody = true;

		return true;
	}
	else if (nextPos.pos_X == 0 || nextPos.pos_Y == 0 || nextPos.pos_X == ConsoleScreen::Xline-1 || nextPos.pos_Y == ConsoleScreen::Yline-1 || findIter != mSnake->mSnakeBody.end())
	{
		mGameState = false;
		return false;
	}
	
	
	
	
		return true;
	
}
