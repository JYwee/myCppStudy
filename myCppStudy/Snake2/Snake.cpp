#include "Snake.h"
#include <conio.h>
#include "ConsoleEngineCore.h"
#include "createManager.h"

Snake::Snake()
{

}
Snake::~Snake()
{

}

void Snake::Tick(float _Time) {

    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
    {
        if (!(mDirection == int4::Right))
        {
            MovePos = int4::Left;
            SetDirection(int4::Left);
        }
        break;
    }
    case 'd':
    {
        if (!(mDirection == int4::Left))
        {
            MovePos = int4::Right;
            SetDirection(int4::Right);
        }
        break;
    }
    case 'w':
    {
        if (!(mDirection == int4::Down))
        {
            MovePos = int4::Up;
            SetDirection(int4::Up);
        }
        break;

    }
    case 's':
    {
        if (!(mDirection == int4::Up))
        {
            MovePos = int4::Down;
            SetDirection(int4::Down);
        }
        break;
    }
    case 'q':
    {
        ConsoleEngineCore::EngineOff();
        break;
    }
    default:
        break;
    }

//    AddPos(MovePos);

    int4 tmp = { 0, 0 };
    if (MovePos == tmp)
    {
        //AddPos(MovePos);
    }
    else if(createManager::GetInstance()->mApple->GetPos() == GetPos()+MovePos)
    {
        createManager::GetInstance()->mApple->rePosition;

        AddPos(MovePos);
    }

}