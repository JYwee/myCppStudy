#pragma once
//class Object;
class ConsoleScreen;
class Player;
class Wall;
class Bullet;

#define WallSize 10

class GameManger
{
	

private:
	GameManger();
	~GameManger();
	static GameManger* gm_Inst;

public:
	/////////////////////signleton/////////////////////
	static GameManger* GetInstance() {
		if (!gm_Inst) {
			gm_Inst = new GameManger();
		}
		return gm_Inst; 
	}

	static void DestoryInstance() {
		if (!gm_Inst) {
			delete gm_Inst;
			gm_Inst = nullptr;
		}
	}
	/////////
	bool IsRunGame();
	void SetGameState(bool gameState){
		this->gameState = gameState;
	}
	bool getGameState() {
		return gameState;
	}
	///////////////////////signleton///////////////////

	bool Init();

	ConsoleScreen* getScreen();
	Player* getPlayer();
	Wall* getWall(int count);
	Bullet* getBullet();


private:
	
	bool gameState = true;

	ConsoleScreen* mScreen;
	Player* mPlayer;
	Wall* mWall[WallSize];
	Bullet* mBullet;
	
};




