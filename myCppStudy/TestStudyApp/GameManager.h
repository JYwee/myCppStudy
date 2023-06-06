#pragma once
#include "SingletonType.h"
#include <list>
#include <conio.h>

class ConsoleScreen;
class Snake;
class Item;

class GameManager : public SingletonType<GameManager>
{
public:
	GameManager();
	~GameManager();

	bool Init();

	bool Run();


	const ConsoleScreen& getConsoleScreen() {
		return *mConsoleScreen;
	}

	const bool GetGameState() const{
		return mGameState;
	}

	void SetGameState(const bool state) {
		mGameState = state;
	}

	bool Input();

private:
	
	ConsoleScreen* mConsoleScreen;
	Snake* mSnake;

	//std::list<
	

	bool mGameState = true;

};

