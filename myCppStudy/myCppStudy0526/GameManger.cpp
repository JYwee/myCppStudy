#include "GameManger.h"

GameManger::GameManger()
	: gameState(true)
{
}

GameManger::~GameManger()
{
}

bool GameManger::IsRunGame()
{
	return gameState;
}


//bool GameManger::Isblock()
//{
//	return false;
//}
//
