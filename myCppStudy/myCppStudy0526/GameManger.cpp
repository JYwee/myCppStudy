#include "GameManger.h"
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"
#include "Bullet.h"
#include <iostream>

GameManger::GameManger()
	: gameState(true),
	mScreen(nullptr),
	 mBullet(nullptr),
	mPlayer(nullptr),
	mWall{nullptr}
{
}

GameManger::~GameManger()
{
}

bool GameManger::IsRunGame()
{
	return gameState;
}

bool GameManger::Init()
{
	bool result;
		
	try
	{
		mScreen = new ConsoleScreen();
		mPlayer = new Player();
		mBullet = new Bullet();

		for (int i = 0; i < WallSize; ++i) {
			mWall[i] = new Wall();
		}

		result = true;

	}
	catch (const std::exception&)
	{
		result = false;
	}
	

	return result;
}

ConsoleScreen* GameManger::getScreen()
{
	return mScreen;
}

Player* GameManger::getPlayer()
{
	return mPlayer;
}

Wall* GameManger::getWall(int count)
{
	return mWall[count];
}

Bullet* GameManger::getBullet()
{
	return mBullet;
}


//bool GameManger::Isblock()
//{
//	return false;
//}
//
