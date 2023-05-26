#include "Player.h"
//#include "Object.h"
#include "ConsoleScreen.h"
#include "int4.h"
#include <conio.h>

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

bool Player::IsCanPassWay(int4 wallPosition)
{
    bool result = (GetPos() == wallPosition);
    if (result) {
        return false;
    }
    return true;
}
