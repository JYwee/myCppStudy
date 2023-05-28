#pragma once
class Object;

class GameManger
{
private:
	GameManger();
	~GameManger();

public:
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

private:
	static GameManger* gm_Inst;

	bool gameState;

};

GameManger* GameManger::gm_Inst = nullptr;


