// testApp2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include "Object.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    std::list<Object*> AllObject;

    Player* NewPlayer = new Player();
    NewPlayer->SetPos({ 20, 10 });
    NewPlayer->SetChar('a');
    AllObject.push_back(NewPlayer);

    for (int i = 0; i < 5; i++)
    {
        Wall* NewWall = new Wall();
        NewWall->SetPos({ 5, static_cast<float>(i) });
        NewWall->SetChar('|');
        AllObject.push_back(NewWall);
    }

}

