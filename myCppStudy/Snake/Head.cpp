#include "Head.h"
#include <conio.h>
#include <list>
#include "Body.h"
#include "createManager.h"
#include "ConsoleEngineCore.h"

Head::Head() 
{
    SetChar('H');
    SetPos({ 0,0 });
}

Head::~Head() 
{
}

bool Head::IsContact(const int4& nextPos)
{
    //std::list<ConsoleObject*> obj = ConsoleEngineCore::GetObjects();
    //std::list<ConsoleObject*>::iterator Start = obj.begin();
    //std::list<ConsoleObject*>::iterator End = obj.end();

    
    if (createManager::GetInstance()->mBody->GetPos() == nextPos) 
    {
        //createManager::GetInstance()->mPartList.push_back(nextPart);
        /*createManager::GetInstance()->mBody->SetIsRespawn(true);
        createManager::GetInstance()->mBody->rePosition();*/
        return true;
    }

    //for (; Start != End; ++Start)
    //{
        //if ((*Start)->GetPos() == nextPos)
        //{
        //    Part* nextPart = ConsoleEngineCore::CreateObject<Part>();
        //    nextPart->SetPrev(this);
        //    nextPart->SetPos(GetPos());
        //    this->SetNext(nextPart);
        //    
        //    createManager::GetInstance()->mPartList.push_back(nextPart);
        //    createManager::GetInstance()->mBody->SetIsRespawn(true);
        //    //(*Start).
        //    return true;
        //}
        //else if (*Start == obj.back())
        //{

        //}

    //}
   // ConsoleEngineCore::FindObj(Body);
   // std::list<ConsoleObject*>::iterator findIter = std::find(obj.begin(), obj.end(), Body::Body());
    
    //Next.
//    if( Pos.X == 
    return false;
}

void Head::Tick(float _Time)
{
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

    int4 tmpPos = { 0, 0 };
    if (!(MovePos == tmpPos))
    {
        SetPrevPos(GetPos());


        Part* partNext = GetNext();
        //partNext->SetPrevPos(GetPrevPos());
        Part* tempNext;

        if (IsContact(GetPos() + MovePos))
        {
            //꼬리 생성하는 경우
            Part* nextPart = ConsoleEngineCore::CreateObject<Part>();
            Part* endPart = GetNext();
            Part* lastPart = nullptr;


            if (this->GetNext() == nullptr)
            {
                //this->SetPrev(nextPart);
                nextPart->SetPrev(this);
                //nextPart->SetNext(this->GetNext());
                this->SetNext(nextPart);
                nextPart->SetPos(GetPrevPos());
            }
            else {

                while (endPart != nullptr) {
                    lastPart = endPart;
                    endPart = lastPart->GetNext();
                }
                nextPart->SetPrev(lastPart);
                nextPart->SetPrevPos(lastPart->GetPos());
                lastPart->SetNext(nextPart);

                nextPart->SetPos(lastPart->GetPrevPos());
            }


            //nextPart->SetPos(GetPos());
            nextPart->SetChar('H');
            //SetNext(nextPart);

            createManager::GetInstance()->mPartList.push_back(nextPart);
            createManager::GetInstance()->mBody->SetIsRespawn(true);
            createManager::GetInstance()->mBody->rePosition();



        }

        else {
            //꼬리 생성 필요 없는 경우
        }
        AddPos(MovePos);


        while (partNext != nullptr)
        {

            if (partNext->GetPrev() == this)
            {
                //partNext->SetPrevPos(GetPos());
                partNext->SetPos(partNext->GetPrev()->GetPrevPos());

                tempNext = partNext;
                partNext = partNext->GetNext();
            }
            else
            {
                partNext->SetPos(partNext->GetPrevPos());
                partNext->SetPrevPos(partNext->GetPrev()->GetPos());
                //partNext->SetPrevPos(partNext->GetPos());

                tempNext = partNext;
                partNext = partNext->GetNext();

            }


        }
    }

    
        
}
    
