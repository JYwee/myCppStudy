#include "Bullet.h"
#include "Wall.h"
#include "GameManger.h"
#include "ConsoleScreen.h"

Bullet::Bullet()
	:mbulletState(false)
{
}

Bullet::~Bullet()
{
}

void Bullet::OnFire()
{
	if (IsOnFire()) {
		
		AddPos(Left);

		if (GameManger::GetInstance()->getScreen()->IsScreenOut(GetPos()))
		{
			this->Destory();
			SetBulletState(false);
		}

		for (int i = 0; i < WallSize; ++i)
		{
			if (GetPos() == GameManger::GetInstance()->getWall(i)->GetPos())
			{
				this->Destory();
				SetBulletState(false);

				GameManger::GetInstance()->getWall(i)->Destory();
			}
		}
	}
	else {

	}
	
}


