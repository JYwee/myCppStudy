#include "Player.h"
//#include "Object.h"
#include "ConsoleScreen.h"
#include "GameManger.h"
#include "Wall.h"
#include "Bullet.h"
#include "int4.h"
#include <conio.h>

#define ESC 27


Player::Player()
{
}

Player::~Player()
{
}

void Player::Input(ConsoleScreen* _Sreen)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a': {
        MovePos = Left;
        break;
    }
    case 'd':
    {
        MovePos = Right;
        break;
    }
    case 'w':
    {
        MovePos = Up;
        break;
    }
    case 's':
    {
        MovePos = Down;
        break;
    }
    case ESC: 
    {
        GameManger::GetInstance()->SetGameState(false);
        break;
    }
    case ' ': 
    {
        if (GameManger::GetInstance()->getBullet()->IsOnFire()) {

        }
        else {
            FireBullet();
            GameManger::GetInstance()->getBullet()->SetBulletState(true);
        }
        break;
    }
        
    default:
        break;   
    }
    if (false == _Sreen->IsScreenOut(GetPos() + MovePos))
    {
        if (IsCanPassWay(GetPos() + MovePos)) {
            AddPos(MovePos);
        }

    }
}

bool Player::IsCanPassWay(const int4& playerPosition) const
{
    
    //bool result = (GetPos() == wallPosition);
    

    for (int i = 0; i < WallSize; ++i) {
        
        if (playerPosition == GameManger::GetInstance()->getWall(i)->GetPos()
            &&
            GameManger::GetInstance()->getWall(i)->IsEnableObj())
        {
            return false;
        }
    }
    
    return true;
}

void Player::FireBullet()
{
    GameManger::GetInstance()->getBullet()->SetPos(this->GetPos()+Left);
}
