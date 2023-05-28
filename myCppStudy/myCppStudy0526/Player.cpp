#include "Player.h"
//#include "Object.h"
#include "ConsoleScreen.h"
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
    case 'a':
        
            MovePos = Left;
        
        break;
    case 'd':
        
            MovePos = Right;
        
        break;
    case 'w':
        
            MovePos = Up;
      
        
        break;

    case 's':
        
            MovePos = Down;
        
        break;

    case ESC:
        break;

    default:
        break;   
    }
    if (false == _Sreen->IsScreenOut(GetPos() + MovePos))
    {
        if (IsCanPassWay(GetPos() + MovePos, GetPos() + MovePos)) {
            AddPos(MovePos);
        }

        //addPos();
    }
}

bool Player::IsCanPassWay(const int4& playerPosition ,const int4& wallPosition) const
{
    bool result = (GetPos() == wallPosition);
    if (result) {
        return false;
    }
    return true;
}
