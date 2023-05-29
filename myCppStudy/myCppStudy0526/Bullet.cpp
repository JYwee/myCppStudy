#include "Bullet.h"
#include "Wall.h"
#include "GameManger.h"
#include "ConsoleScreen.h"

Bullet::Bullet()
	:mbulletState(false)
{
	SetEnableObj(false);
}

Bullet::~Bullet()
{
}

void Bullet::OnFire()
{
	if (IsOnFire()) {
		if (GameManger::GetInstance()->getScreen()->IsScreenOut(GetPos())
			||
			GameManger::GetInstance()->getScreen()->IsScreenOut(GetPos() + Left))
		{
			this->Destory();
			SetBulletState(false);
		}
		else {
			for (int i = 0; i < WallSize; ++i)
			{
				if (GetPos() == GameManger::GetInstance()->getWall(i)->GetPos()
					&&
					GameManger::GetInstance()->getWall(i)->IsEnableObj())
				{
					this->Destory();
					SetBulletState(false);

					GameManger::GetInstance()->getWall(i)->Destory();
					//GameManger::GetInstance()->getWall(i)->SetEnableObj(false);
				}
			}
		}
		if (mbulletState) {
			AddPos(Left);
			GameManger::GetInstance()->getScreen()->SetPixel(GetPos(), 'B');
		}
	}
	else {

	}
	
}


