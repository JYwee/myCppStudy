#pragma once

Player NewPlayer;
Monster NewMonster;

class FightZone
{
public:
	FightZone();
	FightZone(const FightZone&) = delete;
	~FightZone();
	
	void Fight(Player& NewPlayer, Monster& NewMonster);


};

