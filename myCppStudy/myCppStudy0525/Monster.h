#pragma once
class Monster
{

public:
	Monster();
	Monster(const Monster&) = delete;
	~Monster();
	// c++에서는 함수에도 그걸 만든 프로그래머의 의도를 부여할수가 있습니다.
	//void LvUp() 
	//{
	//	Att += 10;
	//}

	void StatusRender();

	void DamagePrint(const char* const _AttName, int _Att);

	void Damage(int _Att)
	{
		Hp -= _Att;
	}

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
	char Name[40] = "Monster";
	int Att = 10;
	int Hp = 100;
};

