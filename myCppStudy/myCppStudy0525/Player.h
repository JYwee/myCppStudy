#pragma once
class Player
{

public:

	Player();
	Player(const Player&) = delete;
	~Player();
	void StatusRender();
	void DamagePrint(const char* const _AttName, int _Att);
	
	void Damage(int _Att)
	{
		Hp -= _Att;
	}

	// 
	const char* GetName()
	{
		return Name;
	}

	int GetAtt()
	{
		return Att;
	}

	bool IsDeath()
	{
		return Hp <= 0;
	}


private:
	// 캡슐화
	char Name[40] = "Player";
	int Att = 10;
	int Hp = 100;
};



