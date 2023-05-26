#pragma once

class Player;
class Monster;

class FightZone
{
public:
	FightZone();
	FightZone(const FightZone&) = delete;
	~FightZone();
	
	void Fight(Player& NewPlayer, Monster& NewMonster);


};

